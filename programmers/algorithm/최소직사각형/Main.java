class Solution {
    public int solution(int[][] sizes) {
        
        int max_row = 0;
        int max_col = 0;
        
        for(int i=0;i<sizes.length;++i){
            if(sizes[i][0]<sizes[i][1]){
                int tmp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = tmp;
            }
            if(max_row<sizes[i][0]) max_row = sizes[i][0];
            if(max_col<sizes[i][1]) max_col = sizes[i][1];
        }
        
        return max_col*max_row;
    }
}