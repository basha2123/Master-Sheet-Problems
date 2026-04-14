#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pieces(vector<double>& ropes, double len) {
    int count = 0;
    for (double r : ropes)
        count += (int)(r / len);
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> ropes(n);
    for (int i = 0; i < n; i++)
        cin >> ropes[i];

    double low = 0, high = *max_element(ropes.begin(), ropes.end());

    while (high - low > 1e-6) {
        double mid = (low + high) / 2;

        if (pieces(ropes, mid) >= k)
            low = mid;
        else
            high = mid;
    }

    cout << low << endl;
    return 0;
}
