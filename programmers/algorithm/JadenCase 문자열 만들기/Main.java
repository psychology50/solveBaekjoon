import java.util.*;

class Solution {
    public String solution(String s) {
        s = s.toLowerCase();
        boolean check = true;
        StringBuilder sb = new StringBuilder();
        
        for (char c : s.toCharArray()) {
            if (c == ' ') {
                check = true;
            } else if (check) {
                c = Character.toUpperCase(c);
                check = false;
            }
            sb.append(c);
        }
                
        return sb.toString();
    }
}