#include <iostream>
using namespace std;

int searchRotated(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[low] <= arr[mid]) {
            if(target >= arr[low] && target < arr[mid]){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        else {
            if (target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int n = 7;
    int target = 5;

    int index = searchRotated(arr, n, target);
    cout << index;

    return 0;
}
