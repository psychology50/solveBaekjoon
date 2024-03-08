#include <bits/stdc++.h>

using namespace std;

string input;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> input;

    int ret = 0;
    string tmp = "";
    bool minus = false;
    for (int i=0; i<=input.length(); ++i) {
        char& c = input[i];

        if (c == '+' || c == '-' || i==input.length()) {
            if (minus) {
                ret -= stoi(tmp); tmp = "";
            } else {
                ret += stoi(tmp); tmp = "";
            }
        } else {
            tmp += c;
        }

        if (c == '-') minus = true;
    }
    cout << ret;
    return 0;
}