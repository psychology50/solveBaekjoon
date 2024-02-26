#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
using pii = pair<int, int>;

// +, -, *, /
int solution(int N, int number) {
    if (N == number) return 1;
    
    vector<unordered_set<int>> cache(9);

    int cur = N;
    for (int k=1; k<=8; ++k) {
        cache[k].insert(cur);
        cur = cur*10 + N;
    }
    
    for (int cntA = 1; cntA <= 8; ++cntA) for (int cntB = 1; cntB <= 8; ++cntB) {
        int k = cntA + cntB;
        if (k > 8) continue;
        for (int a : cache[cntA]) for (int b : cache[cntB]) {
            cache[k].insert(a + b);
            cache[k].insert(a - b);
            cache[k].insert(a * b);
            if (b != 0)
                cache[k].insert(a / b);
        }
    }
    
    for (int k=1; k<=8; ++k) {
        if (cache[k].find(number) != cache[k].end()) return k;
    }
    return -1;
}