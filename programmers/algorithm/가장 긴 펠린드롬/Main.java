class Solution
{
    // 가장 긴 팰린드롬 찾기
    // 1 <= N <= 2,500 (소문자만)
    // 무식하게 해도 2500 * 2500..할만 하겠는데?
    public int solution(String s)
    {
        int answer = 1;

        // "aba", "abba"
        for (int mid=0; mid<s.length()-1; ++mid) {
            // System.out.println("mid = " + s.charAt(mid));
            
            if (s.charAt(mid) == s.charAt(mid+1)) { // 짝수 탐색 가능하면
                int left = mid, right = mid+1;
                
                while (0 <= left && right < s.length()) {
                    if (s.charAt(left) != s.charAt(right)) break;
                
                    answer = Math.max(answer, right-left+1);
                    // System.out.println("left = " + left + ", right = " + right + " --> 길이: " + (right-left+1));
                    --left;
                    ++right;
                }
            }
            
            int left = mid-1, right = mid+1;
            while (0 <= left && right < s.length()) {
                if (s.charAt(left) != s.charAt(right)) break;
                
                answer = Math.max(answer, right-left+1);
                // System.out.println("left = " + left + ", right = " + right + " --> 길이: " + (right-left+1));
                --left;
                ++right;
            }
        }

        return answer;
    }
}