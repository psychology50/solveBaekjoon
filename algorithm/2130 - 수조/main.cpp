#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define endl "\n"
#define INF 1040002

using namespace std;

int n, v;
int capacity[INF];

void input_value() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int b, h, w, d; cin >> b >> h >> w >> d;
        int a = w * d;
        for (int i=0; i < h; i++) {
            capacity[b] += a;
            b++;
        }
    }
    cin >> v;
}

void solution() {
    int area=0, idx=1;
    bool flag = false;

    for (idx; idx < INF; idx++) {
        //cout << idx << " : " << capacity[idx-1] << ", v = " << v << endl;
        area = capacity[idx-1];
        v -= area;
        if (v == 0) { // 딱 맞게 떨어지면 출력하고 종료
            cout << idx << ".00" << endl;
            return;
        } else if (v < 0) { // for문 break하고 남은 잔여량 소수점 계산
            v += area;
            idx--;
            flag = true;
            break;
        }
    }

    if (!flag) { cout << "OVERFLOW" << endl; return;} // for문이 닫혔는데 flag가 false다? == 수조 부피가 V보다 작았다.

    cout << fixed; cout.precision(2);
    cout << (double)idx + v/(double)area << endl;

    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input_value();
    solution();
    return 0;
}