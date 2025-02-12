class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 1;          
        int start = section[0];        
        
        for (int item : section) {            
            if (start + m > item) {                
                continue;            
            }                        
            start = item;            
            answer++;        
        }                
        
        return answer;
    }
}