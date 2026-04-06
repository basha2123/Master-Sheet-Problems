#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    int k = 3;

    int sum = 0;

    for(int i = 0; i < k; i++){
        sum += arr[i];
    }

    int maxSum = sum;

    for(int i = k; i < n; i++){
        sum += arr[i];        
        sum -= arr[i - k];    

        if(sum > maxSum)
            maxSum = sum;
    }

    cout << maxSum << endl;
    return 0;
}
