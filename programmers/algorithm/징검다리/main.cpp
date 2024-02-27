#include <string>
#include <vector>
#include <algorithm>

#define MAX 1000000000

using namespace std;
int sink;

int binarySearch(int l, int r, vector<int>& rocks, int target) {  
    int ret = 0;
    
    while (l <= r) {
        int m = (l + r) >> 1;
        
        int dist = 0, pre = 0, rollback = 0, cnt = 0, rollbackCnt = 1;
        for (int& rock : rocks) {
            dist = rock - pre;
            
            if (dist == 0) {
                pre = rollback;
                dist = rock - pre;
                ++rollbackCnt;
            }
            
            if (dist < m) { 
                ++cnt;
                rollbackCnt = 1;
            } 
            else { 
                rollback = pre;
                pre = rock; 
            }
        }
        
        // 뒤에 깨지 못 한 돌 전부 카운트해야 함.
        if (sink - pre < m) {
            cnt += rollbackCnt;
        }
        
        if (cnt > target) {
            r = m - 1;
        } else {
            ret = max(ret, m);
            l = m + 1;
        }
    }
    return ret;
}

int solution(int distance, vector<int> rocks, int n) {
    sink = distance;
    sort(rocks.begin(), rocks.end());
    return binarySearch(0, distance, rocks, n);
}