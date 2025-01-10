class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        int idx1 = 0;
        int idx2 = 0;
        
        for (String currentStr : goal) {
            if (idx1 < cards1.length && currentStr.equals(cards1[idx1])) {
                idx1++;
            } else if (idx2 < cards2.length && currentStr.equals(cards2[idx2])) {
                idx2++;
            } else {
                return "No";
            }
        }
        
        return "Yes";
    }
}