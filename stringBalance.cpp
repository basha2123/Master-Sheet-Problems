#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(const string &s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    if (isValid(s))
        cout << "Valid parentheses";
      else cout << "Invalid parentheses";
  
    return 0;
}
