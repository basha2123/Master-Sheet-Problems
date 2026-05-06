#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;


bool isAlnum(char c) {
    return isalnum(c);
}

bool isValidEmail(const string& email) {
    int n = email.size();
    if (n == 0) return false;

    int atPos = -1;

    // Find '@'
    for (int i = 0; i < n; i++) {
        if (email[i] == '@') {
            if (atPos != -1) return false; // multiple @
            atPos = i;
        }
    }

    if (atPos <= 0 || atPos >= n - 1) return false;

    // Local part
    for (int i = 0; i < atPos; i++) {
        char c = email[i];

        if (!(isalnum(c) || c == '.' || c == '_' || c == '%' || c == '+' || c == '-'))
            return false;

        if (i > 0 && email[i] == '.' && email[i - 1] == '.')
            return false; // consecutive dots
    }

    // Domain part
    int dotCount = 0;
    for (int i = atPos + 1; i < n; i++) {
        char c = email[i];

        if (!(isalnum(c) || c == '-' || c == '.'))
            return false;

        if (c == '.') {
            dotCount++;
            if (i > atPos + 1 && email[i - 1] == '.')
                return false;
        }
    }

    if (dotCount == 0) return false;

    // TLD check (last part >= 2 chars)
    int lastDot = email.find_last_of('.');
    if (lastDot == string::npos || lastDot >= n - 2)
        return false;

    return true;
}

/* ---------------- PHONE EXTRACTION ---------------- */

bool isDigitStr(const string& s, int start, int len) {
    for (int i = 0; i < len; i++) {
        if (!isdigit(s[start + i])) return false;
    }
    return true;
}

vector<string> extractPhones(const string& text) {
    vector<string> result;
    int n = text.size();

    for (int i = 0; i < n; i++) {

        // Case 1: 10-digit number
        if (i + 10 <= n && isDigitStr(text, i, 10) && text[i] >= '6') {
            result.push_back(text.substr(i, 10));
        }

        // Case 2: +91-XXXXXXXXXX or +91 XXXXXXXXXX
        if (i + 14 <= n && text[i] == '+' && text.substr(i, 3) == "+91") {
            int j = i + 3;
            if (text[j] == '-' || text[j] == ' ') j++;

            if (j + 10 <= n && isDigitStr(text, j, 10)) {
                result.push_back(text.substr(i, j + 10 - i));
            }
        }

        // Case 3: XXX-XXX-XXXX
        if (i + 12 <= n &&
            isDigitStr(text, i, 3) &&
            text[i + 3] == '-' &&
            isDigitStr(text, i + 4, 3) &&
            text[i + 7] == '-' &&
            isDigitStr(text, i + 8, 4)) {

            result.push_back(text.substr(i, 12));
        }

        // Case 4: (XXX) XXX-XXXX
        if (i + 14 <= n &&
            text[i] == '(' &&
            isDigitStr(text, i + 1, 3) &&
            text[i + 4] == ')' &&
            text[i + 5] == ' ' &&
            isDigitStr(text, i + 6, 3) &&
            text[i + 9] == '-' &&
            isDigitStr(text, i + 10, 4)) {

            result.push_back(text.substr(i, 14));
        }
    }

    return result;
}

/* ---------------- INVOICE VALIDATION ---------------- */

bool validateInvoice(const string& inv) {
    // Format: INV-YYYYMM-XXXXXX
    if (inv.size() != 18) return false;

    if (inv.substr(0, 4) != "INV-") return false;
    if (inv[11] != '-') return false;

    string yearStr = inv.substr(4, 4);
    string monthStr = inv.substr(8, 2);
    string serial = inv.substr(12, 6);

    // Check digits
    for (char c : yearStr) if (!isdigit(c)) return false;
    for (char c : monthStr) if (!isdigit(c)) return false;
    for (char c : serial) if (!isdigit(c)) return false;

    int year = stoi(yearStr);
    int month = stoi(monthStr);

    if (year < 2000 || year > 2100) return false;
    if (month < 1 || month > 12) return false;

    // Checksum stub (example)
    int sum = 0;
    for (char c : serial) sum += (c - '0');

    if (sum % 7 != 0) return false;

    return true;
}

/* ---------------- MAIN ---------------- */

int main() {
    // Email test
    string email = "test.user@example.com";
    cout << "Email valid: " << isValidEmail(email) << endl;

    // Phone test
    string text = "Call +91-9876543210 or (987) 654-3210 or 987-654-3210";
    vector<string> phones = extractPhones(text);

    cout << "\nPhones found:\n";
    for (auto& p : phones) cout << p << endl;

    // Invoice test
    string inv = "INV-202511-000123";
    cout << "\nInvoice valid: " << validateInvoice(inv) << endl;

    return 0;
}
