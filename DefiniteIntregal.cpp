#include <iostream>
#include <cmath>

// Define the function to integrate
double f(double x) {
    return x * x;  // Example: f(x) = x^2
}

// Trapezoidal Rule
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    
    return sum * h;
}

// Simpson's Rule
double simpsonsRule(double a, double b, int n) {
    if (n % 2 != 0) n++; // Ensure n is even for Simpson's Rule

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }
    
    return (sum * h) / 3.0;
}

int main() {
    double a = 0, b = 2; // Integration limits
    int n = 100; // Number of subintervals

    std::cout << "Trapezoidal Rule Result: " << trapezoidalRule(a, b, n) << std::endl;
    std::cout << "Simpson's Rule Result: " << simpsonsRule(a, b, n) << std::endl;

    return 0;
}
