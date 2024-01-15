#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string s, t;
int sLen;

bool recur(string str) {
    if (str == s) return true;
    if (str.size() == sLen) return false;

    bool ans = false;

    if (str[str.size() - 1] == 'A') {
        str.pop_back();
        ans = recur(str) ? true : false;
        str.push_back('A');
    }
    if (!ans && str[0] == 'B') {
        reverse(str.begin(), str.end());
        str.pop_back();
        ans = recur(str) ? true : false;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s >> t;
    sLen = s.size();

    cout << (recur(t) ? 1 : 0);

    return 0;
}