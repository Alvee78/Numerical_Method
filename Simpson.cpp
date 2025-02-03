#include <bits/stdc++.h>
using namespace std;

class Simpsons{
    public:
        vector<double> x = {0,0.125,0.25,0.375,.5,.625,.75,.87,1};
        vector<double> y = {1,.8889,.8,.7273,.6667,.6154,.5714,.5333,.5};
        void find(){
            int n = x.size();
            if ((n - 1) % 2 != 0) {
                cout << "Simpson's rule requires an even number of subintervals." << endl;
                return;
            }

            double h = (x[n - 1] - x[0]) / (n - 1);
            double integral = y[0] + y[n - 1];

            for (int i = 1; i < n - 1; i++) {
                if (i % 2 == 1) 
                    integral += 4 * y[i];
                else            
                    integral += 2 * y[i];
            }

            integral *= (h / 3);
            cout << "Area is = " << integral << endl;
        }
};

int main() {
    Simpsons s;
    s.find();    
    return 0;
}

