#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

bool cmp(vi& a, vi& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    int last = -40000;
    for (vi& route : routes) {
        int start = route[0], end = route[1];
        if (start <= last && last <= end) continue;
        
        last = end;
        ++answer;
    }
    
    return answer;
}