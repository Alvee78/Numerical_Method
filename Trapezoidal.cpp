#include <bits/stdc++.h>
using namespace std;

class Trapizoid{
    public:
        vector<double> x = {0,0.125,0.25,0.375,.5,.625,.75,.87,1};
        vector<double> y = {1,.8889,.8,.7273,.6667,.6154,.5714,.5333,.5};
        void find(){
            int n = x.size();
            double integral = 0.0;
            for(int i = 0; i < n - 1; i++) {
                double h = x[i+1] -x[i];
                integral += (h/2)*(y[i] +y[i+1]);
            }
            cout << "Area is = " << integral << endl;
        }
};

int main() {
    Trapizoid t;
    t.find();    
    return 0;
}
