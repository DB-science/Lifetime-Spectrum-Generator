#ifndef DISTRIBUTION_CREATER_H
#define DISTRIBUTION_CREATER_H

#include "data_loader.h"
#include <map>
#include <vector>

std::map<double, double> createCustomDistribution(const std::vector<DataPoint>& data);
std::map<double, double> smoothDistribution(const std::map<double, double>& distribution, int windowSize );
#endif // DISTRIBUTION_CREATER_H
