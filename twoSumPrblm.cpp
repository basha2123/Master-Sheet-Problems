#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,6,7};
    int size = 6;
    int target = 6;
    
    int l = 0, r = size-1;
    
    while(l < r){
        int sum = arr[l] + arr[r];
        
        if(sum == target){
            cout << "Target Found of index : " << l+1 << " and " << r+1;
            break;
        }
        else if(sum < target) l++;
        else r--;
    }
    return 0;
}
