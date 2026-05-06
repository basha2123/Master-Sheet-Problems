#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getWord(const string& s, int& i) {
    string word = "";
    while (i < s.size() && s[i] != ' ') {
        word += s[i++];
    }
    return word;
}

void countLogEvents(const string& log) {
    int info = 0, warn = 0, error = 0;

    int i = 0;
    while (i < log.size()) {
        string word = getWord(log, i);

        if (word == "INFO") info++;
        else if (word == "WARN") warn++;
        else if (word == "ERROR") error++;

        i++; // skip space
    }

    cout << "INFO: " << info << endl;
    cout << "WARN: " << warn << endl;
    cout << "ERROR: " << error << endl;

    // Find most frequent
    string most = "INFO";
    int maxCount = info;

    if (warn > maxCount) {
        maxCount = warn;
        most = "WARN";
    }
    if (error > maxCount) {
        maxCount = error;
        most = "ERROR";
    }

    cout << "Most common: " << most << endl;
}

void findDuplicates(vector<int>& ids) {
    int n = ids.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (ids[i] == ids[j]) {
                count++;
                visited[j] = true;
            }
        }

        if (count > 1) {
            cout << "ID " << ids[i] << " appears " << count << " times\n";
        }
    }
}

int main() {
    // Log test
    string log = "INFO ERROR INFO WARN ERROR INFO WARN INFO";
    countLogEvents(log);

    cout << endl;

    // Product ID test
    vector<int> ids = {101, 202, 101, 303, 202, 404, 101};
    findDuplicates(ids);

    return 0;
}
