#include <bits/stdc++.h>
using namespace std;

class SecandMethod {
    private:
    double tolerance, x0, x1, x2;
    int maxIterations;
    double func(double x) {
        return x * x * x - x * x + 2;
    }
    void setInitialValues(){
        x0 = rand() % 100;
        x1 = rand() % 100 - 200;
        while(func(x0) * func(x1) > 0){
            x0 = rand() % 100;
            x1 = rand() % 100 - 200;
        }
        if(x0 > x1) swap(x0, x1);
    }
    public:
    SecandMethod(double tol = 1e-6, int maxIter = 1000) {
        tolerance = tol;
        maxIterations = maxIter;
        setInitialValues();
    }
    void findRoot() {
        for (int i = 0; i < maxIterations; ++i) {
            double f_x0 = func(x0);
            double f_x1 = func(x1);
            if(f_x1 - f_x0 == 0){
                cout << "Difference between function values is too small. No convergence." << endl;
                return;
            }
            x2 = (x0 * f_x1 - x1 * f_x0) / (f_x1 - f_x0);
            cout << "Iteration X" << i + 1 << " = " << x2 << endl;
            if(fabs(x2 - x1) < tolerance){
                cout << "Root is x = " << x2 << endl;break;
            }
            x0 = x1;
            x1 = x2;
        }
    }
};

int main() {
    SecandMethod solver(1e-6, 1000);
    solver.findRoot();
    return 0;
}