import java.util.*;

class Solution {
    // 음식 N개 (1 <= N <= 2,000) -> 1 <= N <= 200,000
    // 1 <= foodTime <= 1,000 -> 1 <= foodTime <= 100,000,000
    // 방송이 잠시 중단된 시간 : 1 <= k <= 2,000,000 -> 1 <= k <= 2*10^13
    
    // 1부터 차례로 음식 먹음(1초간 먹고 남김) -> 마지막 번호 먹으면 다시 1번 회전
    // 음식 하나 1초 동안 섭취 -> 남은 음식 두고, 다음 음식(남은 음식 중, 가장 가까운 번호의 음식) 섭취 (이동 시간 무시)
    // 반환: 네트워크 장애 이후 몇 번 음식부터 다시 섭취? (없으면 -1)
    
    // 회전 횟수 = k / N
    // 불가능: food_times MAX 값 < k
    // 큐에 작은 시간 음식순으로 삽입 -> (누적값 - 최소 시간) >= 0인 값이 나오면 q.size()로 음식 개수 체크?
    
    // 그냥 모든 값을 라운드 횟수 만큼 지워버리고, 남은 횟수만큼 순회하면서 양수인 값 찾으면 되는 거 아님?
//     public int solution(int[] food_times, long k) {
//         int[] foodTimes = food_times.clone();
        
//         long n = (long) food_times.length;
//         long minRound = k / n; // 최소 회전 횟수(= 시간)
//         long remainRound = (minRound == 0) ? k % (n * minRound) : (int) k; // 잔여 회전 횟수
//         System.out.println("최소 회전 횟수 = " + minRound + ", 잔여 회전 횟수 = " + remainRound);
        
//         int cnt = 0, lastIdx = -1;
//         for (int i=0; i<food_times.length; ++i) {
//             long time = (long) food_times[i];
//             System.out.println("시간 = " + time);
            
//             if (minRound >= time) continue;
//             ++cnt;
            
//             System.out.println("생존 가능");
            
//             if (cnt == remainRound) {
//                 System.out.println("마지막으로 먹은 음식 번호: " + i);
//                 lastIdx = i; // 마지막으로 먹은 음식 번호
//                 break;
//             }
//         }
        
//         int answer = -1;
//         if (lastIdx != -1) {
//             for (int i=0; i<food_times.length; ++i) {
//                 long time = (long) food_times[i];
                
//                 if (minRound+1 >= time) continue;
//                 else {
//                     answer = i+1;
//                     break;
//                 }
//             }
//         }
        
//         return answer;        
//     }
    
    public int solution(int[] food_times, long k) {
        PriorityQueue<Food> pq = new PriorityQueue<>((a, b) -> (a.time != b.time) ? a.time - b.time : a.id - b.id); // 정렬 순서: 시간 > 번호
        
        long n = food_times.length;
        long totalTime = 0;
        for (int i=0; i<(int)n; ++i) {
            pq.offer(new Food(i+1, food_times[i]));
            totalTime += food_times[i];
        }
        if (totalTime <= k) return -1; // 반드시 남지 않는 경우
        
        long total = 0, pre = 0;
        while (total + (pq.peek().time - pre) * n <= k) { // (누적 경과 시간 + (가장 작은 시간 - 이전 식사 시간) * 남은 음식 수) <= k
            int now = pq.poll().time;
            total += (now - pre) * n;
            n--;
            pre = now;
        }
        
        List<Food> filter = new ArrayList<>();
        while (!pq.isEmpty()) filter.add(pq.poll());
        Collections.sort(filter, (a, b) -> a.id - b.id);
        
        int remainRound = (int) ((k - total) % n);
        
        return filter.get(remainRound).id;
    }
    
    private static class Food {
        public int id, time;
        
        public Food(int id, int time) {
            this.id = id;
            this.time = time;
        }
    }
}