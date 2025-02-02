#include <bits/stdc++.h>
using namespace std;

class Newton_Divided_Difference {
    private:
        vector<double> x = {1891, 1901, 1911, 1921, 1931};
        vector<double> y = {46, 66, 81, 93, 101};
        double proterm(int i, double value) {
            double pro = 1;
            for (int j = 0; j < i; j++) {
                pro *= (value - x[j]);
            }
            return pro;
        }
    public:
        void find(double value) {
            int n = x.size();
            double table[n][n];
            for(int i = 0; i < n; ++i) {
                table[i][0] = y[i];
            }
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < n - i; ++j) {
                    table[j][i] = (table[j + 1][i - 1] - table[j][i - 1]) / (x[j + i] - x[j]);
                }
            }
            for (int i = 0; i < n; ++i) {
                cout << setw(4) << x[i] << "\t";
                for (int j = 0; j < n - i; ++j) {
                    cout << setw(4) << table[i][j] << "\t";
                }
                cout << endl;
            }
            double sum = table[0][0];
            for (int i = 1; i < n; ++i) {
                sum += (proterm(i, value) * table[0][i]);
            }
            cout << "Value at " << value << " is " << sum << endl;

        }
};

int main() {
    Newton_Divided_Difference interpolator;
    double value = 1895;
    interpolator.find(value);
    return 0;
}