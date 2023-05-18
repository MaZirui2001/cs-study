#include <stdio.h>
#include <stdlib.h>
int strcmp(char* str1, char* str2){
    int i = 0;
    for(; str1[i] && str2[i]; i++){
        if(str1[i] < str2[i]) return -1;
        else if(str1[i] > str2[i]) return 1;
    }
    if(str1[i]) return 1;
    else if(str2[i]) return -1;
    return 0;
}
void string_sort(char *str[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            int result = strcmp(str[j], str[j+1]);
            if(result == 1){
                char* tmp = str[j];
                str[j] = str[j+1];
                str[j+1] = tmp;
            }
        }
    }
}
// extern void string_sort(char* str[], int n);
int main(){
    char *str[100] = {NULL};
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        str[i] = (char*)malloc(100 * sizeof(char));
        scanf("%s", str[i]);
    }
    string_sort(str, n);
    for(int i = 0; i < n; i++){
        printf("%s\n", str[i]);
    }
    for(int i = 0; i < n; i++){
        free(str[i]);
    }
    return 0;
}
// int main(){
//     printf("hello\n");
//     return 0;
// }