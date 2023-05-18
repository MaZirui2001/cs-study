#include <iostream>
#include <vector>
using namespace std;
int root [1000][1000];
double e [1000][1000];
double w [1000][1000];
void optimal_bst(double *p, double *q, int n){
    for(int i = 1; i <= n + 1; i++){
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    for(int l = 0; l <= n; l++){
        for(int i = 1; i <= n - l; i++){
            int j = i + l;
            e[i][j] = __DBL_MAX__;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            int r;
            for(r = i; r <= j; r++){
                double tmp = e[i][r-1] + e[r+1][j] + w[i][j];
                if(tmp < e[i][j]){
                    e[i][j] = tmp;
                    root[i][j] = r;
                }
            }
        }
    }
}
void create_binary(int i, int j, int parent){
    int Root = root[i][j];
    if(parent == 0) {
        cout << root[i][j] << " is the root" << endl;
    }
    if(j == Root) {
        cout << "d" << j << " is the right son of " << Root << endl;
    }
    else{
        cout << "k" << root[Root+1][j] << " is the right son of " << Root  << endl;
        create_binary(Root + 1, j, root[i][j]);
    }
    if(i == Root) {
        cout << "d" << i-1 << " is the left son of " << Root  << endl;
    }
    else{
        cout << "k" << root[i][Root-1] << " is the left son of " << Root  << endl;
        create_binary(i, root[i][j] - 1, root[i][j]);
    }

}
int main(){
    double p[1000] = {0, 0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14};
    double q[1000] = {0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05};
    int n = 7;
    optimal_bst(p, q, n);
    create_binary(1, n, 0);
    cout << e[1][7] << endl;
    return 0;
}