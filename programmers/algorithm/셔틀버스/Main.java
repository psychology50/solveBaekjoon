import java.util.*;

class Solution {
    // "09:00"부터 n회 t분 간격으로 셔틀 도착. 최대 m명씩 탑승 가능.
    // 가장 마지막에 셔틀 탈 수 있는 시각 (단, 크루 대기열의 가장 마지막에 탑승함에 주의.)
    // 0 < n <= 10
    // 0 < t <= 60
    // 0 < m <= 45
    // 크루 대기열 도착 시간: 1 <= timetable.length <= 2,000 ("HH:MM")
    // 콘이 현재 배차를 타야만 하는 경우: 가장 마지막 크루보다 1분 더 빨리 타면, 가장 늦게 탑승 가능
    // 콘이 현재 배차를 타지 않아도 되는 경우: 이전 배차를 타야 한다고 가정하고, 다음 배차 못 탈 거 같으면 패스. 가능하면 위 과정 갱신
    // 버스에 여유가 넘치면: 마지막 배차 시간이랑 똑같이 탑승
    public String solution(int n, int t, int m, String[] timetable) {
        List<Integer> times = new ArrayList<>();
        for (int i=0; i<timetable.length; ++i) {
            times.add(parseTimeToInt(timetable[i]));
        }
        Collections.sort(times);
        
        // System.out.println("times = " + times);
        
        int startMin = 9 * 60; // "09:00"부터 배차 시작 
        int subTotalSize = 0; // 각 시간대별 사람 수
        int lastMin = 0; // 콘이 타야하는 마지막 시점; "00:00"부터 시작
        
        // i=1에서 탑승하기로 했는데, i=2로 넘어가버리면??
        // => 그럼 애초에 버스 여유가 있었다는 의미.
        // => 만약 첫차 정시가 lastMin이었다가, i=2일 때 "09:10"이고, "09:01"인 크루가 m 이상이면, 어차피 "09:00"으로 맞춰짐.
        for (int i=0, crue=0; i<n; ++i) { // 버스 배차
            subTotalSize = 0;
            
            while (crue < times.size()) { // 한 명씩 탑승
                int currentMin = times.get(crue);
                
                if (currentMin <= startMin && subTotalSize < m) { // 현재 배차까지 탑승 중인 크루
                    ++subTotalSize;
                    ++crue;
                    lastMin = currentMin - 1; // 현재 크루의 1분 전에 탑승.
                } else break; // 도중에 꽉차거나, 현재 탈 수 없는 크루가 나오면 탈출
            }
            
            startMin += t; // 다음 배차로 이동 
        }
        
        if (subTotalSize < m) { // 여유가 있다면, 가장 마지막 배차 탑승
            lastMin = startMin - t; // 반복문 끝날 때 t 더해버려서, 한 번 빼줘야 함.
        }
        
        return parseIntToTime(lastMin);
    }
    
    private int parseTimeToInt(String time) {
        int hour = Integer.parseInt(time.substring(0,2)) * 60;
        int min = Integer.parseInt(time.substring(3,5));
        
        return hour + min;
    }
    
    private String parseIntToTime(int min) {
        return String.format("%02d", min / 60) + ":" + String.format("%02d", min % 60);
    }
}