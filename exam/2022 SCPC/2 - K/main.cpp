#include <iostream>
#include <cstdio>
#include <vector>

#define ll long long
#define MAX 500010
#define MOD 1000000007

using namespace std;

ll Answer;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, test_case;

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
        int n, k; cin >> n >> k;

        vector<int> arr(MAX, 0);
        vector<ll> sum_arr(MAX, 0); 
        ll cnt = 0;

        for (int i=1; i<=n; i++) { // 누적합 만들기
            cin >> arr[i];
            sum_arr[i] = sum_arr[i-1] + (ll)arr[i];
            if (sum_arr[i] == 0) cnt++;
        }

        if (abs(sum_arr[n] % k) > 0) { // 마지막이 0이나 k배수가 아니면 불가능
            cout << "Case #" << test_case+1 << endl;
            cout << 0 << endl;
            continue;
        } 

        if (sum_arr[n] == 0) { // 누적합이 0인 경우
            ll tmp = 1;
            for (int j=1; j<k; j++) {
                tmp *= ((cnt-(ll)j)/(ll)j) % MOD;
            }
            Answer = tmp;
        } else { // 누적합이 k배수
            vector<ll> cache(MAX, 0); 
            ll base = sum_arr[n] / (ll)k;
            
            cache[0] = 1;
            for (int i=1; i<=n; i++) {
                ll tmp = sum_arr[i] / base;
                if (sum_arr[i] % base != 0 || tmp < 1 || k < tmp) continue;
                cache[tmp] += cache[tmp - 1];
            }

            Answer = cache[k-1] % MOD;
        }
        
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}
 
	return 0;
}