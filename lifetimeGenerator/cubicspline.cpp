#include "cubicspline.h"
#include <stdexcept>

// Konstruktor zur Berechnung der Spline-Koeffizienten
CubicSpline::CubicSpline(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size() || x.size() < 2) {
        throw std::invalid_argument("Ungültige Eingabe: x und y müssen gleich groß sein und mindestens 2 Punkte enthalten.");
    }

    n = x.size() - 1;
    this->x = x;
    a = y;

    std::vector<double> h(n);
    for (size_t i = 0; i < n; ++i) {
        h[i] = x[i+1] - x[i];
    }

    std::vector<double> alpha(n);
    for (size_t i = 1; i < n; ++i) {
        alpha[i] = (3 / h[i] * (y[i+1] - y[i])) - (3 / h[i-1] * (y[i] - y[i-1]));
    }

    std::vector<double> l(n+1), mu(n+1), z(n+1);
    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;

    for (size_t i = 1; i < n; ++i) {
        l[i] = 2 * (x[i+1] - x[i-1]) - h[i-1] * mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i-1] * z[i-1]) / l[i];
    }

    l[n] = 1;
    z[n] = 0;
    c.resize(n+1);
    b.resize(n);
    d.resize(n);
    c[n] = 0;

    for (int j = n - 1; j >= 0; --j) {
        c[j] = z[j] - mu[j] * c[j+1];
        b[j] = (y[j+1] - y[j]) / h[j] - h[j] * (c[j+1] + 2 * c[j]) / 3;
        d[j] = (c[j+1] - c[j]) / (3 * h[j]);
    }
}

// Interpolation eines einzelnen Wertes
double CubicSpline::interpolate(double x_value) const {
    size_t i = findSegment(x_value);
    double dx = x_value - x[i];
    return a[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;
}

// Interpolation über einen Bereich von x-Werten
std::vector<DataPoint> CubicSpline::interpolateRange(double x_start, double x_end, double step) const {
    std::vector<DataPoint> interpolatedData;

    for (double x_value = x_start; x_value <= x_end; x_value += step) {
        double y_value = interpolate(x_value);
        interpolatedData.push_back({x_value, y_value});
    }

    return interpolatedData;
}

// Hilfsfunktion, um den Spline-Segment zu finden
size_t CubicSpline::findSegment(double x_value) const {
    if (x_value < x.front() || x_value > x.back()) {
        throw std::out_of_range("Der Wert liegt außerhalb des Bereichs.");
    }

    size_t i = 0;
    for (size_t j = 0; j < n; ++j) {
        if (x_value >= x[j] && x_value <= x[j+1]) {
            i = j;
            break;
        }
    }
    return i;
}
