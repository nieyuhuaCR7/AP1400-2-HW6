#ifndef Q1_H
#define Q1_H

#include <functional>
#include <cmath>
#include <limits>
#include <cstdlib>

namespace q1 {

double gradient_descent(double initial_value, double step_size, double (*func)(double));
double derivative(double value, double (*func)(double));

};

// implementations

inline double q1::derivative(double value, double (*func)(double)) {
    return (func(value + 1e-4) - func(value)) / 1e-4;
}

inline double q1::gradient_descent(double initial_value, double step_size, double (*func)(double)) {
    double value = initial_value;
    int max_iterations = 10000;
    double tolerance = 1e-6;
    double change = std::numeric_limits<double>::max();
    int iteration = 0;

    while (std::fabs(change) > tolerance && iteration < max_iterations) {
        double grad = derivative(value, func);
        double new_value = value - step_size * grad;
        change = new_value - value;
        value = new_value;
        iteration++;
    }
    return value;
}

#endif //Q1_H