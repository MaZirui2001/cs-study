#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
int main(){
char *p = (char*) malloc(2 * sizeof(char));
strncpy(p, "abcdefghijklmn", 10);
cout << strcmp(p, "abcdefghij");
}