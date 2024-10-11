#include "mainwindowpulsegenerator.h"
#include "ui_mainwindowpulsegenerator.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <random>
#include <QApplication>
#include "spectragenerator.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "data_loader.h"
#include "distribution_creater.h"
#include "random_generator.h"
#include "dltpulsegenerator.h"
#include "dpulsestreamapi.h"
#include "startwindow.h"
#include "cubicspline.h"
//#define kNumberOfBins 1024

MainWindowPulseGenerator::MainWindowPulseGenerator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowPulseGenerator)
{
    ui->setupUi(this);
    ui->SpectrumParts->setProperty("class", "title");
    ui->SetupDigitizer->setProperty("class", "title");
    ui->Configuration1275->setProperty("class", "title");
    ui->PositronLifetime->setProperty("class", "title");
    ui->DetectorA->setProperty("class", "title");
    ui->DetectorB->setProperty("class", "title");
    connect(ui->actionBack,&QAction::triggered, this, &MainWindowPulseGenerator::returnToStartWindow);
}

MainWindowPulseGenerator::~MainWindowPulseGenerator()
{
    delete ui;
}


double Background, TrueCoincidence, BadCoincidence, BS_1275, Pile_UP, lambda, lower_bound1, upper_limit1, glifetime1, glifetime2, glifetime3, glifetime4, glifetime5;
double gintensity1, gintensity2, gintensity3, gintensity4, gintensity5, pulse_amplitude, pulseA_riseTime, pulseB_riseTime, pulseA_pulseWidth, pulseB_pulseWidth;
double gsigma1, gsigma2, gsigma3, gsigma4, gsigma5;
double pulseA_randomNoise, pulseB_randomNoise, pulseA_stddevOfBaselineOffsetJitter, pulseB_stddevOfBaselineOffsetJitter;
double pulseA_fixedPatternApertureJitter, pulseB_fixedPatternApertureJitter, pulseA_rndApertureJitter, pulseB_rndApertureJitter;

int NumberOfComponentes, NumberOfCountsInSpectrum, sweep,NumberOfBins;

bool pulseA_randomNoise_enabled, pulseA_baselineOffsetJitter_enabled, pulseA_timeAxisNonLinearity_enabled,pulseB_randomNoise_enabled, pulseB_baselineOffsetJitter_enabled, pulseB_timeAxisNonLinearity_enabled;
bool isPositiveSignalPolarity,Continiouse;


void MainWindowPulseGenerator::on_pushButton_clicked()
{

    const int kNumberOfBins= 1024;
    // Öffne einen Dialog, um den Benutzer einen Speicherort und Dateinamen auswählen zu lassen
    QString directory = QFileDialog::getExistingDirectory(this, tr("Verzeichnis auswählen"), "");

    if (directory.isEmpty()) {
        QMessageBox::warning(this, tr("Fehler"), tr("Kein Verzeichnis ausgewählt!"));
        return;
    }

    // Benutzer gibt den Dateinamen ein
    QString fileName = ui->LFileName->text();  // Du kannst einen QLineEdit in deinem UI verwenden, um den Dateinamen einzugeben

    if (fileName.isEmpty()) {
        QMessageBox::warning(this, tr("Fehler"), tr("Kein Dateiname eingegeben!"));
        return;
    }
    // Standard-Suffix festlegen
    QString defaultSuffix = ".drs4DataStream";

    // Prüfe, ob der Dateiname das Suffix bereits enthält
    if (!fileName.endsWith(defaultSuffix)) {
        fileName += defaultSuffix;  // Suffix hinzufügen, falls nicht vorhanden
    }

    // Kombiniere den Verzeichnispfad und den Dateinamen, um den vollständigen Pfad zu erhalten
    QString fullFilePath = QDir(directory).filePath(fileName);

    // Verwendung der Helper-Funktionen:

    Background = safeDoubleFromLineEdit(ui->LBackground, 0.03);
    TrueCoincidence = safeDoubleFromLineEdit(ui->LTrueCoincidence, 0.84);
    BadCoincidence = safeDoubleFromLineEdit(ui->LBadCoincidence, 0.12);
    BS_1275 = safeDoubleFromLineEdit(ui->L1275Backscattering, 0.001);
    Pile_UP = safeDoubleFromLineEdit(ui->LPileUps, 0.009);

    // Configuration BS-1275
    lambda = safeDoubleFromLineEdit(ui->LLambda, 0.033);
    lower_bound1 = safeDoubleFromLineEdit(ui->LLowerBound, 25.0);
    upper_limit1 = safeDoubleFromLineEdit(ui->LUpperBound, 125.0);

    // Positron lifetime!
    NumberOfComponentes = safeIntFromLineEdit(ui->LnumberOfComponents, 3);

    glifetime1 = safeDoubleFromLineEdit(ui->Llifetime1, 0.158);
    glifetime2 = safeDoubleFromLineEdit(ui->Llifetime2, 0.380);
    glifetime3 = safeDoubleFromLineEdit(ui->Llifetime3, 2.75);
    glifetime4 = safeDoubleFromLineEdit(ui->Llifetime4, 0.0);
    glifetime5 = safeDoubleFromLineEdit(ui->Llifetime5, 0.0);

    gintensity1 = safeDoubleFromLineEdit(ui->Lintensity1, 0.825);
    gintensity2 = safeDoubleFromLineEdit(ui->Lintensity2, 0.172);
    gintensity3 = safeDoubleFromLineEdit(ui->Lintensity3, 0.003);
    gintensity4 = safeDoubleFromLineEdit(ui->Lintensity4, 0.0);
    gintensity5 = safeDoubleFromLineEdit(ui->Lintensity5, 0.0);

    gsigma1 = safeDoubleFromLineEdit(ui->Lsigma1, 0.005);
    gsigma2 = safeDoubleFromLineEdit(ui->Lsigma2, 0.05);
    gsigma3 = safeDoubleFromLineEdit(ui->Lsigma3, 0.400);
    gsigma4 = safeDoubleFromLineEdit(ui->Lsigma4, 0.0);
    gsigma5 = safeDoubleFromLineEdit(ui->Lsigma5, 0.0);


    std::string stdString = fullFilePath.toStdString();
    std::string FileName = stdString;

    NumberOfCountsInSpectrum = safeIntFromLineEdit(ui->LNumberOfPulsePairs, 10000);

    //ProgressBar
    ui->progressBar->setMaximum(NumberOfCountsInSpectrum);

    //Setup Digitizer and Puls-shape
    sweep = safeIntFromLineEdit(ui->Lsweep, 200); // ns
    //kNumberOfBins = safeIntFromLineEdit(ui->lnumberOfBins, 1024); // 1024 # capacitors
    double arrival_time_spread = 0.; // arrival time spread (you can leave it as it is)
    Continiouse = ui->CheckContiniouse->isChecked();

    isPositiveSignalPolarity = ui->CheckIsPositive->isChecked(); // negative pulses
    pulse_amplitude = safeDoubleFromLineEdit(ui->LpulseAmplitude, -500.0); // mV --> scale all amplitudes into this range!
    double pulse_delay = 0.; // trigger delay (you can leave it as it is)

    // detector A:
    pulseA_riseTime = safeDoubleFromLineEdit(ui->LPulseRiseTimeA, 5.3); // ns
    pulseA_pulseWidth = safeDoubleFromLineEdit(ui->LPulseWidthA, 0.315); // ns

    bool pulseA_randomNoise_enabled = true;
    pulseA_randomNoise = safeDoubleFromLineEdit(ui->LRandomNoiseA, 0.35);// rms [mW]
    bool pulseA_baselineOffsetJitter_enabled = true;
    double pulseA_meanOfBaselineOffsetJitter = 0.; // mV
    pulseA_stddevOfBaselineOffsetJitter = safeDoubleFromLineEdit(ui->LstddevBaslineA, 5.0);// mW


    pulseA_timeAxisNonLinearity_enabled = ui->CheckNonLinearityA->isChecked();
    pulseA_fixedPatternApertureJitter = safeDoubleFromLineEdit(ui->LFixedAperatureJitterA, 0.005); //ns
    pulseA_rndApertureJitter = safeDoubleFromLineEdit(ui->LRandomAperatureJitterA, 0.0025); //ns


    // detector B:
    pulseB_riseTime = safeDoubleFromLineEdit(ui->LPulseRiseTimeB, 5.3); // ns
    pulseB_pulseWidth = safeDoubleFromLineEdit(ui->LPulseWidthB, 0.315); // ns

    bool pulseB_randomNoise_enabled = true;
    pulseA_randomNoise = safeDoubleFromLineEdit(ui->LRandomNoiseB, 0.35);// rms [mW]
    bool pulseB_baselineOffsetJitter_enabled = true;
    double pulseB_meanOfBaselineOffsetJitter = 0.; // mV
    pulseB_stddevOfBaselineOffsetJitter = safeDoubleFromLineEdit(ui->LstddevBaslineB, 5.0);// mW


    pulseB_timeAxisNonLinearity_enabled = ui->CheckNonLinearityB->isChecked();
    pulseB_fixedPatternApertureJitter = safeDoubleFromLineEdit(ui->LFixedAperatureJitterB, 0.005); //ns
    pulseB_rndApertureJitter = safeDoubleFromLineEdit(ui->LRandomAperatureJitterB, 0.0025); //ns


    using namespace DLifeTime;

    // (0) defines ...
    //Output Stream for drs4
    const std::string streamFileName = FileName;

    std::string filename1 = "C:/Users/dob54vy/Desktop/Repos/QT/lifetimeGenerator/file1.txt";
    std::string filename2 = "C:/Users/dob54vy/Desktop/Repos/QT/lifetimeGenerator/file2.txt";

    // Daten aus den Dateien laden
    std::vector<DataPoint> data1 = loadDataFromFile(filename1);
    std::vector<DataPoint> data2 = loadDataFromFile(filename2);

    // Extrahiere x- und y-Werte
    std::vector<double> x1, y1;
    for (const auto& point : data1) {
        x1.push_back(point.x);
        y1.push_back(point.y);
    }

    // Erstelle den Spline
    CubicSpline spline1(x1, y1);

    // Interpoliere Werte über einen Bereich
    double x1_start = x1.front();
    double x1_end = x1.back();
    double step1 = 0.01;

    std::vector<DataPoint> interpolatedData1 = spline1.interpolateRange(x1_start, x1_end, step1);

    std::vector<double> x2, y2;
    for (const auto& point : data2) {
        x2.push_back(point.x);
        y2.push_back(point.y);
    }

    // Erstelle den Spline
    CubicSpline spline2(x2, y2);

    // Interpoliere Werte über einen Bereich
    double x2_start = x2.front();
    double x2_end = x2.back();
    double step2 = 0.01;

    std::vector<DataPoint> interpolatedData2 = spline2.interpolateRange(x2_start, x2_end, step2);

    // Benutzerdefinierte Verteilungen erstellen
    std::map<double, double> distribution511 = createCustomDistribution(interpolatedData1);
    std::map<double, double> distribution1275 = createCustomDistribution(interpolatedData2);

    std::map<double, double> smoothedDistribution511 = smoothDistribution(distribution511, 3);  // Verteilung glätten (windowSize = 3)
    std::map<double, double> smoothedDistribution1275 = smoothDistribution(distribution1275, 3);  // Verteilung glätten (windowSize = 3)
    // Zufallsgeneratoren mit benutzerdefinierten Verteilungen initialisieren
    CustomRandomGenerator randomGen1(smoothedDistribution511);
    CustomRandomGenerator randomGen2(smoothedDistribution1275);

    // Initialisiere Zufallszahlengenerator
    std::random_device rd;
    std::mt19937 generator(rd());

    // Initialisiere exponentielle Verteilungen
    std::exponential_distribution<double> distribution1(1.0);
    std::exponential_distribution<double> distribution2(1.0);
    std::exponential_distribution<double> distribution3(1.0);
    std::exponential_distribution<double> distribution4(1.0);
    std::exponential_distribution<double> distribution5(1.0);

    double PulseLength = 0.0;
    int roundedValue = static_cast<int>(std::floor(pulseA_riseTime));

    for (int i = roundedValue; i < sweep; i++) {

        PulseLength = pulse_amplitude * exp(-0.5 * (log(i / pulseA_riseTime) * log(i / pulseA_riseTime)) / ((pulseA_pulseWidth) * (pulseA_pulseWidth)));

        if (PulseLength > 0.01 * pulse_amplitude) {

            PulseLength = i;
            break;
        }
    }


    //definition of vectors to manage events

    std::vector<std::pair<double, double> > A, B; // example code!

    // Create a random number generator
    std::random_device rd1;
    std::mt19937 gen2(rd1());

    //DLT -Setup:

    DLTSetup setup = DLTSetup_DEMO;

    setup.sweep = sweep; // ns
    //setup.numberOfCells = kNumberOfBins; // 1024 # capacitors
    setup.ATS = arrival_time_spread; // arrival time spread (you can leave it as it is)

    DLTPulse pulse = DLTPulse2_DEMO;

    pulse.amplitude = pulse_amplitude; // mV --> scale all amplitudes into this range!
    pulse.isPositiveSignalPolarity = isPositiveSignalPolarity; // negative pulses
    pulse.delay = pulse_delay; // trigger delay (you can leave it as it is)

    // detector A:

    pulse.pulseA.riseTime = pulseA_riseTime;   // ns
    pulse.pulseA.pulseWidth = pulseA_pulseWidth; // ns
    pulse.pulseA.randomNoiseInfoV.enabled = pulseA_randomNoise_enabled;
    pulse.pulseA.randomNoiseInfoV.rndNoise = pulseA_randomNoise;  // rms [mW]

    pulse.pulseA.baselineOffsetJitterInfoV.enabled = pulseA_baselineOffsetJitter_enabled;
    pulse.pulseA.baselineOffsetJitterInfoV.meanOfBaselineOffsetJitter = pulseA_meanOfBaselineOffsetJitter; // mV
    pulse.pulseA.baselineOffsetJitterInfoV.stddevOfBaselineOffsetJitter = pulseA_stddevOfBaselineOffsetJitter; // mV

    pulse.pulseA.timeAxisNonLinearityInfoT.enabled = pulseA_timeAxisNonLinearity_enabled;
    pulse.pulseA.timeAxisNonLinearityInfoT.fixedPatternApertureJitter = pulseA_fixedPatternApertureJitter;  // ns
    pulse.pulseA.timeAxisNonLinearityInfoT.rndApertureJitter = pulseA_rndApertureJitter; // ns

    // detector B:

    pulse.pulseB.riseTime = pulseB_riseTime;   // ns
    pulse.pulseB.pulseWidth = pulseB_pulseWidth; // ns
    pulse.pulseB.randomNoiseInfoV.enabled = pulseB_randomNoise_enabled;
    pulse.pulseB.randomNoiseInfoV.rndNoise = pulseB_randomNoise;  // rms [mW]

    pulse.pulseB.baselineOffsetJitterInfoV.enabled = pulseB_baselineOffsetJitter_enabled;
    pulse.pulseB.baselineOffsetJitterInfoV.meanOfBaselineOffsetJitter = pulseB_meanOfBaselineOffsetJitter;   // mV
    pulse.pulseB.baselineOffsetJitterInfoV.stddevOfBaselineOffsetJitter = pulseB_stddevOfBaselineOffsetJitter; // mV

    pulse.pulseB.timeAxisNonLinearityInfoT.enabled = pulseB_timeAxisNonLinearity_enabled;
    pulse.pulseB.timeAxisNonLinearityInfoT.fixedPatternApertureJitter = pulseB_fixedPatternApertureJitter;  // ns
    pulse.pulseB.timeAxisNonLinearityInfoT.rndApertureJitter = pulseB_rndApertureJitter;          // ns

    // unused for this purpose but it needs to be defined ...

    DLTPHS phs = DLTPHS2_DEMO;            // not used!
    DLTSimulationInput simulationInput = DLTSimulationInput_DEMO; // not used!

    phs.useGaussianModels = true;
    // (A) generate pulsegenerator instance ...

    CallbackClass callback; // check for errors ...

    DLTPulseGenerator* pulseGenerator = new DLTPulseGenerator(simulationInput, phs, setup, pulse, &callback);

    if (callback.hasError()) {
        DDELETE_SAFETY(pulseGenerator);
        QMessageBox::information(this, "Error", "pulse generator cannot be initialized successfully!");

        return;
    }

    // (B) create pulse stream file ...

    if (!DPulseStreamManager::sharedInstance()->start(streamFileName, setup.sweep, double(kNumberOfBins) / setup.sweep, kNumberOfBins)) { // DRS4 compatible ...
        QMessageBox::information(this, "File problem!", "file cannot be created!");

        return;
    }else {
        std::cout << "file creation successful: " << streamFileName << std::endl;
    }

    const int sizeOfWave = sizeof(float) * kNumberOfBins;



    if(Continiouse == false){
        for (int i = 0; i < NumberOfCountsInSpectrum; i++) {

            DLTPulseF pulseA, pulseB;
            double r = ((double)rand() / RAND_MAX);
            A.clear();
            B.clear();

            double amplitude511 = randomGen1.generate();
            double amplitude1275 = randomGen2.generate();


            double PALS = DiscretPositronAnhillationLifetime(NumberOfComponentes, glifetime1, glifetime2, glifetime3, glifetime4, glifetime5,
                                                      gintensity1, gintensity2, gintensity3, gintensity4, gintensity5,
                                                      distribution1, distribution2, distribution3, distribution4, distribution5,
                                                      generator);

            double PMT_1275 = generatePMTuncertaincy(0.55, amplitude1275);
            double PMT_511 = generatePMTuncertaincy(0.55, amplitude511);

            double overall_intensity = Background + TrueCoincidence + BadCoincidence + BS_1275 + Pile_UP;
            double tolerance = 1e-9; // set a small tolerance value
            if (std::abs(overall_intensity - 1.0) > tolerance) {
                QMessageBox::information(this, "Error", "All Spectrum components must sum up to 1.0!");

                return;
            }

            if (r <= Background) {

                double fifthy_fithy = ((double)rand() / RAND_MAX);

                std::uniform_real_distribution<> distrib(-8.0, 42.0);
                double Background_number = distrib(generator);
                if (fifthy_fithy <= 0.5) {
                    std::pair<double, double> a = { 10. + Background_number  , -amplitude511 };
                    std::pair<double, double> b = { 10. ,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
                else
                {
                    std::pair<double, double> b = { 10. + Background_number  , -amplitude511 };
                    std::pair<double, double> a = { 10. ,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
            }
            else if (r <= (Background + TrueCoincidence)) {

                double fifthy_fithy = ((double)rand() / RAND_MAX);

                if (fifthy_fithy <= 0.5) {

                    std::pair<double, double> a = { 5. + PALS + PMT_511, -amplitude511 };
                    std::pair<double, double> b = { 5. + PMT_1275,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
                else {
                    std::pair<double, double> b = { 5. + PALS + PMT_511, -amplitude511 };
                    std::pair<double, double> a = { 5. + PMT_1275,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
            }
            else if (r <= (Background + TrueCoincidence + BadCoincidence)) {

                double fifthy_fithy = ((double)rand() / RAND_MAX);



                if (fifthy_fithy <= 0.5) {

                    std::pair<double, double> a = { 5. + PALS + PMT_511, -amplitude511 };
                    std::pair<double, double> b = { 5. + PMT_1275 ,-amplitude1275 };

                    double amplitude511_2 = randomGen1.generate();
                    double PMT_511_2 = generatePMTuncertaincy(0.55, amplitude511_2);

                    std::pair<double, double> c = { 5. + PALS + PMT_511_2,-amplitude511_2 };

                    A.push_back(a);
                    B.push_back(b);
                    B.push_back(c);
                }
                else
                {
                    std::pair<double, double> b = { 5. + PALS + PMT_511, -amplitude511 };
                    std::pair<double, double> a = { 5. + PMT_1275 ,-amplitude1275 };

                    double amplitude511_2 = randomGen1.generate();
                    double PMT_511_2 = generatePMTuncertaincy(0.55, amplitude511_2);

                    std::pair<double, double> c = { 5. + PALS + PMT_511_2,-amplitude511_2 };

                    A.push_back(a);
                    B.push_back(b);
                    A.push_back(c);
                }

            }
            //Generierung von Backscatter 1275keV with different distribution PHS to mimic the higher probability of low Stopp window apperance
            else if (r <= (Background + TrueCoincidence + BadCoincidence + BS_1275)) {

                double T0_shift = 0.5;//ns
                double BS_1275_sigma = 0.64;//ns
                static std::normal_distribution<double> distribution_BS_1275(0.0, BS_1275_sigma);

                std::exponential_distribution<> d(lambda);

                double random_number;


                // Generiere eine exponentiell verteilte Zufallszahl
                random_number = d(generator);
                if (random_number >= (upper_limit1 - lower_bound1)) {
                    while (random_number >= (upper_limit1 - lower_bound1)) {
                        random_number = d(generator);
                    }

                }
                // Verschiebe die Zufallszahl, so dass der Bereich bei `lower_bound` beginnt
                random_number += lower_bound1;

                double fifthy_fithy = ((double)rand() / RAND_MAX);

                if (fifthy_fithy <= 0.5) {
                    std::pair<double, double> a = { 5. + T0_shift + PMT_511 , -random_number };
                    std::pair<double, double> b = { 5. + PMT_1275 ,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
                else {
                    std::pair<double, double> b = { 5. + T0_shift + PMT_511 , -random_number };
                    std::pair<double, double> a = { 5. + PMT_1275 ,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
            }
            else if (r <= (Background + TrueCoincidence + BadCoincidence + BS_1275 + Pile_UP)) {
                double fifthy_fithy = ((double)rand() / RAND_MAX);
                double fifthy_fithy1 = ((double)rand() / RAND_MAX);

                double PALS2 = DiscretPositronAnhillationLifetime(NumberOfComponentes, glifetime1, glifetime2, glifetime3, glifetime4, glifetime5,
                                                           gintensity1, gintensity2, gintensity3, gintensity4, gintensity5,
                                                           distribution1, distribution2, distribution3, distribution4, distribution5,
                                                           generator);

                double amplitude511_2 = randomGen1.generate();
                double amplitude1275_2 = randomGen2.generate();
                double PMT_1275_2 = generatePMTuncertaincy(0.55, amplitude1275_2);
                double PMT_511_2 = generatePMTuncertaincy(0.55, amplitude511_2);


                std::uniform_real_distribution<> distribPileUp(-PulseLength, PulseLength);
                double PileUp_shift = distribPileUp(generator);

                if (fifthy_fithy <= 0.5) {

                    std::pair<double, double> a = { 2 * PulseLength + PALS + PMT_511, -amplitude511 };
                    std::pair<double, double> b = { 2 * PulseLength + PMT_1275,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);

                    if (fifthy_fithy1 <= 0.5) {
                        std::pair<double, double> c = { 2 * PulseLength + PALS2 + PMT_511_2 + PileUp_shift, -amplitude511_2 };
                        A.push_back(c);
                    }
                    else {
                        std::pair<double, double> c = { 2 * PulseLength + PALS2 + PMT_511_2 + PileUp_shift, -amplitude511_2 };
                        B.push_back(c);
                    }

                }
                else {
                    std::pair<double, double> a = { 2 * PulseLength + PMT_1275,-amplitude1275 };
                    std::pair<double, double> b = { 2 * PulseLength + PALS + PMT_511, -amplitude511 };

                    A.push_back(a);
                    B.push_back(b);

                    if (fifthy_fithy1 <= 0.5) {
                        std::pair<double, double> c = { 2 * PulseLength + PMT_1275_2 + PileUp_shift,-amplitude1275_2 };
                        A.push_back(c);
                    }
                    else {
                        std::pair<double, double> c = { 2 * PulseLength + PMT_1275_2 + PileUp_shift,-amplitude1275_2 };
                        B.push_back(c);
                    }
                }
            }



            if (pulseGenerator->emitPulsesByExternalInput(&pulseA, &pulseB, A, B)) {
                float tChannel0[kNumberOfBins] = { 0 };
                float tChannel1[kNumberOfBins] = { 0 };

                float waveChannel0[kNumberOfBins] = { 0 };
                float waveChannel1[kNumberOfBins] = { 0 };

                std::fill(tChannel0, tChannel0 + kNumberOfBins, 0.);
                std::fill(tChannel1, tChannel1 + kNumberOfBins, 0.);

                std::fill(waveChannel0, waveChannel0 + kNumberOfBins, 0.);
                std::fill(waveChannel1, waveChannel1 + kNumberOfBins, 0.);

                for (int i = 0; i < kNumberOfBins; ++i) {
                    tChannel0[i] = pulseA.at(i).x();
                    waveChannel0[i] = pulseA.at(i).y();

                    tChannel1[i] = pulseB.at(i).x();
                    waveChannel1[i] = pulseB.at(i).y();
                }
                // append pulses to stream ...
                DPulseStreamManager::sharedInstance()->writePulsePair(tChannel0, waveChannel0, tChannel1, waveChannel1, sizeOfWave);


            }


            // Aktualisiere die ProgressBar
            ui->progressBar->setValue(i + 1);  // Setzt den Fortschritt (i + 1)

            // Lässt die GUI aktualisieren, um das Einfrieren der GUI zu verhindern
            QCoreApplication::processEvents();


        }
    }else{
        for (int i = 0; i < NumberOfCountsInSpectrum; i++) {

            DLTPulseF pulseA, pulseB;
            double r = ((double)rand() / RAND_MAX);
            A.clear();
            B.clear();

            double amplitude511 = randomGen1.generate();
            double amplitude1275 = randomGen2.generate();


            double PALS = ContiniousPositronAnhillationLifetime(NumberOfComponentes, glifetime1, gsigma1, glifetime2,gsigma2, glifetime3, gsigma3, glifetime4,gsigma4, glifetime5,gsigma5,
                                                                 gintensity1, gintensity2, gintensity3, gintensity4, gintensity5,
                                                                 distribution1, distribution2, distribution3, distribution4, distribution5,
                                                                 generator);

            double PMT_1275 = generatePMTuncertaincy(0.55, amplitude1275);
            double PMT_511 = generatePMTuncertaincy(0.55, amplitude511);

            double overall_intensity = Background + TrueCoincidence + BadCoincidence + BS_1275 + Pile_UP;
            double tolerance = 1e-9; // set a small tolerance value
            if (std::abs(overall_intensity - 1.0) > tolerance) {
                QMessageBox::information(this, "Error", "All Spectrum components must sum up to 1.0!");
                return;
            }

            if (r <= Background) {

                double fifthy_fithy = ((double)rand() / RAND_MAX);

                std::uniform_real_distribution<> distrib(-8.0, 42.0);
                double Background_number = distrib(generator);
                if (fifthy_fithy <= 0.5) {
                    std::pair<double, double> a = { 10. + Background_number  , -amplitude511 };
                    std::pair<double, double> b = { 10. ,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
                else
                {
                    std::pair<double, double> b = { 10. + Background_number  , -amplitude511 };
                    std::pair<double, double> a = { 10. ,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
            }
            else if (r <= (Background + TrueCoincidence)) {

                double fifthy_fithy = ((double)rand() / RAND_MAX);

                if (fifthy_fithy <= 0.5) {

                    std::pair<double, double> a = { 5. + PALS + PMT_511, -amplitude511 };
                    std::pair<double, double> b = { 5. + PMT_1275,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
                else {
                    std::pair<double, double> b = { 5. + PALS + PMT_511, -amplitude511 };
                    std::pair<double, double> a = { 5. + PMT_1275,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
            }
            else if (r <= (Background + TrueCoincidence + BadCoincidence)) {

                double fifthy_fithy = ((double)rand() / RAND_MAX);



                if (fifthy_fithy <= 0.5) {

                    std::pair<double, double> a = { 5. + PALS + PMT_511, -amplitude511 };
                    std::pair<double, double> b = { 5. + PMT_1275 ,-amplitude1275 };

                    double amplitude511_2 = randomGen1.generate();
                    double PMT_511_2 = generatePMTuncertaincy(0.55, amplitude511_2);

                    std::pair<double, double> c = { 5. + PALS + PMT_511_2,-amplitude511_2 };

                    A.push_back(a);
                    B.push_back(b);
                    B.push_back(c);
                }
                else
                {
                    std::pair<double, double> b = { 5. + PALS + PMT_511, -amplitude511 };
                    std::pair<double, double> a = { 5. + PMT_1275 ,-amplitude1275 };

                    double amplitude511_2 = randomGen1.generate();
                    double PMT_511_2 = generatePMTuncertaincy(0.55, amplitude511_2);

                    std::pair<double, double> c = { 5. + PALS + PMT_511_2,-amplitude511_2 };

                    A.push_back(a);
                    B.push_back(b);
                    A.push_back(c);
                }

            }
            //Generierung von Backscatter 1275keV with different distribution PHS to mimic the higher probability of low Stopp window apperance
            else if (r <= (Background + TrueCoincidence + BadCoincidence + BS_1275)) {

                double T0_shift = 0.5;//ns
                double BS_1275_sigma = 0.64;//ns
                static std::normal_distribution<double> distribution_BS_1275(0.0, BS_1275_sigma);

                std::exponential_distribution<> d(lambda);

                double random_number;


                // Generiere eine exponentiell verteilte Zufallszahl
                random_number = d(generator);
                if (random_number >= (upper_limit1 - lower_bound1)) {
                    while (random_number >= (upper_limit1 - lower_bound1)) {
                        random_number = d(generator);
                    }

                }
                // Verschiebe die Zufallszahl, so dass der Bereich bei `lower_bound` beginnt
                random_number += lower_bound1;


                double fifthy_fithy = ((double)rand() / RAND_MAX);

                if (fifthy_fithy <= 0.5) {
                    std::pair<double, double> a = { 5. + T0_shift + PMT_511 , -random_number };
                    std::pair<double, double> b = { 5. + PMT_1275 ,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
                else {
                    std::pair<double, double> b = { 5. + T0_shift + PMT_511 , -random_number };
                    std::pair<double, double> a = { 5. + PMT_1275 ,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);
                }
            }
            else if (r <= (Background + TrueCoincidence + BadCoincidence + BS_1275 + Pile_UP)) {
                double fifthy_fithy = ((double)rand() / RAND_MAX);
                double fifthy_fithy1 = ((double)rand() / RAND_MAX);

                double PALS2 = ContiniousPositronAnhillationLifetime(NumberOfComponentes, glifetime1, gsigma1, glifetime2,gsigma2, glifetime3, gsigma3, glifetime4,gsigma4, glifetime5,gsigma5,
                                                                  gintensity1, gintensity2, gintensity3, gintensity4, gintensity5,
                                                                  distribution1, distribution2, distribution3, distribution4, distribution5,
                                                                  generator);

                double amplitude511_2 = randomGen1.generate();
                double amplitude1275_2 = randomGen2.generate();
                double PMT_1275_2 = generatePMTuncertaincy(0.55, amplitude1275_2);
                double PMT_511_2 = generatePMTuncertaincy(0.55, amplitude511_2);


                std::uniform_real_distribution<> distribPileUp(-PulseLength, PulseLength);
                double PileUp_shift = distribPileUp(generator);

                if (fifthy_fithy <= 0.5) {

                    std::pair<double, double> a = { 2 * PulseLength + PALS + PMT_511, -amplitude511 };
                    std::pair<double, double> b = { 2 * PulseLength + PMT_1275,-amplitude1275 };

                    A.push_back(a);
                    B.push_back(b);

                    if (fifthy_fithy1 <= 0.5) {
                        std::pair<double, double> c = { 2 * PulseLength + PALS2 + PMT_511_2 + PileUp_shift, -amplitude511_2 };
                        A.push_back(c);
                    }
                    else {
                        std::pair<double, double> c = { 2 * PulseLength + PALS2 + PMT_511_2 + PileUp_shift, -amplitude511_2 };
                        B.push_back(c);
                    }

                }
                else {
                    std::pair<double, double> a = { 2 * PulseLength + PMT_1275,-amplitude1275 };
                    std::pair<double, double> b = { 2 * PulseLength + PALS + PMT_511, -amplitude511 };

                    A.push_back(a);
                    B.push_back(b);

                    if (fifthy_fithy1 <= 0.5) {
                        std::pair<double, double> c = { 2 * PulseLength + PMT_1275_2 + PileUp_shift,-amplitude1275_2 };
                        A.push_back(c);
                    }
                    else {
                        std::pair<double, double> c = { 2 * PulseLength + PMT_1275_2 + PileUp_shift,-amplitude1275_2 };
                        B.push_back(c);
                    }
                }
            }



            if (pulseGenerator->emitPulsesByExternalInput(&pulseA, &pulseB, A, B)) {
                float tChannel0[kNumberOfBins] = { 0 };
                float tChannel1[kNumberOfBins] = { 0 };

                float waveChannel0[kNumberOfBins] = { 0 };
                float waveChannel1[kNumberOfBins] = { 0 };

                std::fill(tChannel0, tChannel0 + kNumberOfBins, 0.);
                std::fill(tChannel1, tChannel1 + kNumberOfBins, 0.);

                std::fill(waveChannel0, waveChannel0 + kNumberOfBins, 0.);
                std::fill(waveChannel1, waveChannel1 + kNumberOfBins, 0.);

                for (int i = 0; i < kNumberOfBins; ++i) {
                    tChannel0[i] = pulseA.at(i).x();
                    waveChannel0[i] = pulseA.at(i).y();

                    tChannel1[i] = pulseB.at(i).x();
                    waveChannel1[i] = pulseB.at(i).y();
                }
                // append pulses to stream ...
                DPulseStreamManager::sharedInstance()->writePulsePair(tChannel0, waveChannel0, tChannel1, waveChannel1, sizeOfWave);


            }


            // Aktualisiere die ProgressBar
            ui->progressBar->setValue(i + 1);  // Setzt den Fortschritt (i + 1)

            // Lässt die GUI aktualisieren, um das Einfrieren der GUI zu verhindern
            QCoreApplication::processEvents();


        }
    }
    // Sobald der Prozess abgeschlossen ist, setze die ProgressBar auf 100%
    ui->progressBar->setValue(NumberOfCountsInSpectrum);

    // (D) close file stream ...
    DPulseStreamManager::sharedInstance()->stopAndSave();
    // Prozess abgeschlossen, MessageBox anzeigen
    QMessageBox::information(this, "Prozess abgeschlossen", "Der Datenstream wurde erfolgreich generiert.");

    DDELETE_SAFETY(pulseGenerator);


}

// Implementierung der Funktion safeDoubleFromLineEdit
double MainWindowPulseGenerator::safeDoubleFromLineEdit(QLineEdit *lineEdit, double defaultValue) {
    bool ok = false;
    double value = lineEdit->text().toDouble(&ok);  // &ok gibt an, ob die Konvertierung erfolgreich war
    if (!ok) {
        return defaultValue;  // Falls ungültig, Standardwert verwenden
    }
    return value;
}

// Implementierung der Funktion safeIntFromLineEdit
int MainWindowPulseGenerator::safeIntFromLineEdit(QLineEdit *lineEdit, int defaultValue) {
    bool ok = false;
    int value = lineEdit->text().toInt(&ok);  // &ok gibt an, ob die Konvertierung erfolgreich war
    if (!ok) {
        return defaultValue;  // Falls ungültig, Standardwert verwenden
    }
    return value;
}

void MainWindowPulseGenerator::returnToStartWindow() {
    // Zeige das Startfenster und schließe das aktuelle Fenster
    StartWindow *startWindow = new StartWindow();  // Erstelle das Startfenster
    startWindow->show();  // Zeige das Startfenster an
    this->close();        // Schließe das aktuelle Fenster
}
