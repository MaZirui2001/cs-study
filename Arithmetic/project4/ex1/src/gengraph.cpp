#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <random>
#include <ctime>
#include <set>
using namespace std;
int logbase[2] = {5, 7};
int main(){
    srand(time(0));
    string docname = "../input/input";
    ofstream fout;
    int vnum = 27;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 2; j++){
            fout.open(docname + to_string(i) + to_string(j) + ".txt");
            int base = logbase[j-1];
            for(int m = 0; m < vnum; m++){
                set<int>edge;
                int num = log(vnum) / log(base);
                for(int n = 0; n < num; n++){
                    int tar = rand() % vnum;
                    int w = rand() % 61 - 10;
                    if(!edge.count(tar)){
                        edge.insert(tar);
                        fout << m << " " << tar << " " << w << endl;
                    }
                    else{
                        n--;
                    }
                }
            }
            fout.close();
        }
        vnum *= 3;
    }
}