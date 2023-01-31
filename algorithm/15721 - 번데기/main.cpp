#include <iostream>

#define endl "\n"

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, t, flag; cin >> a >> t >> flag;
    int round=1, total=7;
    int tmp = 4;
    int now;

    while (t > tmp) {
        tmp += 4 + round++;
        total += 4 + 2*(round+1);
    }
    tmp -= (4 + round-1);
    total -= (4 + 2*(round+1));

    if (t - tmp <= 2) {
        now = (!flag) ? total + 2*(t-tmp)-1 : total + 2*(t-tmp);
        cout << now % a << endl;
    } else {
        now = (!flag) ? total + 4 + (t-tmp-2) : total + 4 + (round+1) + (t-tmp-2);
        cout << now % a << endl;
    }

    return 0;
}