#include <bits/stdc++.h>
using namespace std;

class Newton_Backward_Interpolation {
    private:
        vector<double> x = {1891, 1901, 1911, 1921, 1931};
        vector<double> y = {46, 66, 81, 93, 101};
        double find_p(double p, int n) {
            double temp = p;
            for (int i = 1; i < n; ++i) {
                temp = temp * (p + i);
            }
            return temp;
        }
        int fact(int n) {
            int f = 1;
            for (int i = 2; i <= n; ++i) {
                f *= i;
            }
            return f;
        }
        public:
        void find(double value) {
            int n = x.size();
            double table[n][n];
            for(int i = 0; i < n; ++i) {
                table[i][0] = y[i];
            }
            for (int i = 1; i < n; ++i) {
                for (int j = n - 1; j >= i; --j) {
                    table[j][i] = table[j][i - 1] - table[j - 1][i - 1];
                }
            }
            for (int i = 0; i < n; ++i) {
                cout << setw(4) << x[i] << "\t";
                for (int j = 0; j < n - i; ++j) {
                    cout << setw(4) << table[i][j] << "\t";
                }
                cout << endl;
            }
            double sum = table[n - 1][0];
            double p = (value - x[n - 1]) / (x[1] - x[0]);
            for (int i = 1; i < n; ++i) {
                sum = sum + (find_p(p, i) * table[n - 1][i]) / fact(i);
            }
            cout << "Value at " << value << " is " << sum << endl;
        }
};

int main() {
    Newton_Backward_Interpolation interpolator;
    double value = 1895;
    interpolator.find(value);
    return 0;
}