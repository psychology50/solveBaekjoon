import java.util.*;

class Solution {
    private int playTime, advTime;
    // private int[][] viewLogs;
    
    public String solution(String play_time, String adv_time, String[] logs) {
        playTime = convertTimeToSec(play_time);
        advTime = convertTimeToSec(adv_time);
        int[] ad = new int[360000]; // playtime 길어봐야 356,400 + a
        
        for (String log : logs) {
            String[] interval = log.split("-");
            
            int from = convertTimeToSec(interval[0]);
            int to = convertTimeToSec(interval[1]);
            
            for(int j=from; j<to; j++) { // 초단위로 재생 기록 수 체크
				++ad[j];
			}
        }
        
        int maxIdx=0;
		long maxSum=0;
		long sum =0;
        
		for(int i=0; i<advTime; i++) { // [00:00:00 ~ 광고 시간)까지 누적합 계산
			sum += ad[i];
		}
		maxSum = sum;
		
		for(int i = advTime; i<playTime; ++i) {
			sum += ad[i] - ad[i-advTime]; // 1초씩 이동하면서 최대 누적합 계산
            
			if(sum > maxSum) {
				maxSum = sum;
				maxIdx = i - advTime + 1;
			}
		}
		
		return convertTimeToString(maxIdx);
    }
    
//     // 전체 재생 구간(play_time) (00:00:01 <= 시간 <= 99:59:59)
//     // 공익광고 재생 길이(adv_time)
//     // 시청 구간 (logs) (1 <= 길이 <= 300,000)
//     // 결과: 누적 재생 시간이 가장 많이 나오는 공익광고가 들어갈 가장 빠른 시작 시각
//     public String solution(String play_time, String adv_time, String[] logs) {
//         playTime = convertTimeToSec(play_time);
//         advTime = convertTimeToSec(adv_time);
        
//         viewLogs = new int[logs.length][2];
//         for (int i=0; i<logs.length; ++i) {
//             String[] interval = logs[i].split("-");
            
//             viewLogs[i][0] = convertTimeToSec(interval[0]);
//             viewLogs[i][1] = convertTimeToSec(interval[1]);
//         }
//         Arrays.sort(viewLogs, (a, b) -> (a[0] != b[0]) ? a[0] - b[0] : a[1] - b[1]);
        
//         // 가장 빠른 로그 시간에 잡아도 시간 초과하는 경우
//         if (viewLogs[0][0] + advTime >= playTime) 
//             return convertTimeToString(viewLogs[0][0] - (viewLogs[0][0] + advTime - playTime));
        
//         // 결과치 계산을 위한 변수
//         int maxCnt = 1;
//         String answer = convertTimeToString(viewLogs[0][0]);
        
//         Queue<int[]> q = new ArrayDeque<>();
//         int curTime = viewLogs[0][0]; // 현재 시각을 가장 빠른 로그 시작 시간으로 잡음
        
//         // 탐색하다가 광고 타임이 영상 재생 시간 넘긴 경우 처리 필요
//         for (int i=0; i<viewLogs.length; ++i) {
//             int[] log = viewLogs[i];
            
//             if (q.peek() == null || isInScope(curTime, log[0])) { // q가 비어있거나, 광고 범위 내의 시간이 접근하면 q 삽입
//                 // System.out.println(convertTimeToString(curTime) + "에서 " + convertTimeToString(log[0]) + " 포함 가능");
//                 q.offer(log);
                
//                 if (q.size() > maxCnt) {
//                     answer = convertTimeToString(curTime);
//                     maxCnt = Math.max(maxCnt, q.size());
//                 }
                
//                 continue;
//             }
            
//             // 광고 범위를 벗어났다면, 가장 앞의 로그를 차례로 빼면서 curTime 조정
//             while (true) {
//                 q.poll();
                
//                 if (q.isEmpty()) {
//                     // System.out.println("더 이상 제외할 값이 없으므로, start를 " + convertTimeToString(curTime) + "으로 수정");
//                     curTime = log[0]; // 더 이상 제외할 수 없으면, 새로운 로그로 curTime 옮겨서 반복문 끝냄.
//                     q.offer(log);
                    
//                     int cnt = 0;
//                     for (int j=i-1; j>=0 && viewLogs[j][1] > curTime; --j) {
//                         ++cnt;
//                     } 
                    
//                     if (q.size() + cnt > maxCnt) {
//                         answer = convertTimeToString(curTime);
//                         maxCnt = Math.max(maxCnt, q.size() + cnt);
//                     }
                    
//                     break;
//                 }
                
//                 curTime = q.peek()[0]; // 다음으로 빠른 로그로 시작 시간 옮김
//                 if (isInScope(curTime, log[0])) {
//                     // System.out.println("최대값 탐색 : " + curTime);
//                     q.offer(log);
                    
//                     int cnt = 0;
//                     for (int j=i-1; j>=0 && viewLogs[j][1] > curTime; --j) {
//                         ++cnt;
//                     } 
                    
//                     if (q.size() + cnt > maxCnt) {
//                         answer = convertTimeToString(curTime);
//                         maxCnt = Math.max(maxCnt, q.size() + cnt);
//                     }
//                 }
//             }
//         }
        
//         return answer;
//     }
    
    // private boolean isInScope(int curTime, int logStartTime) {
    //     return curTime + advTime > logStartTime; // 광고 종료시각이랑 완전히 동일하면..??
    // }
    
    private int convertTimeToSec(String time) {
        String[] part = time.split(":");
        
        int result = Integer.parseInt(part[2]);
        result += Integer.parseInt(part[1]) * 60;
        result += Integer.parseInt(part[0]) * 3600;
        
        return result;
    }
    
    private String convertTimeToString(int time) {
        StringBuilder sb = new StringBuilder();
        int tmp = time;

        int hour = time / 3600;
        int min = (time % 3600) / 60;
        int sec = (time % 3600 % 60);
        
        if (hour / 10 == 0) sb.append("0");
        sb.append(hour).append(":");
        
        if (min / 10 == 0) sb.append("0");
        sb.append(min).append(":");
        
        if (sec / 10 == 0) sb.append("0");
        sb.append(sec);
        
        return sb.toString();
    }
}