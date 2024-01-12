#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k, n;
string pre = "ABCDEFGHIJKLMNOPQRXTUVWXYZ", target;
vector<string> ladder;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k >> n >> target;
    ladder.resize(n);
    for (int i = 0; i < n; ++i) cin >> ladder[i];

    return 0;
}