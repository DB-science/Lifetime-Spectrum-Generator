#include "spectragenerator.h"


double DiscretPositronAnhillationLifetime(int NumberOfComponents, double lifetime1, double lifetime2, double lifetime3, double lifetime4, double lifetime5,
                                          double intensity1, double intensity2, double intensity3, double intensity4, double intensity5,
                                          std::exponential_distribution<double>& distribution1,
                                          std::exponential_distribution<double>& distribution2, std::exponential_distribution<double>& distribution3,
                                          std::exponential_distribution<double>& distribution4, std::exponential_distribution<double>& distribution5,
                                          std::mt19937& generator)

{
    double positronLifetime= 0.0;

    if (NumberOfComponents == 1) {
        double overall_intensity = intensity1;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        double r = ((double)rand() / RAND_MAX);
        if (r <= intensity1 / overall_intensity)
        {

            distribution1.param(std::exponential_distribution<double>::param_type(1 / lifetime1));

            positronLifetime = (distribution1(generator));
        }
    }
    else if (NumberOfComponents == 2) {
        double overall_intensity = intensity1 + intensity2;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        double r = ((double)rand() / RAND_MAX);
        if (r <= intensity1 / overall_intensity)
        {
            distribution1.param(std::exponential_distribution<double>::param_type(1 / lifetime1));

            positronLifetime = (distribution1(generator));
        }
        else if (r <= (intensity1 + intensity2) / overall_intensity)
        {
            distribution2.param(std::exponential_distribution<double>::param_type(1 / lifetime2));

            positronLifetime = (distribution2(generator));
        }
        else {
            distribution3.param(std::exponential_distribution<double>::param_type(1 / lifetime3));
            positronLifetime = (distribution3(generator));
        }
    }
    else if (NumberOfComponents == 3) {
        double overall_intensity = intensity1 + intensity2 + intensity3;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        double r = ((double)rand() / RAND_MAX);
        if (r <= intensity1 / overall_intensity)
        {
            distribution1.param(std::exponential_distribution<double>::param_type(1 / lifetime1));

            positronLifetime = (distribution1(generator));
        }
        else if (r <= (intensity1 + intensity2) / overall_intensity)
        {
            distribution2.param(std::exponential_distribution<double>::param_type(1 / lifetime2));

            positronLifetime = (distribution2(generator));
        }
        else {
            distribution3.param(std::exponential_distribution<double>::param_type(1 / lifetime3));
            positronLifetime = (distribution3(generator));
        }
    }
    else if (NumberOfComponents == 4) {
        double overall_intensity = intensity1 + intensity2 + intensity3 + intensity4;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        double r = ((double)rand() / RAND_MAX);
        if (r <= intensity1 / overall_intensity)
        {
            distribution1.param(std::exponential_distribution<double>::param_type(1 / lifetime1));

            positronLifetime = (distribution1(generator));
        }
        else if (r <= (intensity1 + intensity2) / overall_intensity)
        {
            distribution2.param(std::exponential_distribution<double>::param_type(1 / lifetime2));

            positronLifetime = (distribution2(generator));
        }
        else if (r <= (intensity1 + intensity2 + intensity3) / overall_intensity)
        {
            distribution3.param(std::exponential_distribution<double>::param_type(1 / lifetime3));

            positronLifetime = (distribution3(generator));
        }
        else {
            distribution4.param(std::exponential_distribution<double>::param_type(1 / lifetime4));
            positronLifetime = (distribution4(generator));
        }
    }
    else if (NumberOfComponents == 5) {
        double overall_intensity = intensity1 + intensity2 + intensity3 + intensity4 + intensity5;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        double r = ((double)rand() / RAND_MAX);
        if (r <= intensity1 / overall_intensity)
        {
            distribution1.param(std::exponential_distribution<double>::param_type(1 / lifetime1));

            positronLifetime = (distribution1(generator));
        }
        else if (r <= (intensity1 + intensity2) / overall_intensity)
        {
            distribution2.param(std::exponential_distribution<double>::param_type(1 / lifetime2));

            positronLifetime = (distribution2(generator));
        }
        else if (r <= (intensity1 + intensity2 + intensity3) / overall_intensity)
        {
            distribution3.param(std::exponential_distribution<double>::param_type(1 / lifetime3));

            positronLifetime = (distribution3(generator));
        }
        else if (r <= (intensity1 + intensity2 + intensity3 + intensity4) / overall_intensity)
        {
            distribution4.param(std::exponential_distribution<double>::param_type(1 / lifetime4));

            positronLifetime = (distribution4(generator));
        }
        else {
            distribution5.param(std::exponential_distribution<double>::param_type(1 / lifetime5));
            positronLifetime = (distribution5(generator));
        }
    }
    return positronLifetime;
}
double ContiniousPositronAnhillationLifetime(int NumberOfComponents, double lifetime1, double lifetime1_sigma, double lifetime2, double lifetime2_sigma, double lifetime3, double lifetime3_sigma, double lifetime4, double lifetime4_sigma, double lifetime5, double lifetime5_sigma,
                                             double intensity1, double intensity2, double intensity3, double intensity4, double intensity5,
                                             std::exponential_distribution<double>& distribution1,
                                             std::exponential_distribution<double>& distribution2, std::exponential_distribution<double>& distribution3,
                                             std::exponential_distribution<double>& distribution4, std::exponential_distribution<double>& distribution5,
                                             std::mt19937& generator)

{
    double positronLifetime = 0.0;

    if (NumberOfComponents == 1) {
        double overall_intensity = intensity1;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        double r = ((double)rand() / RAND_MAX);
        if (r <= intensity1 / overall_intensity)
        {

            static std::normal_distribution<double> distributionLifetime1(lifetime1, lifetime1_sigma);
            double value = distributionLifetime1(generator);

            distribution1.param(std::exponential_distribution<double>::param_type(1 / value));

            positronLifetime = (distribution1(generator));
        }
    }
    else if (NumberOfComponents == 2) {
        double overall_intensity = intensity1 + intensity2;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        double r = ((double)rand() / RAND_MAX);
        if (r <= intensity1 / overall_intensity)
        {

            static std::normal_distribution<double> distributionLifetime1(lifetime1, lifetime1_sigma);
            double value = distributionLifetime1(generator);
            distribution1.param(std::exponential_distribution<double>::param_type(1 / value));

            positronLifetime = (distribution1(generator));
        }
        else
        {
            static std::normal_distribution<double> distributionLifetime2(lifetime2, lifetime2_sigma);
            double value2 = distributionLifetime2(generator);
            distribution2.param(std::exponential_distribution<double>::param_type(1 / value2));

            positronLifetime = (distribution2(generator));
        }

    }
    else if (NumberOfComponents == 3) {
        double overall_intensity = intensity1 + intensity2 + intensity3;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        double r = ((double)rand() / RAND_MAX);
        if (r <= intensity1 / overall_intensity)
        {
            static std::normal_distribution<double> distributionLifetime1(lifetime1, lifetime1_sigma);
            double value = distributionLifetime1(generator);

            distribution1.param(std::exponential_distribution<double>::param_type(1 / value));

            positronLifetime = (distribution1(generator));
        }
        else if (r <= (intensity1 + intensity2) / overall_intensity)
        {
            static std::normal_distribution<double> distributionLifetime2(lifetime2, lifetime2_sigma);
            double value2 = distributionLifetime2(generator);
            distribution2.param(std::exponential_distribution<double>::param_type(1 / value2));

            positronLifetime = (distribution2(generator));
        }
        else {

            static std::normal_distribution<double> distributionLifetime3(lifetime3, lifetime3_sigma);
            double value3 = distributionLifetime3(generator);
            distribution3.param(std::exponential_distribution<double>::param_type(1 / value3));
            positronLifetime = (distribution3(generator));
        }
    }
    else if (NumberOfComponents == 4) {
        double overall_intensity = intensity1 + intensity2 + intensity3 + intensity4;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        double r = ((double)rand() / RAND_MAX);
        if (r <= intensity1 / overall_intensity)
        {
            static std::normal_distribution<double> distributionLifetime1(lifetime1, lifetime1_sigma);
            double value = distributionLifetime1(generator);

            distribution1.param(std::exponential_distribution<double>::param_type(1 / value));

            positronLifetime = (distribution1(generator));
        }
        else if (r <= (intensity1 + intensity2) / overall_intensity)
        {
            static std::normal_distribution<double> distributionLifetime2(lifetime2, lifetime2_sigma);
            double value2 = distributionLifetime2(generator);

            distribution2.param(std::exponential_distribution<double>::param_type(1 / value2));

            positronLifetime = (distribution2(generator));
        }
        else if (r <= (intensity1 + intensity2 + intensity3) / overall_intensity)
        {
            static std::normal_distribution<double> distributionLifetime3(lifetime3, lifetime3_sigma);
            double value3 = distributionLifetime3(generator);

            distribution3.param(std::exponential_distribution<double>::param_type(1 / value3));
            positronLifetime = (distribution3(generator));
        }
        else {
            static std::normal_distribution<double> distributionLifetime4(lifetime4, lifetime4_sigma);
            double value4 = distributionLifetime4(generator);

            distribution4.param(std::exponential_distribution<double>::param_type(1 / value4));
            positronLifetime = (distribution4(generator));
        }
    }
    else if (NumberOfComponents == 5) {
        double overall_intensity = intensity1 + intensity2 + intensity3 + intensity4 + intensity5;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        double r = ((double)rand() / RAND_MAX);
        if (r <= intensity1 / overall_intensity)
        {
            static std::normal_distribution<double> distributionLifetime1(lifetime1, lifetime1_sigma);
            double value = distributionLifetime1(generator);

            distribution1.param(std::exponential_distribution<double>::param_type(1 / value));

            positronLifetime = (distribution1(generator));
        }
        else if (r <= (intensity1 + intensity2) / overall_intensity)
        {
            static std::normal_distribution<double> distributionLifetime2(lifetime2, lifetime2_sigma);
            double value2 = distributionLifetime2(generator);
            distribution2.param(std::exponential_distribution<double>::param_type(1 / value2));

            positronLifetime = (distribution2(generator));
        }
        else if (r <= (intensity1 + intensity2 + intensity3) / overall_intensity)
        {
            static std::normal_distribution<double> distributionLifetime3(lifetime3, lifetime3_sigma);
            double value3 = distributionLifetime3(generator);
            distribution3.param(std::exponential_distribution<double>::param_type(1 / value3));
            positronLifetime = (distribution3(generator));
        }
        else if (r <= (intensity1 + intensity2 + intensity3 + intensity4) / overall_intensity)
        {
            static std::normal_distribution<double> distributionLifetime4(lifetime4, lifetime4_sigma);
            double value4 = distributionLifetime4(generator);
            distribution4.param(std::exponential_distribution<double>::param_type(1 / value4));
            positronLifetime = (distribution4(generator));
        }
        else {
            static std::normal_distribution<double> distributionLifetime5(lifetime5, lifetime5_sigma);
            double value5 = distributionLifetime5(generator);
            distribution5.param(std::exponential_distribution<double>::param_type(1 / value5));
            positronLifetime = (distribution5(generator));
        }
    }
    return positronLifetime;
}

double IRF_Gaussian(double FWHM1, double FWHM1_intensity, double FWHM2, double FWHM2_intensity, double t0_shift,
                    std::normal_distribution<double>& distributionFWHM1,std::normal_distribution<double>& distributionFWHM2,
                    std::mt19937& generator){
    double IRF= 0.0;

    if (FWHM1_intensity == 1.0) {
        double overall_intensity = FWHM1_intensity;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance) {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
        }


        distributionFWHM1.param(std::normal_distribution<double>::param_type(0, (FWHM1/2.3548)));

        IRF = (distributionFWHM1(generator));
        }else
        {

        double overall_intensity = FWHM1_intensity + FWHM2_intensity;
        double tolerance = 1e-9; // set a small tolerance value
        if (std::abs(overall_intensity - 1.0) > tolerance)
            {
            throw std::invalid_argument("Error: The intensities must sum up to 1!");
            }


        double r = ((double)rand() / RAND_MAX);
        if (r <= FWHM1_intensity / overall_intensity)
            {
            distributionFWHM1.param(std::normal_distribution<double>::param_type(0, (FWHM1/2.3548)));
            IRF = (distributionFWHM1(generator));
            }else{
            distributionFWHM2.param(std::normal_distribution<double>::param_type(t0_shift, (FWHM2/2.3548)));
            IRF = (distributionFWHM2(generator));
            }
        }
        return IRF;
}

double Background_counts(std::uniform_real_distribution<>& distributionBG, std::mt19937& generator){

    distributionBG.param(std::uniform_real_distribution<>::param_type(0,50));
    double bg_counts = distributionBG(generator);

    return bg_counts;
}

double generatePMTuncertaincy(double timeTransitSpread, double numberOfCounts) {

    double positiv_value = abs(numberOfCounts);

    if (positiv_value <= 0) {
        return 0.0;
    }
    double factor = 1050 / 500;
    double converted_value = factor * positiv_value;
    double value = timeTransitSpread * (1 / ((sqrt(converted_value))));
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::normal_distribution<double> distribution((0.0, value));

    if (distribution.param() != std::normal_distribution<double>().param()) {
        distribution.param(std::normal_distribution<double>::param_type(0.0, value));
    }

    return distribution(gen);
}
