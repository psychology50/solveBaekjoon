#include <iostream>
#include <string>

#define MAX 3010

using namespace std;

bool isValid(string input, int start, int end) {
    if (start >= end) return true;

    int l = start, r = end;
    while (l < r) {
        if (input[l++] == input[r--]) return false;
    }

    return isValid(input, start, r-1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;

    ++t;
    while (--t) {
        string input; cin >> input;

        if (input.length() % 2 == 0) {cout << "NO\n"; continue;}
        cout << (isValid(input, 0, input.length()-1) ? "YES\n" : "NO\n");
    }

    return 0;
}