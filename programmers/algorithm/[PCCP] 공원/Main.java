class Solution {
    private static final int[][] dydx = {{-1, -1}, {-1, 0}, {0, -1}}; 
    
    public int solution(int[] mats, String[][] park) {
        int capacity = -1;
        
        int n = park.length;
        int m = park[0].length;
        int[][] cache = new int[n][m];
        
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            if (!park[i][j].equals("-1")) {
                cache[i][j] = -1;
                continue;
            }
            
            int maxAllow = Integer.MAX_VALUE;
            for (int k=0; k<3; ++k) {
                int ny = i + dydx[k][0];
                int nx = j + dydx[k][1];
                
                if (!(0 <= ny && ny < n && 0 <= nx && nx < m)) {
                    maxAllow = -1;
                    break;
                }
                
                maxAllow = Math.min(maxAllow, cache[ny][nx]);
            }
            
            cache[i][j] = (maxAllow == -1) ? 1 : maxAllow + 1;
            capacity = Math.max(capacity, cache[i][j]);
        }
        
        // for (int i=0; i<n; ++i) {
        //     for (int j=0; j<m; ++j) {
        //         System.out.print(cache[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        
        int answer = -1;
        for (int i=0; i<mats.length; ++i) if (mats[i] <= capacity) {
            answer = Math.max(answer, mats[i]);
        }
        
        return answer;
    }
}