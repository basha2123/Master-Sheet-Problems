#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,2,3,3,4};   //for only sorted array
    int n = 6;
    
    int slow = 0;

    for(int fast = 1; fast < n; fast++){
        if(arr[fast] != arr[slow]){
            slow++;
            arr[slow] = arr[fast];
        }
    }
    
    int newLength = slow + 1;  //new length of unique elements
    
    for(int i = 0; i < newLength; i++)
        cout << arr[i] << " ";

    return 0;
}
