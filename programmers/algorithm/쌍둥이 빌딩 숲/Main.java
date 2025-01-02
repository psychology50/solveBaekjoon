import java.util.*;

class Solution {
    private static final int MOD = 1_000_000_007;
    private static int[][] cache;
    
    // 높이 n인 빌딩 수 2n개 (1 <= n <= 100)
    // 구분 가능한 수 count (1 <= count <= n)
    // 반환: 가능한 빌딩 배치 수 % MOD (단, 같은 높이 빌딩 사이에는 더 큰 빌딩이 존재할 수 없고, 같은 높이 빌딩은 구분 x)
    
    // (1) count == n이면, 언제나 1
    // (2) count == n-1이면, n 1개, n-1 자율 배치
    // (3) count == n-2이면, ... 이렇게 되면 블럭이 몇 개든 규칙이 동일함.
    // 규칙은 n과 count 사이의 관계. => 틀림..n=4면, 11224433 11334422 22334411 22113344도 되므로, 경우의 수가 증가함.
    // n 우선 배치 -> 1씩 줄이면서 배치?
    
    // (n, c) = n개 쌍 건물에, c개의 건물이 보이는 경우
    // (0, 0) = 1 
    // (1, 1) = 1
    // (2, 1) = 2,  (2, 2) = 1
    // (3, 1) = 8,  (3, 2) = 6,  (3, 3) = 1
    // (4, 1) = 48, (4, 2) = 44, (4, 3) = 12, (4, 4) = 1
    // count가 1일 때, (n, 1) = (n-1, 1) * 2(n-1)
    
    // 점화식: (n, c) = (n-1, c-1) + (n-1, c) * 2(n-1)
    //  - (n-1, c-1): n 건물을 보이도록 
    //  - (n-1, c) * 2(n-1): 
    public int solution(int n, int count) {
        cache = new int[n+1][n+1];
        for (int[] row: cache) Arrays.fill(row, -1);
        for (int i=0; i<=n; ++i) {
            cache[i][0] = 0;
            for (int c=i+1; c<=n; ++c) cache[i][c] = 0;
        }
        cache[0][0] = cache[1][1] = 1;
        
        return dfs(n, count);
    }
    
    private int dfs(int n, int c) {
        if (cache[n][c] != -1) return cache[n][c];
        
        long sum = dfs(n-1, c-1);
        sum += (long) dfs(n-1, c) * 2 * (n-1);
        
        return cache[n][c] = (int) (sum % MOD);
    }
}