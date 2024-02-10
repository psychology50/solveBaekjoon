#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Coin {
    int gold, silver, bronze;
} Coin;
Coin start, target;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> start.gold >> start.silver >> start.bronze >> target.gold >> target.silver >> target.bronze;
    
    int cnt = 0;
    while (start.gold >= target.gold) {
        if (start.silver < target.silver) {
            --start.gold;
            start.silver += 9;
            ++cnt;
        } else {
            if (start.bronze < target.bronze) {
                --start.silver;
                start.bronze += 9;
                ++cnt;
            }
        }

        if (start.gold >= target.gold && start.silver >= target.silver && start.bronze >= target.bronze) {cout << cnt; return 0;}
    }

    while (start.silver >= target.silver) {
        if (start.gold < target.gold) {
            start.silver -= 11;
            ++start.gold;
            ++cnt;
        } else if (start.bronze < target.bronze) {
                --start.silver;
                start.bronze += 9;
                ++cnt;
        }

        if (start.gold >= target.gold && start.silver >= target.silver && start.bronze >= target.bronze) {cout << cnt; return 0;}
    }

    while (start.bronze >= target.bronze) {
        if (start.silver < target.silver) {
            start.bronze -= 11;
            ++start.silver;
            ++cnt;
        } else {
            if (start.gold < target.gold) {
                start.silver -= 11;
                ++start.gold;
                ++cnt;
            }
        }

        if (start.gold >= target.gold && start.silver >= target.silver && start.bronze >= target.bronze) {cout << cnt; return 0;}
    }

    cout << -1;
    return 0;
}