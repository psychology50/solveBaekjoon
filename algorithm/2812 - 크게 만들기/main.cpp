#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
int n, k;
string number;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> number;

    // 2중 반복 타임오버
    // while (true) {
    //     int minIdx = 0;
    //     bool flag = false;
    //     for (int i=1; i<number.size(); ++i) {
    //         if (number[minIdx] - '0' < number[i] - '0') {
    //             number.erase(number.begin() + minIdx);
    //             flag = true;
    //             break;
    //         } else {
    //             minIdx = i;
    //         }
    //     }
    //     if (!flag) number.erase(number.begin() + minIdx);

    //     if (number.size() == (n-k)) break;
    // }

    // 이건 왜 타임 오버..
    // int minIdx = 0, cnt = 0, i = 1;
    // while (true) {
    //     cout << "numberSize = " << number.size() << " : i = " << i << " (minIndex="<<minIdx << ")" << endl;;
    //     if (i >= number.size() || cnt == k) break;

    //     if (number[minIdx] - '0' < number[i] - '0') {
    //         cout << "pop()\n"; 
    //         number.erase(number.begin() + minIdx);
    //         ++cnt; minIdx=0; i=1;
    //         continue;
    //     } else {
    //         minIdx = i;
    //     }
    //     ++i;
    // }
    // if (cnt != k) number.erase(number.end() - (k-cnt), number.end());

    int cnt = 0;
    stack<int> stack;
    for (int i=0; i<number.length(); ++i) {
        while (!stack.empty() && stack.top() < number[i]-'0' && cnt < k) {
            stack.pop(); ++cnt;
        }
        stack.push(number[i] - '0');
    }
    while (cnt != k) {
        stack.pop(); ++cnt;
    }

    string ans;
    while (!stack.empty()) {ans += stack.top()+'0'; stack.pop();}
    reverse(ans.begin(), ans.end());

    cout << ans;
    return 0;
}