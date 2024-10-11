#ifndef SPECTRAGENERATOR_H
#define SPECTRAGENERATOR_H

#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <random>

double DiscretPositronAnhillationLifetime(int NumberOfComponents, double lifetime1, double lifetime2, double lifetime3, double lifetime4, double lifetime5,
                                          double intensity1, double intensity2, double intensity3, double intensity4, double intensity5,
                                          std::exponential_distribution<double>& distribution1,
                                          std::exponential_distribution<double>& distribution2, std::exponential_distribution<double>& distribution3,
                                          std::exponential_distribution<double>& distribution4, std::exponential_distribution<double>& distribution5,
                                          std::mt19937& generator);

double ContiniousPositronAnhillationLifetime(int NumberOfComponents, double lifetime1, double lifetime1_sigma, double lifetime2, double lifetime2_sigma, double lifetime3, double lifetime3_sigma, double lifetime4, double lifetime4_sigma, double lifetime5, double lifetime5_sigma,
                                             double intensity1, double intensity2, double intensity3, double intensity4, double intensity5,
                                             std::exponential_distribution<double>& distribution1,
                                             std::exponential_distribution<double>& distribution2, std::exponential_distribution<double>& distribution3,
                                             std::exponential_distribution<double>& distribution4, std::exponential_distribution<double>& distribution5,
                                             std::mt19937& generator);


double IRF_Gaussian(double FWHM1, double FWHM1_intensity, double FWHM2, double FWHM2_intensity, double t0_shift,
                    std::normal_distribution<double>& distributionFWHM1,std::normal_distribution<double>& distributionFWHM2,
                    std::mt19937& generator);

double Background_counts(std::uniform_real_distribution<>& distributionBG, std::mt19937& generator);

double generatePMTuncertaincy(double timeTransitSpread, double numberOfCounts);

#endif // SPECTRAGENERATOR_H
