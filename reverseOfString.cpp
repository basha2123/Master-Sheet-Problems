#include<iostream>
using namespace std;

void reverse(string &s, int l, int r){
    if(l >= r) return;

    swap(s[l], s[r]);
    reverse(s, l + 1, r - 1);
}

int main(){
    string s = "HELLO";
    reverse(s, 0, s.length() - 1);
    cout << s;
    return 0;
}
