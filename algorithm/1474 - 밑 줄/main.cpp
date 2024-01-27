#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n, m;
vector<string> words;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    string str;
    int totalCnt = 0;
    for (int i=0; i<n; ++i) {
        cin >> str, words.push_back(str);
        totalCnt += str.size();
    }

    int required = (m - totalCnt) / (n - 1);
    int redundancy = (m - totalCnt) % (n - 1);

    for (int i=1; i<n; ++i) if (redundancy > 0 && ('a' <= words[i][0] && words[i][0] <= 'z')) {
        words[i].insert(0, "_");
        --redundancy;
    }
    for (int i=n-1; i>=1; --i) if (redundancy > 0 && ('A' <= words[i][0] && words[i][0] <= 'Z')) {
        words[i].insert(0, "_");
        --redundancy;
    }

    string underBar;
    for (int i=0; i<required; ++i) underBar += "_";
    for (int i=1; i<n; ++i) words[i].insert(0, underBar);

    for (auto& word : words) cout << word;

    return 0;
}