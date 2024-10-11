#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

extern std::string FileName;
extern int NumberOfCountsInSpectrum;

extern double Background; // 0.014 00 1.4%
extern double TrueCoincidence;
extern double BadCoincidence;
extern double BS_1275;
extern double Pile_UP;

extern double lambda;
extern double lower_bound1;
extern double upper_limit1;




extern int SourcePower; //in uCi
extern int sweep; //in ns
extern double PulseWidth; //in ns
extern double risingEdge; //in ns

//positron lifetime!
extern int NumberOfComponentes;
extern double lifetime1;
extern double lifetime2;
extern double lifetime3;
extern double lifetime4;
extern double lifetime5;

extern double intensity1;
extern double intensity2;
extern double intensity3;
extern double intensity4;
extern double intensity5;

extern int sweep;
extern int kNumberOfBins;
extern double arrival_time_spread;
extern double pulse_amplitude;
extern bool isPositiveSignalPolarity;
extern double pulse_delay;
extern double pulseA_riseTime;
extern double pulseA_pulseWidth;
extern bool pulseA_randomNoise_enabled;
extern double pulseA_randomNoise;
extern bool pulseA_baselineOffsetJitter_enabled;
extern double pulseA_meanOfBaselineOffsetJitter;
extern double pulseA_stddevOfBaselineOffsetJitter;
extern bool pulseA_timeAxisNonLinearity_enabled;
extern double pulseA_fixedPatternApertureJitter;
extern double pulseA_rndApertureJitter;
extern double pulseB_riseTime;
extern double pulseB_pulseWidth;
extern bool pulseB_randomNoise_enabled;
extern double pulseB_randomNoise;
extern bool pulseB_baselineOffsetJitter_enabled;
extern double pulseB_meanOfBaselineOffsetJitter;
extern double pulseB_stddevOfBaselineOffsetJitter;
extern bool pulseB_timeAxisNonLinearity_enabled;
extern double pulseB_fixedPatternApertureJitter;
extern double pulseB_rndApertureJitter;

#endif // GLOBALS_H
