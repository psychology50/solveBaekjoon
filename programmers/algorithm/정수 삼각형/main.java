class Solution {
    public int solution(int[][] triangle) {
        int[][] cache = new int[501][501];
        
        for (int i = 0; i < triangle[triangle.length-1].length; ++i) cache[triangle.length-1][i] = triangle[triangle.length-1][i];
        
        for (int row = triangle.length-2; row>=0; --row) {
            for (int col = 0; col < triangle[row].length; ++col) {
                int now = triangle[row][col];
                cache[row][col] = Math.max(now + cache[row+1][col+1], now + cache[row+1][col]);
            }
        }
        
        return cache[0][0];
    }
}