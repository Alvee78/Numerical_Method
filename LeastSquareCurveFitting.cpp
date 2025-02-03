#include <bits/stdc++.h>
using namespace std;

class Least_Square_Curve_Fitting{
    public:
        // vector<double>x = {1, 2, 3 ,4 ,5};
        // vector<double>y = {0.6, 2.4, 3.5, 4.8, 5.7}; //Best-fit line equation: y = 1.26x + (-0.38)
        vector<double>x = {0,2,5,7};
        vector<double>y = {-1,5,12,20};//Best-fit line equation: y = 2.89655x + (-1.13793)
        void find(){
            int n = x.size();
            double sum_x = 0, sum_y = 0 , sum_xx = 0, sum_xy = 0;
            for(int i = 0; i < n; i++) {
                sum_x += x[i];
                sum_y += y[i];
                sum_xx += (x[i] * x[i]);
                sum_xy += (x[i] * y[i]);
            }
            double a = (n*sum_xy - sum_x*sum_y)/(n*sum_xx - sum_x*sum_x);
            double b = (sum_y - a*sum_x)/n;
            cout << "Best-fit line equation: y = " << a << "x + ("<< b <<")" << endl;
        }
};

int main() {
    Least_Square_Curve_Fitting lscf;
    lscf.find();    
    return 0;
}
