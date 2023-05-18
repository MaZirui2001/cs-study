#include <stdio.h>
int main() {
    long a[0][4];
    printf("%ld, %ld\n", sizeof(a), a[0][0]);
 }