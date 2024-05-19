class Solution {
    private int[][] map;
    private int[] answer = {0, 0};
    
    public int[] solution(int[][] arr) {
        map = arr;
        divide(0, 0, arr.length);
        
        return answer;
    }
    
    private void divide(int row, int col, int length) {
        int start = map[row][col];
        boolean flag = false;
        
        for (int y=0; y<length; ++y) {
            for (int x=0; x<length; ++x) {
                if (map[row + y][col + x] != start) {
                    flag = true;
                    break;
                }
            }
            
            if (flag) break;
        }
    
        if (flag) {
            divide(row, col, length/2);
            divide(row+length/2, col, length/2);
            divide(row, col+length/2, length/2);
            divide(row+length/2, col+length/2, length/2);
        } else {
            ++answer[start];
        }
    }
}