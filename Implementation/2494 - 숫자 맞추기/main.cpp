#include <iostream>
#include <algorithm>
#include <string>

#define MOD 10

using namespace std;

typedef struct s_state
{
    int idx, value, cnt;
}              t_state;

int N;
string init, final;
int cache[10001][10];
t_state state[10001][10];

int turn_screw(int row, int num) {
    if (row == N) return 0; // exception handling (out of index)

    int &ret = cache[row][num];
    if (ret) return ret;

    int left = (final[row] - init[row] - num + 20) % MOD; // gap check
    int right = 10 - left;

    int turned_left = turn_screw(row + 1, (num+left) % MOD) + left; // compare left && right
    int turned_right = turn_screw(row + 1, num) + right;

    if (turned_left < turned_right) {
        state[row][num] = {row + 1, (num+left) % MOD, left};
        ret = turned_left;
    } else { 
        state[row][num] = {row + 1, num, -right};
        ret = turned_right;
    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> N >> init >> final;

    cout << turn_screw(0, 0) << "\n";

    int row = 0, num = 0;
    for (int i = 1; i <= N; i++) {
        t_state &curr = state[row][num];
        cout << i << ' ' << curr.cnt << "\n";
        row = curr.idx;
        num = curr.value;
    }

    return 0;
}