#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int cache[1000000];
    int ret;
    
    cache[0] = money[0], cache[1] = money[0];
    for (int i=2; i<money.size()-1; ++i)
        cache[i] = max(cache[i-2]+money[i], cache[i-1]);
    
    ret = cache[money.size()-2];
    
    cache[0] = 0, cache[1] = money[1];
    
    for (int i=2; i<money.size(); ++i)
        cache[i] = max(cache[i-2]+money[i], cache[i-1]);
    
    return max(ret, cache[money.size() - 1]);
}