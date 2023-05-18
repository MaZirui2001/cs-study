#include <iostream>
using namespace std;
void bubblesort(int *a, int n){
    if(n == 0) return;
    else{
        int i;
        for(i = 0; i < n - 1; i++){
            if(a[i] > a[i+1]){
                a[i] ^= a[i+1];
                a[i+1] ^= a[i];
                a[i] ^= a[i+1];
            }
        }
        bubblesort(a, n - 1);
    }
}
int main(){
    int a[6] = {6, 5, 4, 3, 2, 1};
    bubblesort(a, 6);
    for(int i = 0; i < 6; i++){
        cout << a[i] << endl;
    }
    return 0;
}