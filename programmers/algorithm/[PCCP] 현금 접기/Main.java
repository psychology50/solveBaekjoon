class Solution {
    // 1. 항상 길이가 긴 쪽을 반으로 접는다.
    // 2. 접기 전 길이가 홀수라면, 접은 후 소수점 이하는 버린다.
    // 3. 90도 돌려서 넣을 수도 있다.
    // 반환: 지갑에 넣기 위한 접는 최소 횟수
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        int[] money = bill.clone();
        
        while (true) {
            if ((money[0] <= wallet[0] && money[1] <= wallet[1]) || (money[1] <= wallet[0] && money[0] <= wallet[1])) {
                break;
            }
            
            int bigIdx = (money[0] >= money[1]) ? 0 : 1;
            money[bigIdx] = money[bigIdx] / 2;
            ++answer;
        }
        
        return answer;
    }
}