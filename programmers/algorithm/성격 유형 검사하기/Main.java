import java.util.*;

class Solution {
    private int[] evaluation = new int[8];
    
    public String solution(String[] survey, int[] choices) {
        for (int i=0; i < survey.length; ++i) {
            String s = survey[i];
            
            Character pre = Character.fromString(String.valueOf(s.charAt(0)));
            Character pos = Character.fromString(String.valueOf(s.charAt(1)));
            System.out.println("<DEBUG> pre : " + pre + ", pos : " + pos);
            
            inputCredit(pre, pos, choices[i]);
        }
        
        return calcResult();
    }
    
    private void inputCredit(Character pre, Character pos, int choice) {
        if (choice < 4) {
            evaluation[pre.getIndex()] = evaluation[pre.getIndex()] + (4 - choice);
        }
        
        if (choice > 4) {
            evaluation[pos.getIndex()] = evaluation[pos.getIndex()] + (choice - 4);
        }
    }
    
    private String calcResult() {
        String answer = "";
        
        for (int i=0; i<8; i += 2) {
            int pre = evaluation[i];
            int pos = evaluation[i+1];

            Character c;
            if (pre >= pos) {
                c = Character.fromIndex(i);
            } else {
                c = Character.fromIndex(i+1);                
            }
            
            System.out.println("<<DEBUG>> pre : " + pre + ", pos : " + pos + " -> select : " + c);
            
            answer += c.getAlphabet();
        }
        
        return answer;
    }
    
    private enum Character {
        RION("R", 0), TUB("T", 1),
        CON("C", 2), FRODO("F", 3),
        JAIJI("J", 4), MOOZI("M", 5),
        APEACH("A", 6), NEO("N", 7)
        ;
        
        private String alphabet;
        private int index;
        
        Character(String alphabet, int index) {
            this.alphabet = alphabet;
            this.index = index;
        }
        
        public static Character fromString(String character) {
            for (Character c : values()) {
                if (c.getAlphabet().equals(character)) {
                    return c;
                }
            }
            throw new IllegalArgumentException("존재하지 않는 타입입니다.");
        }
        
        public static Character fromIndex(int index) {
            for (Character c : values()) {
                if (c.getIndex() == index) {
                    return c;
                }
            }
            throw new IllegalArgumentException("존재하지 않는 인덱스 입니다.");
        }
        
        public String getAlphabet() {
            return this.alphabet;
        }
        
        public int getIndex() {
            return this.index;
        }
    }
}