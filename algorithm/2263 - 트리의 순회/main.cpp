#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> inOrder, postOrder;

void preOrder(int postL, int postR, int inL, int inR) {
    if (postL > postR || inL > inR) return;

    int subRoot = postOrder[postR]; // 서브 트리 구간 중 후위 순회 마지막이 서브 루트
    cout << subRoot << " ";

    int inRoot = 0;
    for (int i=inL; i<=inR; ++i) if (inOrder[i] == subRoot) {
        inRoot = i; break;
    }
    int leftSz = inRoot - inL;

    preOrder(postL, postL + leftSz - 1, inL, inRoot - 1);
    preOrder(postL + leftSz, postR - 1, inRoot + 1, inR);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; inOrder.resize(n); postOrder.resize(n);
    for (int& order: inOrder) cin >> order;
    for (int& order: postOrder) cin >> order; 

    preOrder(0, n - 1, 0, n - 1);

    return 0;
}