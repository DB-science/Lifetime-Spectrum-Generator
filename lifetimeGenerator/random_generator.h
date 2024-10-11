#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>
#include <vector>
#include <map>

class CustomRandomGenerator {
public:
    CustomRandomGenerator(const std::map<double, double>& distribution);
    double generate();

private:
    std::vector<double> values;
    std::discrete_distribution<> dist;
    std::mt19937 gen;
};

#endif // RANDOM_GENERATOR_H
