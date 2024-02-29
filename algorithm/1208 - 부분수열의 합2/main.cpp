#include <bits/stdc++.h>

#define PADDING 1000000

using namespace std;
using ll = long long;

int n, s;
vector<int> numbers;

map<int, int> subArr;
ll ret = 0;

void leftSeg(int sum, int idx) {
    if (idx == n/2) {
        ++subArr[sum + PADDING];
        return;
    }
    
    leftSeg(sum + numbers[idx], idx + 1);
    leftSeg(sum, idx + 1);
}

void rightSeg(int sum, int idx) {
    if (idx == n) {
        ret += subArr[s - sum + PADDING];
        return;
    }

    rightSeg(sum + numbers[idx], idx + 1);
    rightSeg(sum, idx + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s; numbers.resize(n);
    for (int& number: numbers) cin >> number;
    leftSeg(0, 0);
    rightSeg(0, n/2);

    cout << ((s == 0) ? ret - 1 : ret);

    return 0;
}