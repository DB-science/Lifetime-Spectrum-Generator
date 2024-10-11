#include "globals.h"

//configuration of Spectrum Components
double Background = 0.0331;
double TrueCoincidence = 0.8394;
double BadCoincidence = 0.119;
double BS_1275 = 0.0014;
double Pile_UP = 0.0071;

// Configuration BS-1275
double lambda = 1.0 / 30.0;
double lower_bound1 = 25.0;
double upper_limit1 = 125.0;


//positron lifetime!
int NumberOfComponentes = 3; //the number of Components the Positron lifetime Spectrum should have. 1 to 5 Components availible, Intensity must add to 1.
double lifetime1 = 0.158; double intensity1 = 0.825;
double lifetime2 = 0.380; double intensity2 = 0.172;
double lifetime3 = 2.750; double intensity3 = 0.003;
double lifetime4 = 0.0; double intensity4 = 0.00;
double lifetime5 = 0.0; double intensity5 = 0.00;


std::string FileName = "C:/Users/domin/Desktop/Projekt-better-Pulsgenerator/Easy_Modul2/Test_" + std::to_string(lifetime1) + "_" + std::to_string(intensity1) + "_" + std::to_string(lifetime2) + "_" + std::to_string(intensity2) + "_" + std::to_string(lifetime3) + "_" + std::to_string(intensity3) + "_" + std::to_string(lifetime4) + "_" + std::to_string(intensity4) + "_" + std::to_string(lifetime5) + "_" + std::to_string(intensity5) + "_TrueCoincidence_" + std::to_string(TrueCoincidence) + "_Background_" + std::to_string(Background) + "_BadCoincidence_" + std::to_string(BadCoincidence) + "_PileUp_" + std::to_string(Pile_UP) + "_BS_1275_" + std::to_string(BS_1275) + ".drs4DataStream";
int NumberOfCountsInSpectrum = 1E3;







//Setup Digitizer and Puls-shape
int sweep = 200; // ns
int kNumberOfBins = 1024; // 1024 # capacitors
double arrival_time_spread = 0.; // arrival time spread (you can leave it as it is)

double pulse_amplitude = -500.; // mV --> scale all amplitudes into this range!
bool isPositiveSignalPolarity = false; // negative pulses
double pulse_delay = 0.; // trigger delay (you can leave it as it is)

// detector A:

double pulseA_riseTime = 5.3;   // ns
double pulseA_pulseWidth = 0.315; // ns


bool pulseA_randomNoise_enabled = true;
double pulseA_randomNoise = 0.35;  // rms [mW]

bool pulseA_baselineOffsetJitter_enabled = true;
double pulseA_meanOfBaselineOffsetJitter = 0.; // mV
double pulseA_stddevOfBaselineOffsetJitter = 5.; // mV

bool pulseA_timeAxisNonLinearity_enabled = true;
double pulseA_fixedPatternApertureJitter = 0.005;  // ns
double pulseA_rndApertureJitter = 0.0025; // ns

// detector B:

double pulseB_riseTime = 5.3;   // ns
double pulseB_pulseWidth = 0.315; // ns


bool pulseB_randomNoise_enabled = true;
double pulseB_randomNoise = 0.35;  // rms [mW]

bool pulseB_baselineOffsetJitter_enabled = true;
double pulseB_meanOfBaselineOffsetJitter = 0.; // mV
double pulseB_stddevOfBaselineOffsetJitter = 5.; // mV

bool pulseB_timeAxisNonLinearity_enabled = true;
double pulseB_fixedPatternApertureJitter = 0.005;  // ns
double pulseB_rndApertureJitter = 0.0025; // ns

