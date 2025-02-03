#include <bits/stdc++.h>
using namespace std;

class Euler{
    public:
        double x0 = 0, y0 = 1;  // Initial condition y(0) = 1
        double h = 0.05;         // Step size
        double x_target = .1;
        double func(double x,double y) {
            return x*x+y;
        }
        void euler(){
            while (x0 < x_target) {
                y0 += h * func(x0, y0);
                x0 += h;
            }
            cout << "X -> Y = " << y0 << endl;
        }

};
int main() {
    Euler eu;
    eu.euler();
    return 0;
}