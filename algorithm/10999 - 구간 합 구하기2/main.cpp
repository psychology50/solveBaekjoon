#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

#define endl "\n";
using namespace std;

long long arr[1000010];
vector<long long> Lazy;  // Lazy Propagation 기억 장치
vector<long long> SegTree;
vector<tuple<int, int, int, long long>> Ctrl;

void inputInfo(int* n, int* m, int* k) {
    cin >> *n >> *m >> *k;
    for (int i=0; i<*n; i++) cin >> arr[i];
    for (int i=0; i<*m+*k; i++) {
        int a, b, c; 
        long long d;

        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            Ctrl.push_back({a, b, c, d});
        } else {
            cin >> b >> c;
            Ctrl.push_back({a, b, c, -1});
        }
    }
}

int calc_size_tree(int n) {
    int height = (int)ceil(log2(n));
    int size = (1 << (height + 1));

    return size;
}

long long create_tree(int left, int right, int idx) {
    if (left == right) return SegTree[idx] = arr[left];
    
    int mid;
    mid = (left + right) / 2;
    SegTree[idx] = create_tree(left, mid, idx*2+1) + create_tree(mid+1, right, idx*2+2);
    return SegTree[idx];
}

void lazyUpdate(int idx, int start, int end) {
    if (Lazy[idx] != 0) {
        SegTree[idx] += (end - start + 1) * Lazy[idx];
        if (start != end) {
            Lazy[idx * 2 + 1] += Lazy[idx];
            Lazy[idx * 2 + 2] += Lazy[idx];
        }
        Lazy[idx] = 0;
    }
}

void updateTree(int start, int end, int idx, int left, int right, long long value) {
    lazyUpdate(idx, start, end);
    
    if (right < start || end < left) return; // exception handling
    if (left <= start && end <= right) { // lazy propagation에서는 인덱스가 넘어가는 순간 업데이트 진행. 그 전까진 보류한다.
        SegTree[idx] += (end - start + 1) * value;
        if (start != end) {
            Lazy[idx * 2 + 1] += value;
            Lazy[idx * 2 + 2] += value;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateTree(start, mid, idx*2+1, left, right, value);
    updateTree(mid+1, end, idx*2+2, left, right, value);
    SegTree[idx] = SegTree[idx * 2 + 1] + SegTree[idx * 2 + 2];
}

long long Query(int start, int end, int idx, int left, int right) {
    lazyUpdate(idx, start, end);

    if (right < start || end < left) return 0; // exception handling
    if (left <= start && end <= right) return SegTree[idx];

    int mid = (start + end) / 2;
    long long left_value = Query(start, mid, idx*2+1, left, right);
    long long right_value = Query(mid+1, end, idx*2+2, left, right);
    return left_value + right_value;
}

void solution(int n, int m, int k) {
    int flag, left, right; 
    for (int i=0; i < m+k; i++) {
        flag = get<0>(Ctrl[i]);
        left = get<1>(Ctrl[i]) - 1;
        right = get<2>(Ctrl[i]) - 1;

        if (flag == 1) {
            long long value = get<3>(Ctrl[i]);
            updateTree(0, n-1, 0, left, right, value);
        } else {
            cout << Query(0, n-1, 0, left, right) << endl;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    inputInfo(&n, &m, &k);

    int treeSize = calc_size_tree(n);
    SegTree.resize(treeSize);
    Lazy.resize(treeSize);
    create_tree(0, n-1, 0);

    solution(n, m, k);

    return 0;
}