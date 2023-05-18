#include <stdio.h>
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
    int x, t, i, j;
    for(i = 0; i < d; i++){
        x = a[i];
        t = i;
        for(j = 0; j < n / d - 1; j++){
            a[t] = a[(t + k) % n];
            t = (t + k) % n;
        }
        a[t] = x;
    }
}
int main(){
    int n, k;
    int i, j;
    scanf("%d %d", &n, &k);
    // int *a = new int[n];
    for(i = 0; i < n; i++){
        scanf("%d", a+i);
    }
    shift_left(k, n);
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}