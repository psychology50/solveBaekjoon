import java.util.*;
import java.math.*;

class Solution {
    private static final int MAX_VALUE = 300001;
    private int N;
    
    private int[][] cache = new int[MAX_VALUE][2];
    private int[] salesCopy;
    private Map<Integer, List<Integer>> groups = new HashMap<>();
    
    public int solution(int[] sales, int[][] links) {
        N = sales.length;
        salesCopy = sales;

        for (int i=0; i < links.length; ++i) {
            if (groups.get(links[i][0]) == null) {
                groups.put(links[i][0], new ArrayList());
            }
            
            groups.get(links[i][0]).add(links[i][1]);
        }
        
//         for (Map.Entry<Integer, List<Integer>> entry : groups.entrySet()) {
//             System.out.print(entry.getKey() + "의 팀원 : ");
            
//             for (Integer v : entry.getValue()) {
//                 System.out.print(v + ", ");
//             }
//             System.out.println();
//         }
        
        dfs(1);
        
        return Math.min(cache[1][0], cache[1][1]); // 대표의 참석 여부
    }
    
    private void dfs(int cur) {
        cache[cur][0] = 0; // 불참하는 경우
        cache[cur][1] = salesCopy[cur-1]; // 참석하는 경우
        
        if (groups.get(cur) == null) {
            return;
        }
        int minValue = Integer.MAX_VALUE;
        
        for (int i=0; i<groups.get(cur).size(); ++i) {
            int nxt = groups.get(cur).get(i); 
            dfs(nxt);

            // System.out.println("현재 = " + cur + ", nxt = " + nxt);
            
            if (cache[nxt][0] < cache[nxt][1]) { // 밑에서 참여 안 했을 때, 비용이 더 적으면
                cache[cur][0] += cache[nxt][0];
                cache[cur][1] += cache[nxt][0];
                // 전체 매출액 = (cur 팀원이 나갈 경우 - cur 팀원이 나가지 않을 경우)
                minValue = Math.min(minValue, cache[nxt][1] - cache[nxt][0]);
            } else {
                cache[cur][0] += cache[nxt][1];
                cache[cur][1] += cache[nxt][1];
                minValue = 0; // 팀원이 팀장이 되어서 참여한 경우이므로 0
            }
            
            // System.out.println("참석 안 한 경우 = " + cache[cur][0]);
            // System.out.println("참석 한 경우 = " + cache[cur][0]);
            
        }
        
        cache[cur][0] += minValue; // 팀원 누구도 참여 못 한 경우 (팀원 최솟값)
    }
}