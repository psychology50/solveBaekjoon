#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef pair<string, int> psi;

int n;
map<string, int> ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string file; cin >> file;
        string extends = file.substr(file.find('.') + 1);
        
        ++ans[extends];
    }

    for (auto iter : ans) {
        cout << iter.first << " " << iter.second << "\n";
    }
    return 0;
}