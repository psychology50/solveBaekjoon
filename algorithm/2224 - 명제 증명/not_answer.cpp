/*
이 문제는 Union-Find로 해결할 수 없다.
하나의 알파벳이 여러 명제를 증명 가능할 경우 부모가 여럿 생기기 때문
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using pcc = pair<char, char>;
vector<pcc> res;

int n;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int node[52];

int getIndex(char& c) {
    for (int idx=0; idx<alphabet.size(); ++idx) if (alphabet[idx] == c) return idx;
    return -1;
}

bool cmp(pcc& a, pcc& b) {
    int ai = getIndex(a.first), bi = getIndex(b.first);
    if (ai != bi) return ai < bi;
    
    int aj = getIndex(a.second), bj = getIndex(b.second);
    return aj < bj;
}

int F(int& a) {
    if (node[a] == a) return node[a];
    return F(node[a]);
}

void U(int p, int q) {
    p = F(p); q = F(q);
    node[p] = q;
}

void findUnion(int& now, int& a) {
    if (node[a] == a) return;
    res.push_back({alphabet[now], alphabet[node[a]]});
    findUnion(now, node[a]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<52; ++i) node[i] = i;
    for (int i=0; i<n; ++i) {
        string p, oper, q; cin >> p >> oper >> q;
        int pi = getIndex(p[0]), qi = getIndex(q[0]);
        U(pi, qi);
    }

    for (int i=0; i<alphabet.size(); ++i) {
        findUnion(i, i);
    }

    sort(res.begin(), res.end(), cmp);
    cout << res.size() << "\n";
    for (auto r: res) cout << r.first << " => " << r.second << "\n";

    return 0;
}