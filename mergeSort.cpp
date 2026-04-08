#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int i = l;
    int j = mid + 1;
    int k = 0;
    
    int temp[100];
    
    while(i<=mid && j<=r){
        if(arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    
    while(i<=mid) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];
    
    for(int p=0; p<k; p++)
        arr[l+p] = temp[p];
}

void mergeSort(int arr[], int l, int r){
    if(l>=r) return;
    int mid = (l+r)/2;
    
    mergeSort(arr, l , mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main(){
    int arr[] = {8,2,4,1,3};
    int n = 5;
    mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
