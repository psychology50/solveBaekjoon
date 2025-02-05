import java.util.*;

class Solution {
    public String solution(String s, String skip, int index) {
        StringBuilder sb = new StringBuilder();
        
        Set<String> pass = new HashSet<>();
        for (int i=0; i<skip.length(); ++i) {
            pass.add(String.valueOf(skip.charAt(i)));
        }
        // System.out.println(pass);
        
        for (int i=0; i<s.length(); ++i) {           
            int bit = (int)s.charAt(i);
            int cnt = 0;
            
            while (true) {
                if (cnt == index) break;
                
                ++bit;
                if (bit > 122) {
                    bit = 97 + (bit - 122 - 1);
                }
                
                if (pass.contains(String.valueOf((char) bit))) {
                    continue;
                }
                
                ++cnt;
            }
            
            sb.append(String.valueOf((char) bit));
        }
        
        return sb.toString();
    }
}