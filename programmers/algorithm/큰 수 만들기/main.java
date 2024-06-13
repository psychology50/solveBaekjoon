import java.util.*;

class Solution {
    public String solution(String number, int k) {
        StringBuilder sb = new StringBuilder();
        
        char[] numbers = number.toCharArray();
        
        for (int idx=0, start=0; idx < number.length() - k; ++idx) {
            char max = '0';
            for (int section = start; section <= idx+k; ++section) {
                if (numbers[section] > max) {
                    max = numbers[section];
                    start = section + 1;
                }
            }
            sb.append(Character.toString(max));
        }
        
        return sb.toString();
    }
}