#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    string result = "";

    int count = 1;

    for (int i = 1; i <= s.length(); i++) {
        if (i < s.length() && s[i] == s[i - 1]) {
            count++;
        } else {
            result += s[i - 1];           
            result += to_string(count);   
            count = 1;
        }
    }

    cout << result;
    return 0;
}
