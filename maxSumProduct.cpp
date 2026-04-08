#include <iostream>
#include<climits>
using namespace std;

int main() {
    
    int arr[]={10,2,-4,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int prefix = 1;
    int suffix = 1;
    int maximum = INT_MIN;
    for(int i =0;i<n;i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix  *= arr[i];
        suffix *= arr[n-i-1];
        maximum = max(maximum,max(prefix,suffix));
    }
    cout<<maximum;
    return 0;
}
