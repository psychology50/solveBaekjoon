#include <iostream>
#include <vector>

#define MAX 20
#define ll long long

using namespace std;

int n, k;
vector<string> numbers;
ll total;
ll factorial[MAX] = {1, };

void init();
void recur();

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();

    return 0;
}

void init() {
    cin >> n;
    for (int i=0; i<n; i++) {
        string num; cin >> num;
        numbers.push_back(num);
    }
    cin >> k;

    // k 자릿수와 배수 구해서 리스트화
    for (int i=1; i<=15; i++) factorial[i] = factorial[i-1] * i;
}

void recur(string num, int digit, int pick) {
    if (pick > n) return;

    // digit == k 자릿수 동일하다면,
    // return;

    // 

}