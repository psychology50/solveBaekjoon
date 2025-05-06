class Solution {
    // 가로 >= 세로
    public int[] solution(int brown, int yellow) {
        int width = yellow + 2, height = 3;
        int yw = yellow, yh = 1;
        
        while (brown != 2 * (width + height) - 4) {
            while (true) {
                yw = yellow / ++yh;
                
                if (yellow == yw * yh) break; 
            }
            
            width = yw + 2;
            height = yh + 2;
        }
        
        return new int[]{width, height};
    }
}