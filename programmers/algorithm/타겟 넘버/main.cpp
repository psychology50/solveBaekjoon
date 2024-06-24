#include <string>
#include <vector>

using namespace std;
int n, ret = 0, t;

void dfs(int val, int depth, vector<int>& numbers) {
    if (depth == n) {
        if (val == t) ++ret;
        return;
    }
    
    dfs(val + numbers[depth], depth+1, numbers);
    dfs(val - numbers[depth], depth+1, numbers);
}

int solution(vector<int> numbers, int target) {
    n = numbers.size(); t = target;
    dfs(0, 0, numbers);
    return ret;
}