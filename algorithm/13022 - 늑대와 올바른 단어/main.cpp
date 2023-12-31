#include <iostream>
#include <vector>

using namespace std;

vector<char> words = {'w', 'o', 'l', 'f'};
int cnt[] = {0, 0, 0, 0};
bool ans = true;

int getIndex(char &c) {
    switch (c) {
        case 'w': return 0;
        case 'o': return 1;
        case 'l': return 2;
        case 'f': return 3;
    }
}

string makeFirstRuleWord(int n) {
    string res;

    for (int i=0; i<n; ++i) res += 'w';
    for (int i=0; i<n; ++i) res += 'o';
    for (int i=0; i<n; ++i) res += 'l';
    for (int i=0; i<n; ++i) res += 'f';
}

void isValid() {
    if (!(cnt[0] == cnt[1] && cnt[1] == cnt[2] && cnt[2] == cnt[3]))
        ans = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string input;
    cin >> input;

    for (int i=0, idx; i<input.size(); ++i) {
        char c = input[i];
        idx = getIndex(c);
        ++cnt[idx];
        
        if (input[i + 1] == 'w') isValid();

        if (i >= 1) {
            if (idx == 0) if (!(input[i - 1] == 'w' || input[i-1] == 'f'))
                ans = false;
            if (idx == 1) if (!(input[i - 1] == 'o' || input[i-1] == 'w'))
                ans = false;
            if (idx == 2) if (!(input[i - 1] == 'l' || input[i-1] == 'o'))
                ans = false;
            if (idx == 3) if (!(input[i - 1] == 'l' || input[i-1] == 'f'))
                ans = false;   
        }
    }
    
    isValid();

    cout << ((ans) ? 1 : 0) << "\n";

    return 0;
}