#include <iostream>
#include <cmath>
using namespace std;
int a[10];
int gcd(int a, int b){
    int c = a % b;
    while(c){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
void shift_left(int k, int n){
    int d = gcd(n, k);
    for(int i = 0; i < d; i++){
        int x = a[i];
        int t = i;
        for(int j = 0; j < n / d - 1; j++){
            a[t] = a[(t + k) % n];
            t = (t + k) % n;
        }
        a[t] = x;
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    // int *a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    shift_left(k, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}