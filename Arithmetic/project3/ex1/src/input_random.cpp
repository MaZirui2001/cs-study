#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <set>
using namespace std;
int main(){
    srand(time(0));
    int n = 40;
    ofstream fout;
    fout.open("../input/input.txt");
    set<int> low_set;
    set<int> high_set;
    while(n > 0){
        int low = rand() % 50;
        int high = low + rand() % (50 - low + 1);
        if(low <= 30 && high >= 25) continue;
        if(low_set.count(low) && high_set.count(high)) continue;

        low_set.insert(low);
        high_set.insert(high);
        n--; 
        cout << low << " " << high << endl;
        fout << low << " " << high << endl;
    }
    fout.close();
}