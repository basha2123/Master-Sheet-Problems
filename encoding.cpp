#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getLabel(const vector<string>& unique, const string& val) {
    for (int i = 0; i < unique.size(); i++) {
        if (unique[i] == val) return i;
    }
    return -1;
}

vector<int> labelEncode(const vector<string>& data, vector<string>& unique) {
    vector<int> encoded;

    for (auto& val : data) {
        // Check if already exists
        int idx = getLabel(unique, val);

        if (idx == -1) {
            unique.push_back(val);
            idx = unique.size() - 1;
        }
        encoded.push_back(idx);
    }

    return encoded;
}

vector<vector<int>> oneHotEncode(const vector<string>& data, const vector<string>& unique) {
    vector<vector<int>> result;

    for (auto& val : data) {
        vector<int> row(unique.size(), 0);

        for (int i = 0; i < unique.size(); i++) {
            if (unique[i] == val) {
                row[i] = 1;
                break;
            }
        }

        result.push_back(row);
    }

    return result;
}

int main() {
    // Sample dataset
    vector<string> gender = {"Male", "Female", "Female", "Male"};
    vector<string> city = {"New York", "Paris", "Tokyo", "Paris"};

    // ----- Label Encoding -----
    vector<string> genderUnique, cityUnique;

    vector<int> genderLabel = labelEncode(gender, genderUnique);
    vector<int> cityLabel = labelEncode(city, cityUnique);

    cout << "Label Encoding:\n";

    cout << "Gender: ";
    for (int x : genderLabel) cout << x << " ";
    cout << endl;

    cout << "City: ";
    for (int x : cityLabel) cout << x << " ";
    cout << endl;

    // ----- One Hot Encoding -----
    vector<vector<int>> genderOH = oneHotEncode(gender, genderUnique);
    vector<vector<int>> cityOH = oneHotEncode(city, cityUnique);

    cout << "\nOne-Hot Encoding:\n";

    cout << "Gender:\n";
    for (auto& row : genderOH) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    cout << "City:\n";
    for (auto& row : cityOH) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}
