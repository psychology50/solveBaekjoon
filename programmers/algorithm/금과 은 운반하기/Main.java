import java.util.*;
import java.math.*;

// MAX 값 결정이 중요.
// Long.MAX_VALUE로 하면, sumG, sumS, sumTotal을 int로 잡을 시 Overflow
class Solution {
    public long solution(int a, int b, int[] g, int[] s, int[] w, int[] t) {
        int N = g.length;
        long left = 0, right = (long) 10e14 * 4; // 최악: (옮겨야 하는 금&은 양) * (한 번에 옮길 수 있는 양) + 편도 시간
        long answer = Long.MAX_VALUE;
        
        while (left <= right) {
            long mid = (left + right) / 2;
            int sumG = 0, sumS = 0, sumTotal = 0;
            
            for (int i=0; i<N; ++i) {
                long possibleMoveCnt = mid / (t[i] * 2);
                if (mid % (t[i] * 2) >= t[i]) {
                    ++possibleMoveCnt;
                }
                
                long maxWeight = possibleMoveCnt * w[i];
                
                sumG += Math.min(g[i], maxWeight);
                sumS += Math.min(s[i], maxWeight);
                sumTotal += Math.min(g[i] + s[i], maxWeight);
            }
            
            if (sumG >= a && sumS >= b && sumTotal >= a+b) {
                right = mid - 1;
                answer = Math.min(answer, mid);
            } else {
                left = mid + 1;
            }
        }
        
        return answer;
    }
}