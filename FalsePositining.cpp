#include <bits/stdc++.h>
using namespace std;

class FalsePositionMethod {
    private:
    double tolarance, a, b, c;
    int maxIterations;
    double func(double x) {
        return x * x * x - x * x + 2;
    }
    void setInitial(){
        srand(time(0));
        a = rand() % 10;
        b = rand() % 10 - 20;
        while(func(a) * func(b) >= 0){
            a = rand()*1.0/RAND_MAX * 5;
            b = rand()*1.0/RAND_MAX * -5;
        }
        if(a < b) swap(a, b);
    }
    public:
    FalsePositionMethod(double tol = 1e-6, int maxIter = 1000) {
        tolarance = tol;
        maxIterations = maxIter;
        setInitial();
    }
    void findRoot() {
        for (int i = 0; i < maxIterations; ++i) {
            c = (a* func(b) - b * func(a)) / (func(b) - func(a));
            cout << "Iteration X" << i+1 << " = " << c << endl;
            double f_c = func(c);
            if(fabs(f_c) < tolarance) {
                cout << "Root is x = " << c << endl;break;
            }
            if(func(a) * f_c < 0) b = c;
            else a = c;
        }
    }
};

int main() {
    FalsePositionMethod solver(1e-6, 1000);
    solver.findRoot();
    return 0;
}