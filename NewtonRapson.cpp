#include <bits/stdc++.h>
using namespace std;

class NewtonRapsonMethod {
    private:
    double tolarance, x;
    int maxIterations;
    double func(double x) {
        return x * x * x - x * x + 2;
    }
    double derivative(double x) {
        return 3 * x * x - 2 * x;
    }
    public:
    NewtonRapsonMethod(double tol = 1e-6, int maxIter = 1000) {
        tolarance = tol;
        maxIterations = maxIter;
        x = rand() % 100;
    }
    void findRoot() {
        for (int i = 0; i < maxIterations; ++i) {
            double f_x = func(x);
            double f_prime_x = derivative(x);
            if(f_prime_x == 0) {
                cout << "Derivative is zero. No convergence." << endl;
                return;
            }
            double x_new = x - f_x / f_prime_x;
            cout << "Iteration X" << i+1 << " = " << x_new << endl;
            if(fabs(x_new - x) < tolarance) {
                cout << "Root is x = " << x_new << endl;break;
            }
            x = x_new;
        }
    }
};

int main() {
    NewtonRapsonMethod solver(1e-6, 1000);
    solver.findRoot();
    return 0;
}