#include<iostream>
using namespace std;

void reverse(int arr[], int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    int k = 3;

    //printing of array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    //reversing of whole array
    reverse(arr,0,5);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    //rotation of k
    reverse(arr, 0, k-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    //rotation of right by k steps
    reverse(arr, k, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
