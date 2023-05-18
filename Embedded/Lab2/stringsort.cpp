#include<iostream>
#include <string>
using namespace std;
void string_sort(string str[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(str[j] > str[j+1]){
                swap(str[j], str[j+1]);
            }
        }
    }
}
int main(){
    string str[100];
    int n;
        cin >>
    cin >> n;
    for(int i = 0; i < n; i++){ str[i];
    }
    string_sort(str, n);
    for(int i = 0; i < n; i++){
        cout << str[i] << endl;
    }
    return 0;
}