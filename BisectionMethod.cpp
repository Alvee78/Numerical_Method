#include<bits/stdc++.h>
using namespace std;

class BisectionMethod {
    private:
        double tolerance, a , b , c;
        int maxIterations;

        double func(double x) {
            return x * x * x - x * x + 2;// x^3 - x^2 + 2 ans = -1;
            //return x * x * x * x - 2 * x * x * x - 3 * x * x + 2 * x + 1; // x^4 - 2x^3 - 3x^2 + 2x + 1 ans = 0.814115;ans = -0.360409;ans = -1.228328
            //return x * x * x * x - x - 10; // x^4 - x - 10 ans = -1.69747; ans = 1.85556;
        }
        void setInitialValues(){
            a = rand() % 100;
            b = rand() % 100 - 200;
            while(func(a) * func(b) > 0){
                a = rand() % 100;
                b = rand() % 100 - 200;
            }
            if(a > b) swap(a, b);
        }
    public:
        BisectionMethod(double tol = 1e-6, int maxIter = 1000) {
            tolerance = tol;
            maxIterations = maxIter;
            setInitialValues();
        }
        void findRoot() {
            for (int i = 0; i < maxIterations; ++i) {
                c = (a + b) / 2;
                cout << "Iteration X" << i+1 << " = " << c << endl;
                double f_c = func(c);
                if(f_c == 0 || (b - a) / 2 < tolerance) {
                    cout << "Root is " << c << endl;break;
                }
                if(func(a) *  f_c < 0) b = c;
                else a = c;
            }
        }
};

int main() {
    BisectionMethod solver(1e-6, 100);
    solver.findRoot();
    return 0;
}