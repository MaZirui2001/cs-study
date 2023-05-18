#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
int b[50][50];
int c[50][50];
int LCS_length(char x[], int m, char y[], int n){
    for(int i = 1; i <= m; i++){
        c[i][0] = 0;
    }
    for(int j = 1; j < n; j++){
        c[0][j] = 0;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(x[i] == y[j]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            }
            else if(c[i-1][j] > c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
        }
    }
    return c[m][n];
}
void print_LCS(ofstream &fout, char x[], int i, int j){
    if(i == 0 || j == 0) return;
    if(b[i][j] == 0){
        print_LCS(fout, x, i-1, j-1);
        cout << x[i] << " ";
        fout << x[i] << " ";
    }
    else if(b[i][j] == 1) print_LCS(fout, x, i-1, j);
    else print_LCS(fout, x, i, j-1);
}
int main(){
    ifstream fin;
    ofstream fout, ftime;
    char x[50], y[50];
    fin.open("../input/2_2_input.txt");
    fout.open("../output/result.txt");
    ftime.open("../output/time.txt");
    while(fin.peek() != EOF){
        int n;
        fin >> n;
        for(int i = 1; i <= n; i++){
            fin >> x[i];
        }
        for(int i = 1; i <= n; i++){
            fin >> y[i];
        }
        int length;
        clock_t start, end;
        cout << "Scale = " << n << endl;
        fout << "Scale = " << n << endl;
        ftime << "Scale = " << n << endl;
        start = clock();
        for(int i = 0; i < 1000000; i++){
            length = LCS_length(x, n, y, n);
        }
        end = clock();
        cout << "Total time:\t" << (double)(end - start)  << endl;
        ftime << "Total time:\t" << (double)(end - start)  << endl;
        cout << "LCS length:\t" << length << endl;
        fout << "LCS length:\t" << length << endl;
        cout << "LCS is:\t";
        fout << "LCS is:\t";
        print_LCS(fout, x, n, n);
        cout << endl << endl;
        fout << endl << endl;
        ftime << endl;
    }
    fin.close();
    fout.close();
    ftime.close();
    return 0;
}