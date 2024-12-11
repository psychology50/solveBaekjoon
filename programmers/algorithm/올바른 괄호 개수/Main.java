import java.util.*;

class Solution {
    // (1) 재귀문으로 n개쌍으로 만들 수 있는 괄호 문자열 조합 생성
    // (2) Stack으로 O(N) 시간 복잡도로 판단
    private int answer = 0;
    
    public int solution(int n) {
        recur(n-1, n, "(");
        
        return answer;
    }
    
    private void recur(int left, int right, String cur) {
        if (left == 0 && right == 0) {
            if (cur.substring(cur.length() - 1).equals("(")) return;
            
            isValid(cur);
            return;
        }
        
        if (left != 0) recur(left-1, right, cur + "(");
        if (right != 0) recur(left, right-1, cur + ")");
    }
    
    private void isValid(String str) {
        Stack<String> stk = new Stack<>();
        for (int i=0; i<str.length(); ++i) {
            String token = String.valueOf(str.charAt(i));
            
            if (stk.isEmpty()) {
                if (token.equals(")")) return;
                else {
                    stk.add(token);
                    continue;
                }
            } else {
                if (token.equals("(")) {
                    stk.add(token);
                } else {
                    stk.pop();
                }
            }
        }
        
        if (stk.isEmpty()) ++answer;
    }
}