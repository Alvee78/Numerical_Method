#include<bits/stdc++.h>
using namespace std;

class GaussElimination{
    public:
        vector<vector<double>> mat;
        int n;
        GaussElimination(vector<vector<double>>& mat , int n){
            this->n = n;
            this->mat = mat; 
        }
        void find(){
            for(int i = 0; i < n; i++) {
                int maxRow = i;
                for(int j = i+1; j < n; j++ ){
                    if(mat[j][i] > mat[maxRow][i]){
                        maxRow = j;
                    }
                }
                swap(mat[i],mat[maxRow]);
                for(int j = i+1; j < n; j++){
                    double factor = mat[j][i]/mat[i][i];
                    for(int k = 0; k <= n; k++){
                        mat[j][k] -= factor*mat[i][k];
                    }
                }
            }

            vector<double> ans(n);
            for(int i = n-1;i >=0 ; i--){
                ans[i] = mat[i][n];
                for(int j = i+1; j < n; j++){
                    ans[i] -= mat[i][j] * ans[j];
                }
                ans[i] /= mat[i][i];
            }

            for(int i = 0; i < n; i++){
                cout << char('a'+i) << " = " << ans[i] << endl;
            }
        }


};

int main(){
    vector<vector<double>> mat = {{3.0, 2.0, -4.0, 3.0},
                                  {2.0, 3.0, 3.0, 15.0},
                                  {5.0, -3, 1.0, 14.0}};
    GaussElimination guass(mat,3);
    guass.find();
    return 0;
}