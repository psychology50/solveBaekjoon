#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// 처리 시간이 적은 심사자가 가장 많이 처리하도록
ll solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    int sz = times.size(); // 입국 심사자 전체 수
    
    // 입국자수/심사자수 = 처리량
    // 최소 처리 시간, 최대 처리 시간
    ll l = 1, r = 1e18;
    
    ll ret = 0;
    while (l <= r) {
        ll mid = (l + r) / 2; // (입국자수/심사자수) * 평균처리시간
        
        ll sum = 0;
        for (int& time : times)
            sum += mid/(ll)time; // 처리량
        
        if (sum >= n) { // 처리량이 과하면, 빠른 심사관에게 더 할당 
            r = mid-1;
            ret = mid; // 상한선
        } else { // 처리량이 부족하면, 느린 심사관에게 더 할당
            l = mid+1; 
        }
    }
    
    return ret;
}