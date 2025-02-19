class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        
        int a = x / 10000;
        int b = (x / 1000) % 10;
        int c = (x / 100) % 10;
        int d = (x / 10) % 10;
        int e = x % 10;
    
        int sum = a + b + c + d + e;
    
        if(x % sum != 0)
            answer = false;
        
        return answer;
    }
}