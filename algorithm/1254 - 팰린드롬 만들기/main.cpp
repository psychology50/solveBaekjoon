#include <iostream>
#include <string>

using namespace std;
string input;

int isValid(string& s, int x) {
    int l = x-1;
    int r = s.length();

    while (++l < --r) {
        if (s[l] != s[r]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> input;

    if (input.length() == 0 || input.length() == 1) {
        cout << input.length();
        return 0;
    }

    int ret = 0;
    for (int i=0; i<input.length(); ++i) {
        if (isValid(input, i)) {
            ret = i;
            break;
        }
    }

    cout << input.length() + ret;

    return 0;
}