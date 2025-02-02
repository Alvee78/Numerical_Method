#include <bits/stdc++.h>
using namespace std;

class LagrangeInterpolation {
    private:
    vector<double> x = {2, 2.5, 3.0};
    vector<double> y = {0.6931, 0.91629, 1.09861};
    public:
    void interpolate(double targetX) {
        int n = x.size();
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            double maxTerm = y[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    maxTerm *= (targetX - x[j])/ (x[i] - x[j]);
                }
            }
            ans += maxTerm;
        }
        cout << "Interpolated value at x = " << targetX << " is " << ans << endl;
    }
};

int main() {
    LagrangeInterpolation interpolator;
    double value = 2.7;
    interpolator.interpolate(value);
    return 0;
}