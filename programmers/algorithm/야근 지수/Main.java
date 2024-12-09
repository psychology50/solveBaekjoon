import java.util.*;

class Solution {
    // 야근 피로도 = (남은 일의 각 작업량)^2 의 합
    // 1 <= n <= 1,000,000 (퇴근까지 남은 시간)
    // 1 <= works.length <= 20,000 
    // 1 <= works[i] <= 50,000 (남은 일의 작업량)
    // 가장 큰 값을 제거하면 끝남.
    public long solution(int n, int[] works) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for (int i=0; i<works.length; ++i) {
            pq.offer(works[i]);
        }
        
        while (n > 0) {
            Integer value = pq.poll();
            
            if (value == 0) {
                break;
            }
            
            pq.offer(value - 1);
            --n;
        }
        
        long answer = 0;
        
        while (!pq.isEmpty()) {
            Integer value = pq.poll();
            
            answer += Math.pow(value, 2);
        }
        
        return answer;
    }
}