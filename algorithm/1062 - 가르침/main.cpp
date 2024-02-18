#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n, k, ret;
bool alphabet[27];
vector<string> words;

int calcValid() {
    int cnt = 0;
    bool flag;

    for (string word : words) {
        flag = true;

        for (int i=0; i<word.length(); ++i) {
            if (!alphabet[word[i] - 'a']) {
                flag = false;
                break;
            }
        }

        if (flag) {++cnt;}
    }

    return cnt;
}

void dfs(int idx, int cnt) {
    if (cnt == k) {
        ret = max(ret, calcValid());
        return;
    }

    for (int i=idx; i<26; ++i) {
        if (alphabet[i]) continue;
        alphabet[i] = true;
        dfs(i+1, cnt+1);
        alphabet[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for (int i=0; i<n; ++i) {
        string tmp; cin >> tmp;
        string t = tmp.substr(4, tmp.size() - 8);
        words.push_back(t);
    }

    if (k < 5) {
        cout << 0; return 0; 
    }
    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;
    k -= 5;

    dfs(0, 0);
    cout << ret;

    return 0;
}