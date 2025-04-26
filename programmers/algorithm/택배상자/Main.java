import java.util.*;

class Solution {
    // 상자가 트레일따라 1~n번 차례로 넘어옴 (queue)
    // 맨 앞 상자가 현재 실어야 할 순서 아니면? 잠시 다른 곳에 보관 (보조 컨테이너 벨트, stack 구조)
    //
    public int solution(int[] order) {
        int lastIdx = 0;
        
        Deque<Integer> subTrailer = new ArrayDeque<>();
        
        for (int cur=1; cur<=order.length; ++cur) {
            if (cur != order[lastIdx]) { // 트레일러 상자가 현재 필요한 거 아니면 종료
                // System.out.println(cur + "를 서브 트레일러에 저장");
                subTrailer.add(cur);
                continue;
            }
            
            if (++lastIdx == order.length) break; // 박스 다 넣었으므로 종료
            if (order[lastIdx] > cur) continue; // 더 큰 숫자 필요해서 stack 뒤져볼 이유 없음.
            
            while (!subTrailer.isEmpty() && order[lastIdx] < cur) {
                int number = subTrailer.pollLast().intValue();
                
                if (number != order[lastIdx]) { // 창고 조회 실패 -> 즉시 종료
                    // System.out.println("서브 트레일러 top의 " + number + "과(와) 타겟 " + order[lastIdx] + " 미스 매치");
                    return lastIdx;
                }
                
                // System.out.println("서브 트레일러에서 " + number + " 꺼냄");
                ++lastIdx;
            } 
        }
        
        return lastIdx;
    }
}