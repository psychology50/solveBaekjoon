#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define INF 1e9

using namespace std;
int n, plusCnt, multipleCnt;
vector<int> numbers;
int ret = 0;

void dfs(int cnt, int val, vector<int> pickers) {
    // for (int i=0; i<pickers.size(); ++i) {
    //     cout << pickers[i] << " ";
    // }
    // cout << endl;

    if (cnt == 0) {
        ret = max(ret, val * accumulate(pickers.begin(), pickers.end(), 0));
        // cout << "ret = " << ret << endl;
        return;
    }

    // 순열 생성
    vector<int> permutation(pickers.size());
    for (int i = 0; i < permutation.size(); ++i) permutation[i] = i;

    // 각 그룹에는 적어도 하나의 원소가 포함되어 있어야 한다.
    for (int pickCnt = 1; pickCnt < pickers.size() - cnt + 1; ++pickCnt) {
        // 순열에서 pickCnt개 선택하는 조합 생성
        vector<int> comb(pickers.size());
        fill(comb.begin(), comb.end(), -1);
        // pickCnt개 만큼 0으로 초기화
        for (int i = 0; i < pickCnt; ++i) {comb[i] = 0;}
        
        do {
            for (int i=0; i<pickers.size(); ++i) if (comb[i] == 0) comb[i] = permutation[i];

            // 원소 삭제를 위해 정렬해야 함 -> 복사본 생성
            vector<int> indexes;
            for (int i=0; i<pickers.size(); ++i) if (comb[i] != -1) indexes.push_back(comb[i]);

            cout << "순열 --> ";
            for (int i=0; i<pickCnt; ++i) {
                cout << indexes[i] << " ";
            }
            cout << endl;
            vector<int> tmp = pickers;
            int tmpSum = 0;
            for (int& idx: indexes) {
                tmpSum += tmp[idx];
            }
            
            // index 큰 값부터 삭제 (에러 방지)
            sort(indexes.begin(), indexes.end(), greater<>());
            for (int& idx: indexes) {
                tmp.erase(tmp.begin() + idx);
            }
            dfs(cnt - 1, val * tmpSum, tmp);
        } while (next_permutation(comb.begin(), comb.end())); // 순열 조합 생성
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; numbers.resize(n);
    for (int i = 0; i < n; ++i) cin >> numbers[i];
    cin >> plusCnt >> multipleCnt;

    dfs(multipleCnt, 1, numbers);
    cout << ret;

    return 0;
}