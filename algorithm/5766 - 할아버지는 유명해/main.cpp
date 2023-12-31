#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (true) {
        cin >> n >> m;
        if (!n && !m) return 0; 

        map<int, int> ranking;
        vector<int> secondRanker, result;
        int first = 0, second = 0;
        
        for (int i = 0, tmp; i < n*m; ++i) {
            cin >> tmp;
            ++ranking[tmp];
        }

        for (auto ranker : ranking) first = max(first, ranker.second);
        for (auto ranker : ranking) if (ranker.second != first) {
            second = max(second, ranker.second);
        }
        for (auto ranker : ranking) if (ranker.second == second) {
            cout << ranker.first << " ";
        }
        cout << "\n";
    }
    
    return 0;
}