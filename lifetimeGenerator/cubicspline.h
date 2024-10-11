#ifndef CUBICSPLINE_H
#define CUBICSPLINE_H

#include <vector>
#include "data_loader.h"

class CubicSpline {
public:
    CubicSpline(const std::vector<double>& x, const std::vector<double>& y);

    // Interpolation für einen einzigen Punkt
    double interpolate(double x_value) const;

    // Interpolation über einen Bereich von x-Werten
    std::vector<DataPoint> interpolateRange(double x_start, double x_end, double step) const;

private:
    size_t findSegment(double x_value) const;

    size_t n;
    std::vector<double> a, b, c, d, x;
};

#endif // CUBICSPLINE_H
