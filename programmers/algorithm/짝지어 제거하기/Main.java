import java.util.*;

class Solution {
    public int solution(String s) {
        Deque<Character> stack = new ArrayDeque<>();

        for (int i = 0; i < s.length(); ++i) {
            if (stack.isEmpty()) {
                stack.add(s.charAt(i));
                continue;
            }
            
            char ch = s.charAt(i);

            if (stack.peekLast() == ch) {
                stack.pollLast();
            } else {
                stack.add(ch);
            }
        }
        
        return stack.isEmpty() ? 1 : 0;
    }
}