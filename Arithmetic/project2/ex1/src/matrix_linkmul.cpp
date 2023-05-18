#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <ctime>
using namespace std;
long long m[50][50];
int solve[50][50];
void print_result_5(ofstream &fout){
    cout << "The multiply time of scale 5 is:" << endl << "\t";
    fout << "The multiply time of scale 5 is:" << endl << "\t";
    for(int i = 1; i <= 5; i++){
        cout << i << "\t\t";
        fout << i << "\t\t\t\t";
    }
    cout << endl;
    fout << endl;
    for(int i = 1; i <= 5; i++){
        cout << 6 - i << "\t";
        fout << 6 - i << "\t";
        for(int j = 5; j >= 1; j--){
            if (i <= j){
                cout << m[i][j] << "\t";
                fout << m[i][j] << "\t";
            }
            else {
                cout << "\t\t";
                fout << "\t\t";
            }

        }
        cout << endl;
        fout << endl;
    }
    cout << endl;
    fout << endl;
    cout << "The solution of scale 5 is:" << endl << "\t";
    fout << "The solution of scale 5 is:" << endl << "\t";
    for(int i = 1; i <= 5; i++){
        cout << i << "\t" ;
        fout << i << "\t" ;
    }
    cout << endl;
    fout << endl;
    for(int i = 1; i <= 5; i++){
        cout << 6 - i << "\t";
        fout << 6 - i << "\t";
        for(int j = 5; j >= 1; j--){
            if (i <= j){
                cout << solve[i][j] << "\t";
                fout << solve[i][j] << "\t";
            }
            else {
                cout << "\t\t";
                fout << "\t\t";
            }
        }
        cout << endl;
        fout << endl;
    }
    cout << endl;
    fout << endl;
}

long long matrix_chain_order(long long p[], int n){
    for(int i = 1; i <= n; i++){
        m[i][i] = 0;
    }
    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INT64_MAX;
            for(int k = i; k <= j - 1; k++){
                long long q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    solve[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}
void print_optimal_parens(ofstream &fout, int i, int j){
    if(i == j) {
        cout << "A" << i;
        fout << "A" << i;
    }
    else{
        cout << "(";
        fout << "(";
        print_optimal_parens(fout, i, solve[i][j]);
        print_optimal_parens(fout, solve[i][j] + 1, j);
        cout << ")";
        fout << ")";
    }
}
int main(){
    ifstream fin;
    ofstream fout, ftime;
    long long p[50];
    long long least_mul_time;
    clock_t start, end;
    fin.open("../input/2_1_input.txt");
    fout.open("../output/result.txt");
    ftime.open("../output/time.txt");
    while(fin.peek() != EOF){
        int n;
        fin >> n;
        for(int i = 0; i <= n; i++){
            fin >> p[i];
        }
        cout << "Scale = " << n << endl;
        fout << "Scale = " << n << endl;
        ftime << "Scale = " << n << endl;
        start = clock();
        for(int i = 0; i < 1000000; i++)
            least_mul_time = matrix_chain_order(p, n);
        end = clock();
        if(n == 5) print_result_5(fout);
        cout << "Total time: " << (double)(end - start)<< endl;
        ftime << "Total time: " << (double)(end - start)<< endl;
        cout << "Least multiply time:\t" << least_mul_time << endl;
        fout << "Least multiply time:\t" << least_mul_time << endl;
        cout << "Divide method:\t";
        fout << "Divide method:\t";
        print_optimal_parens(fout, 1, n);
        cout << endl << endl;
        fout << endl << endl;
        ftime << endl;
    }
    fin.close();
    fout.close();
    ftime.close();
    return 0;
}