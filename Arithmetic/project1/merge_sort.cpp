#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void merge(int arr[], int p, int q, int r){
    int num1 = q - p + 1;
    int num2 = r - q;
    int *left = new int[num1+1];
    int *right = new int[num2+1];
    for(int i = 0; i < num1; i++){
        left[i] = arr[p + i];
    }
    left[num1] = INT32_MAX;
    for(int i = 0; i < num2; i++){
        right[i] = arr[q + 1 + i];
    }
    right[num2] = INT32_MAX;
    int i = 0, j = 0;
    for(int k = p; k <= r; k++){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
    }
    delete [] left;
    delete [] right;
}
void merge_sort(int arr[], int p, int r){
    // if(p < r){
    //     int q = (p + r) / 2;
    //     merge_sort(arr, p, q);
    //     merge_sort(arr, q+1, r);
    //     merge(arr, p, q, r);
    // }
    int left, mid, right;
    for(int i = 1; i < r - p + 1; i *= 2){
        for(left = p ; left < r - p + 1 - i; left = right + 1){
            mid = left + i - 1;
            right = mid + i;
            if (right > r) right = r;
            merge(arr, left, mid, right);
        }
    }
}
int main(){
    int n;
    cin >> n;
    int *num = new int[n];
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    merge_sort(num, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}