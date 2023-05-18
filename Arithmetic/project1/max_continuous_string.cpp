#include<iostream>
using namespace std;
#include <vector>
void max_con(vector<int> num){
    int n = num.size();
    int start = 0;

    int max_start = 0;
    int max_end = 0;
    int max_end_temp = 0;
    int max = -INT32_MAX;

    int max_temp = -INT32_MAX;
    int i, j = 0;
    for(j = 0; j < n; j = i){
        int sum = 0;
        for(i = j; sum >= 0 && i < n; i++){
            sum += num[i];
            if(sum > max_temp) {
                max_end_temp = i;
                max_temp = sum;
            }
        }
        if(max < max_temp){
            max_start = j;
            max_end = max_end_temp;
            max = max_temp;
        }
    }
    cout << max << " " << max_start << " " << max_end;

}
int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    max_con(num);
    return 0;
}