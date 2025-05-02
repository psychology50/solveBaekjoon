class Solution {
    public int solution(int n) {
        int answer = 0;
        
        int sum=1;
        int left=1, right=1;
        while (left <= n) {
            if (sum < n) {
                sum += ++right;
            } else {
                if (sum == n) ++answer;
                
                sum -= left++;
            }
        }
        
        return answer;
    }
}