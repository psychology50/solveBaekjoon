#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, a, b;
vector<int> arr;
vector<int> ans;
vector<bool> visit;
vector<int> list;
int maximum = INT_MIN;

int calc() {
    vector<int> temp_list;
    int temp = list[0];
    for (int i = 1; i < n; i++) {
        if (ans[i] == 1)
            temp += list[i];
        if (ans[i] == 2) {
            temp_list.push_back(temp);
            temp = list[i];
        }
    }
    temp_list.push_back(temp);
    temp = 1;
    for (int i = 0; i < temp_list.size(); i++)
        temp *= temp_list[i];
    return temp;
}

void dfs(int x, int p, int q) {
    if (p <= a && q <= b) {
        if (x == n) {
            maximum = max(maximum, calc());
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            visit[i] = true;
            list.push_back(arr[i]);
            if (x == 0)
                dfs(x + 1, p, q);
            else {
                ans[x] = 1;
                dfs(x + 1, p + 1, q);
                ans[x] = 2;
                dfs(x + 1, p, q + 1);
                ans[x] = 0;
            }
            list.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    arr.resize(n);
    ans.resize(n);
    visit.resize(n, false);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> a >> b;
    dfs(0, 0, 0);
    cout << maximum;

    return 0;
}