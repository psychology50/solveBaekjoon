#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getParent(int parent[], int x) {
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    return (a == b) ? 1 : 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> truth, tmp;
    vector<vector<int>> party;
    int n, m, truthNum; //사람 수, 파티 수, 진실을 아는 사람의 수
    int total, num, ans = 0;
    bool flag;

    cin >> n >> m >> truthNum;

    if (truthNum == 0) { // 진실을 아는 사람이 한 명도 없을 때
        cout << m;
        return 0;
    }

    int parent[n + 1];

    for(int i = 1 ; i <= n ; i++) parent[i] = i;

    for(int i = 0 ; i < truthNum ; i++) {
        cin >> num;
        truth.push_back(num); // 진실을 아는 사람들의 번호
    }

    for(int i = 0 ; i < m ; i++) {
        cin >> total;

        for(int j = 0 ; j < total ; j++) {
            cin >> num;
            tmp.push_back(num);
        }

        party.push_back(tmp);
        
        for(int j = 1 ; j < tmp.size() ; j++) unionParent(parent, tmp[j - 1], tmp[j]);

        tmp.clear();
    }

    for(int i = 0 ; i < party.size() ; i++) {
        flag = true;

        for(int j = 0 ; j < party[i].size() ; j++) {
            for(int k = 0 ; k < truth.size() ; k++) {
                if(findParent(parent, party[i][j], truth[k])){
                    flag = false;
                    break;
                }
                if(!flag) break;
            }
        }

        if(flag) ans++;
    }

    cout << ans;

    return 0;
}