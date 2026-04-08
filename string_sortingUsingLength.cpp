#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    return a.length() < b.length();
}

int main() {
    vector<string> arr = {"apple", "hi", "banana", "cat"};

    sort(arr.begin(), arr.end(), compare);

    for (string s : arr) {
        cout << s << " ";
    }

    return 0;
}
