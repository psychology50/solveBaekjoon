class Solution {
    public int solution(int n, int a, int b)
    {
        int round = 1;
        int target1 = (a < b) ? a : b;
        int target2 = (a < b) ? b : a; // 언제나 A < B 보장.

        while (true) {
            if (target1 == target2-1 && target1 % 2 == 1) {
                break;
            }
            
            target1 = calcNextNumber(target1);
            target2 = calcNextNumber(target2);
            ++round;
        }

        return round;
    }
    
    private int calcNextNumber(int cur) {
        return (cur % 2 == 1) ? (cur+1) / 2 : cur / 2;
    }
}