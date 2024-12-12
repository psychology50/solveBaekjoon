import java.util.*;

class Solution {
    // 1 <= N <= 1,000,000
    // "I (숫자)" : 큐에 (숫자) 삽입
    // "D 1" : 큐에서 최댓값 삭제 (없으면 무시, 둘 이상이면 하나만 삭제)
    // "D -1" : 큐에서 최소값 삭제 
    // 결과: [최댓값, 최솟값] (비어있으면 [0, 0])
    public int[] solution(String[] operations) {
        LinkedList<Integer> queue = new LinkedList<>();
        
        for (int i=0; i<operations.length; ++i) {
            String[] operation = operations[i].split(" ");
            
            String command = operation[0];
            Integer value = Integer.parseInt(operation[1]);
            
            // System.out.println("command: " + (command.equals("I") ? "삽입" : "제거") + " --> value : " + value);
            
            if (command.equals("I")) {
                if (queue.isEmpty()) {
                    queue.offer(value);
                    continue;
                }
                
                Integer maxValue = queue.getFirst();
                Integer minValue = queue.getLast();
                
                if (value >= maxValue) { // max보다 같거나 크면 앞에 삽입
                    queue.offerFirst(value);
                } else if (value <= minValue) { // min보다 같거나 작으면 뒤에 삽입
                    queue.offerLast(value);
                } else { // max > value > min인 경우, 삽입할 위치 탐색
                    int left = 0, right = queue.size();
                    int mid = 0;
                    
                    while (left < right) {
                        mid = (left + right) / 2;
                        
                        Integer cur = queue.get(mid);
                        
                        if (cur > value) {
                            right = mid - 1;
                        } else {
                            left = mid + 1;
                        }
                    }
                    
                    queue.add(mid, value);
                }
            } else {
                if (value.equals(1)) {
                    queue.pollFirst();
                } else {
                    queue.pollLast();
                }
            }
        }

        int[] answer = new int[2];
        
        if (queue.isEmpty()) return answer;
        
        answer[0] = queue.getFirst();
        answer[1] = queue.getLast();
        
        return answer;
    }
}