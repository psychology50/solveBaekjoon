#include <iostream>

using namespace std;

int N;
int graph[21][21];
bool check[21];
int res = 1e9;

void recur(int cnt, int idx) {
    if (cnt == N/2) {
        int start = 0, link = 0;
        for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
            if (check[i] && check[j]) start += graph[i][j] + graph[j][i];
            if (!check[i] && !check[j]) link += graph[i][j] + graph[j][i];
        }
        
        int sum = abs(start - link);
        res = min(res, sum);
    }

    for (int i=cnt; i<N; i++) {
        check[i] = true;
        recur(i+1, idx+1);
        check[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> graph[i][j];
    cout << res << "\n";
    return 0;
}