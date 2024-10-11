#include "random_generator.h"

CustomRandomGenerator::CustomRandomGenerator(const std::map<double, double>& distribution) {
    std::vector<double> weights;
    for (const auto& entry : distribution) {
        values.push_back(entry.first);
        weights.push_back(entry.second);
    }
    std::random_device rd;
    gen = std::mt19937(rd());
    dist = std::discrete_distribution<>(weights.begin(), weights.end());
}

double CustomRandomGenerator::generate() {
    return values[dist(gen)];
}
