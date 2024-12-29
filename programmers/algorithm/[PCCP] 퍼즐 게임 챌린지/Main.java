class Solution {
    private int N;
    // 1 <= diffs 길이 = times 길이 = n <= 300,000
    // 전체 제한시간: 1 <= limit <= 10^15
    // 반환: 제한 시간 내 퍼즐을 모두 해결하는 최소 숙련도 (level)
    
    // 퍼즐 난이도 diff
    // 퍼즐 소요 시간 time_cur
    // 이전 퍼즐 소요 시간 time_pre
    // 숙련도 level
    //  - diff <= level, time_cur 만큼 걸려서 해결
    //  - diff > level, time_prev * (diff - level) + time_cur <단, 다시 풀 때는 난이도 상관없이 틀리지 않음>
    public int solution(int[] diffs, int[] times, long limit) {
        N = diffs.length;
        
        int answer = 0;
        int left = 1, right = 300000;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (isValid(diffs, times, mid, limit)) {
                right = mid - 1;
                answer = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return answer;
    }
    
    private boolean isValid(int[] diffs, int[] times, int level, long limit) {
        int diff = 0, timePre = 0, timeCur = 0;
        long cnt = 0;
        
        for (int i=0; i<N; ++i) {
            diff = diffs[i];
            timeCur = times[i];
            
            if (diff <= level) {
                cnt += timeCur;
            } else {
                cnt += timeCur + ((timePre + timeCur) * (diff - level));
            }
            
            if (cnt > limit) return false;
            
            timePre = timeCur;
        }
        
        return true;
    }
}