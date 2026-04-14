#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 2; i * i <= n; i++) {
        int count = 0;

        while (n % i == 0) {
            count++;
            n /= i;
        }

        if (count > 0) {
            cout << i;
            if (count > 1)
                cout << "^" << count;
            cout << " ";
        }
    }

    if (n > 1) {
        cout << n;
    }

    return 0;
}
