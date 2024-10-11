#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>  // Für Fehlermeldungen
#include "startwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_window1(nullptr)  // Initialisiere den Zeiger auf das zweite Fenster mit nullptr

{
    ui->setupUi(this);
    connect(ui->actionStart_Window,&QAction::triggered, this, &MainWindow::returnToStartWindow2);

}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_window1) {
        delete m_window1;  // Freigeben, wenn das zweite Fenster existiert
    }
}

int NumberOfComponents, NumberOfCounts;
double lifetime1, lifetime2 ,lifetime3 ,lifetime4 ,lifetime5;
double intensity1, intensity2, intensity3, intensity4, intensity5;

double fwhm1, fwhm1_intensity, fwhm2, fwhm2_intensity, fwhm2_t0_shift;
double sigma1, sigma2, sigma3, sigma4, sigma5;

double background_percentage;

bool checkbox_state;
int spectrumrange;
double binning;
void MainWindow::on_pushButton_clicked()
{

    binning = ui->LBinning->text().toDouble(); // ps
    spectrumrange = ui->LSpectrumRange->text().toInt(); // ns
    NumberOfComponents = ui->LNumberOfComponents->text().toInt();
    NumberOfCounts = ui->LNumberOfCounts->text().toInt();

    lifetime1 = ui->LLifetime1->text().toDouble();
    lifetime2 = ui->LLifetime2->text().toDouble();
    lifetime3 = ui->LLifetime3->text().toDouble();
    lifetime4 = ui->LLifetime4->text().toDouble();
    lifetime5 = ui->LLifetime5->text().toDouble();

    intensity1 = ui->LIntensity1->text().toDouble();
    intensity2 = ui->LIntensity2->text().toDouble();
    intensity3 = ui->LIntensity3->text().toDouble();
    intensity4 = ui->LIntensity4->text().toDouble();
    intensity5 = ui->LIntensity5->text().toDouble();

    fwhm1 = ui->LFWHM1->text().toDouble();
    fwhm2 = ui->LFWHM2->text().toDouble();
    fwhm1_intensity = ui->LFWHM_Intensity1->text().toDouble();
    fwhm2_intensity = ui->LFWHM_Intensity2->text().toDouble();
    fwhm2_t0_shift = ui->Lt0_shift->text().toDouble();

    sigma1 = ui->LSigma1->text().toDouble();
    sigma2 = ui->LSigma2->text().toDouble();
    sigma3 = ui->LSigma3->text().toDouble();
    sigma4 = ui->LSigma4->text().toDouble();
    sigma5 = ui->LSigma5->text().toDouble();

    background_percentage = ui->LBackground->text().toDouble();

    checkbox_state = ui->ContiniousLifetime->isChecked();

    // Definiere die Grenzwerte für die Intensitäten (z.B. zwischen 0 und 1)
    double intensityMin = 0.0;
    double intensityMax = 1.0;

    // Überprüfe, ob die Intensitätswerte innerhalb der Grenzwerte liegen
    if (intensity1 < intensityMin || intensity1 > intensityMax ||
        intensity2 < intensityMin || intensity2 > intensityMax ||
        intensity3 < intensityMin || intensity3 > intensityMax ||
        intensity4 < intensityMin || intensity4 > intensityMax ||
        intensity5 < intensityMin || intensity5 > intensityMax ||
        fwhm1_intensity < intensityMin || fwhm1_intensity > intensityMax ||
        fwhm2_intensity < intensityMin || fwhm2_intensity > intensityMax)
    {
        // Zeige eine Fehlermeldung, wenn einer der Werte außerhalb der Grenzwerte liegt
        QMessageBox::warning(this, "Invalid input", "The intensity values must be between 0 and 1.");
        return;  // Beende die Funktion, um keine falschen Werte weiterzuverarbeiten
    }

    if(NumberOfComponents == 1){
        if (intensity1!=intensityMax){
            QMessageBox::warning(this, "Invalid input", "The intensity1 values must be 1.");
            return;
        }

    }else if(NumberOfComponents == 2){
        if((intensity1 +intensity2)!= intensityMax){
            QMessageBox::warning(this, "Invalid input", "The intensity1 and intensity2 values must sum up to 1.");
            return;
        }
    }else if(NumberOfComponents == 3){
        if((intensity1 +intensity2+intensity3)!= intensityMax){
            QMessageBox::warning(this, "Invalid input", "The intensity1, intensity2 and intensity3 values must sum up to 1.");
            return;
        }
    }else if(NumberOfComponents == 4){
        if((intensity1 +intensity2+intensity3+intensity4)!= intensityMax){
            QMessageBox::warning(this, "Invalid input", "The intensity1, intensity2, intensity3 and intensity4 values must sum up to 1.");
            return;
        }
    }else{
        QMessageBox::warning(this, "Invalid input", "The intensity1, intensity2, intensity3, intensity4 and intensity5 values must sum up to 1.");
        return;
    }

    std::vector<double> doubleValues ={lifetime1,lifetime2,lifetime3, lifetime4,lifetime5,intensity1, intensity2, intensity3, intensity4, intensity5};
    std::vector<double> IRFValues ={fwhm1, fwhm1_intensity, fwhm2,fwhm2_intensity,  fwhm2_t0_shift};
    std::vector<double> doubleSigmas ={sigma1, sigma2, sigma3, sigma4, sigma5};

    // Wenn das zweite Fenster noch nicht existiert, erstelle es

    if (!m_window1) {
        // Erstelle das window1-Fenster als reguläres Fenster
        m_window1 = new window1(this, doubleValues, NumberOfComponents, NumberOfCounts, IRFValues, background_percentage, doubleSigmas, checkbox_state, spectrumrange, binning);
        m_window1->setAttribute(Qt::WA_DeleteOnClose);  // Optional: Fenster wird gelöscht, wenn es geschlossen wird
        m_window1->show();  // Zeige das Fenster
    } else {
        m_window1->updateValues(doubleValues, NumberOfComponents, NumberOfCounts, IRFValues, background_percentage, doubleSigmas, checkbox_state, spectrumrange, binning);
    }



}

void MainWindow::returnToStartWindow2() {
    // Zeige das Startfenster und schließe das aktuelle Fenster
    StartWindow *startWindow = new StartWindow();  // Erstelle das Startfenster
    startWindow->show();  // Zeige das Startfenster an
    this->close();        // Schließe das aktuelle Fenster
}


