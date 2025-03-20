import java.util.*;

class Solution {
    // m명 늘 때마다 서버 1대 증설 (증설하면 k시간 유지)
    //  - total < m : 증설 필요 x
    //  - n*m <= total < (n + 1)*m : 최소 n대 서버가 운영 중이어야 함.
    // 결과: 서버 최소 증설 횟수
    // 상태: [서버, 증설 시간] -> Queue<증설 시간>, size로 서버 대수 체크
    private Queue<Integer> q = new ArrayDeque<>();
    private int increaseCnt = 0;
    
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        
        for (int time=0; time<24; ++time) {
            int curUserCnt = players[time];
            
            decreaseServerIfNeeded(time, k);
            
            if (!isNeedIncreaseServer(curUserCnt, m)) continue;
            
            increaseServer(time, curUserCnt, m);
        }
        
        return answer = increaseCnt;
    }
    
    private boolean isNeedIncreaseServer(int curUserCnt, int m) {
        // System.out.println("현재 커버 가능한 사용자 수 : " + (m * (q.size() + 1)) + ", 현재 접속자 수: " + curUserCnt);
        return curUserCnt >= m * (q.size() + 1); 
    }
    
    private void decreaseServerIfNeeded(int curTime, int k) {
        while (!q.isEmpty()) {
            int serverTime = q.peek();
            
            if (serverTime + k > curTime) break;
            // System.out.println(curTime + "시간에 삭제된 서버가 증설된 시간 : " + serverTime);
            
            q.poll();
        }
    }
    
    private void increaseServer(int curTime, int curUserCnt, int m) {
        // 최소 필요 서버 수(n) * m <= curUserCnt < (n+1)*m -> n = curUserCnt/m - x(현재 서버 수)
        int needMoreCnt = curUserCnt / m - q.size();
        // System.out.println(curTime + "시간에 필요한 추가 서버 대수 = " + needMoreCnt);
        
        for (int i=0; i<needMoreCnt; ++i) q.add(curTime);
        
        increaseCnt += needMoreCnt;
    }
}