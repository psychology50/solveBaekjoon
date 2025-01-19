import java.util.*;

class Solution {
    // 방 (처음엔 모두 빈 방): (1 <= k <= 10^12) 1,000,000,000,000
    // 고객이 원하는 방: 1 <= room_number.length <= 200,000
    // 1 <= room_number[i] <= k
    // 방 채우기 규칙 (단, 언제나 가능한 경우만 제공)
    // 1. 한 번에 한 명씩, 신청 순서대로
    // 2. 방이 비어있으면, 투숙 원하는 방에 즉시 배정
    // 3. 방이 비어있지 않으면, 번호 더 큰데, 비어있는 방중 가장 작은 방 배정
    // 반환: 배정된 방 번호 배열
    
    // 방문 배열을 만들 수 없음. bit 연산도 불가.
    // Set -> 반복문 : 효율성 테스트 시간초과
    // while 돌면서, 이미 지나온 경로는 다시 검사 안 하도록 최적화
    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];
        HashMap<Long, Long> allocated = new HashMap<>(); // 현재 방, 다음으로 작은 방 번호
        
        for (int i=0; i<room_number.length; ++i) {
            List<Long> visited = new ArrayList<>();
            long room = room_number[i];
            
            while (allocated.getOrDefault(room, -1L) != -1L) { // 이미 누가 점유 중이면
                visited.add(room); // 현재 방문한 방 번호들 전부 수집
                room = allocated.get(room); // 다음 최적화 방으로 빠르게 이동
            }
            visited.add(room);
            
            for (Long visit: visited) {
                allocated.put(visit, room+1); // 지나온 방들의 최적 정보를 모두 갱신
            }            
            
            answer[i] = room;
        }
        
        return answer;
    }
}