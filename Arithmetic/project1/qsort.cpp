#include <iostream>
using namespace std;
int partition(int a[], int p, int r){
    int x = a[r];
    int i = p;
    int j = p;
    int tmp;
    while(j < r){
        if(x > a[j]){
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i = i + 1;
        }
        j = j + 1;
    }
    tmp = a[i];
    a[i] = a[r];
    a[r] = tmp;
    return i;
}
void qsort(int a[], int p, int r){
    int q;
    if(p < r){
        q = partition(a, p, r);
        qsort(a, p, q - 1);
        qsort(a, q + 1, r);
    }
    return;
}
int main(){
    int n;
    int a[20];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    qsort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}