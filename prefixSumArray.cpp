#include<iostream>
using namespace std;

int sum(int prefix[], int r){
    return prefix[r];
}

//overloading
int sum(int prefix[], int l, int r){
    if(l == 0) return prefix[r];
    return prefix[r] - prefix[l - 1];
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int prefix[6];

    prefix[0] = arr[0];
    for(int i = 1; i < 6; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    for(int i = 0; i < 6; i++){
        cout << prefix[i] << " ";
    }
    cout << endl;
    
    cout << sum(prefix, 4) << endl;  //sum array upto index 4
    cout << sum(prefix, 2, 5) << endl;  //sum array from index 2 to 5

    return 0;
}

