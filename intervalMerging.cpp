#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> mergeIntervals(vector<pair<int,int>>& intervals) {
    vector<pair<int,int>> result;

    if (intervals.empty()) return result;

    sort(intervals.begin(), intervals.end());

    pair<int,int> current = intervals[0];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= current.second) {
            current.second = max(current.second, intervals[i].second);
        } 
        else {
            result.push_back(current);
            current = intervals[i];
        }
    }

    result.push_back(current);

    return result;
}

int main() {
    vector<pair<int,int>> intervals = {
        {1,3}, {2,6}, {8,10}, {9,12}
    };

    vector<pair<int,int>> merged = mergeIntervals(intervals);

    cout << "Merged Intervals:\n";
    for (auto &p : merged) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    return 0;
}
