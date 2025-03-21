class Solution {
    // 직원은 [출근 희망 시각 + 10분] 이내 출근해야 함. (토/일 제외)
    // 시간 표기법 = hour * 100 + min
    // 결과 상품을 받을 직원 수
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int answer = 0;
        
        for (int i=0; i<schedules.length; ++i) {
            int target = schedules[i];
            
            int curDate = startday;
            boolean youAreLate = false;
            for (int j=0; j<7; ++j, ++curDate) {
                if (curDate == 6) continue;
                if (curDate == 7) {
                    curDate = 0;
                    continue;
                }
                // System.out.println("사원 " + i + "번은 " + curDate + "번 째 날에 " + timelogs[i][j] + " 에 출근");
                
                if (isLate(target, timelogs[i][j])) {
                    // System.out.println("지각!");
                    youAreLate = true;
                    break;
                }
            }
            
            if (!youAreLate) ++answer;
        }
        
        return answer;
    }
    
    private boolean isLate(int target, int time) {
        return convertToTimestamp(time) > convertToTimestamp(target) + 10;
    }
    
    private int convertToTimestamp(int time) {
        return (time / 100) * 60 + (time % 100);
    }
}