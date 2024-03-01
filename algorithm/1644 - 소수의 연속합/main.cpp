#include <bits/stdc++.h>

#define MAX 4000010

using namespace std;
int n;
bool isPrime[MAX];
vector<int> prime;

void findPrime() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false, isPrime[1] = false;

    for (int i=2; i<=sqrt(n); ++i) {
        if (!isPrime[i]) continue;

        for (int j=i*i; j<=n; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 1) {
        cout << 0; return 0;
    }

    findPrime();
    
    for (int i=2; i<=n; ++i) if (isPrime[i]) prime.push_back(i);

    int start = 0, end = 0, sum = 0, ret = 0;
    while (end <= prime.size()) {
        if (sum < n) {
            sum += prime[end]; ++end;
        } else if (sum >= n) {
            sum -= prime[start]; ++start;
        }

        if (sum == n) ++ret;
    }
    cout << ret;
    
    return 0;
}