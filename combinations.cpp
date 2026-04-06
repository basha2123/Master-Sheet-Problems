#include <iostream>
using namespace std;

int fact(int n){
    if(n==1 || n==0){
        return 1;
    }
    return n*fact(n-1);
}

auto ncr(int &n,int &r){
    int nCr = fact(n)/(fact(r)*fact(n-r));
    return nCr;
}

int main(){
    int n,r;
    cout << "enter n and r: " << endl;
    cin >> n >> r;
    cout << "NCR: " << ncr(n,r);
    return 0;
}
