class Solution {
    public int solution(int n) {
        int count = Integer.bitCount(n);
        int answer = n + 1;
        
        while (true) {
            if (count == Integer.bitCount(answer)) {
                break;
            }
            
            answer++;
        }
        
        return answer;
    }
}
