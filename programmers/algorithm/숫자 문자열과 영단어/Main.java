import java.util.stream.*;

class Solution {
    public int solution(String s) {
        int len = s.length();
        int cur = 0;
        int answer = 0;
        
        while (cur < len) {
            answer *= 10;
            
            if (isNumeric(s.charAt(cur))) {
                // System.out.println("숫자 : " + Integer.valueOf(s.charAt(cur) - 48).intValue());
                answer += Integer.valueOf(s.charAt(cur) - 48).intValue();
                
                ++cur;
            } else {
                StringBuilder sb = new StringBuilder();
                int pointer = cur;
                
                while (pointer < len && !isNumeric(s.charAt(pointer))) {
                    sb.append(s.charAt(pointer));
                    ++pointer;
                    
                    if (Digit.fromString(sb.toString()) != null) break;
                }
                // System.out.println("문자 : " + Digit.fromString(sb.toString()).getNumber());
                
                answer += Digit.fromString(sb.toString()).getNumber();
                cur = pointer;
            }
        }
        
        return answer;
    }
    
    private boolean isNumeric(char c) {
        return '0' <= c && c <= '9';
    }
    
    private enum Digit {
        ZERO("zero", 0),
        ONE("one", 1),
        TWO("two", 2),
        THREE("three", 3),
        FOUR("four", 4),
        FIVE("five", 5),
        SIX("six", 6),
        SEVEN("seven", 7),
        EIGHT("eight", 8),
        NINE("nine", 9)
        ;
        
        private String str;
        private int number;
        
        private Digit(String str, int number) {
            this.str = str;
            this.number = number;
        }
        
        private int getNumber() {
            return this.number;
        }
        
        public static Digit fromString(String str) {
            return Stream.of(values())
                .filter(v -> v.str.equals(str))
                .findFirst()
                .orElse(null);
        }
    }
}