#include "distribution_creater.h"
#include <numeric>


std::map<double, double> createCustomDistribution(const std::vector<DataPoint>& data) {
    std::map<double, double> distribution;
    for (const auto& point : data) {
        distribution[point.x] += point.y;
    }

    // Normieren der Y-Werte
    double sum = std::accumulate(distribution.begin(), distribution.end(), 0.0,
                                 [](double value, const std::map<double, double>::value_type& p) { return value + p.second; });

    for (auto& entry : distribution) {
        entry.second /= sum;
    }

    return distribution;
}

std::map<double, double> smoothDistribution(const std::map<double, double>& distribution, int windowSize = 3) {
    std::map<double, double> smoothedDistribution;

    // Erstellen eines Vektors aus den Verteilungswerten
    std::vector<std::pair<double, double>> points(distribution.begin(), distribution.end());

    // Gleitendes Fenster (Moving Average)
    for (size_t i = 0; i < points.size(); ++i) {
        double smoothedY = 0.0;
        int count = 0;

        // Schleife über das Fenster (links und rechts der aktuellen Position)
        for (int j = -windowSize; j <= windowSize; ++j) {
            int index = i + j;
            if (index >= 0 && index < points.size()) {
                smoothedY += points[index].second;
                ++count;
            }
        }

        // Mittelwert berechnen
        smoothedY /= count;
        smoothedDistribution[points[i].first] = smoothedY;
    }

    return smoothedDistribution;
}
