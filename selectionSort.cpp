#include<iostream>
using namespace std;

int main(){
    int arr[] = {8,2,4,1,8,9,0};
    int n = 7;
    
    for(int i=0;i<n;i++){
        int minIndex = i;
        
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    
    return 0;
}


