#include <iostream>
#include <cmath>

#define MAX 100001

using namespace std;
int n, m;
int lecture[MAX];
int maxLesson = 0;

int getBluerayCnt(int minSize) {
    int sum = 0, cnt = 0;
    for (int i=0; i<n; ++i) {
        sum += lecture[i];
        if (sum > minSize) {
            --i;
            sum = 0;
            ++cnt;
        }
    }
    return cnt;
}


int binarySearch() {
    int l = maxLesson, r = 1000000000;

    while (l <= r) {
        int mid = (l + r) / 2; // 최소 블루레이 크기
        int cnt = getBluerayCnt(mid); // 구한 블루레이 개수

        if (cnt < m) { // 최소 크기를 너무 크게 잡은 경우
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> lecture[i];
        maxLesson = max(maxLesson, lecture[i]);
    }
    cout << binarySearch();

    return 0;
}