class Solution {
    // 1 <= N <= 2,000 (응답완료시간(2016-09-15) S, 처리 시간(최대 소수점 셋째자리까지 + 뒤에 's') T 공백 구분)
    // 0.001 <= T <= 3.000 (S 기준 오름차순 정렬)
    // 반환: 초당 최대 처리량 (처리량/s)
    public int solution(String[] lines) {
        Double[][] logs = parseLogs(lines);
        
        int answer = 0;
        
        for (int i=0; i<logs.length; ++i) {
            Double term = logs[i][1] + 0.999;

            int count = 1;
            for (int j=i+1; j<logs.length; ++j) {
                if (logs[j][0] >= term) continue;
                ++count;
            }
            
            answer = Math.max(answer, count);
        }
        
        return answer;
    }
    
    private Double[][] parseLogs(String[] lines) {
        Double[][] logs = new Double[lines.length][2];
        
        for (int i=0; i<lines.length; ++i) {
            String[] times = lines[i].split(" ");
        
            String[] finishTime = times[1].split(":");
            double S = 0;
            S += Double.parseDouble(finishTime[0]) * 3600;
            S += Double.parseDouble(finishTime[1]) * 60;
            S += Double.parseDouble(finishTime[2]);
            
            double T = Double.parseDouble(times[2].split("s")[0]);
            double start = S - T;
            
            // System.out.println("S : " + S + ", T = " + T + " ==> start = " + start);
            
            logs[i][0] = Double.valueOf(start);
            logs[i][1] = Double.valueOf(S);
        }
        
        return logs;
    }
}