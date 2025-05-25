import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> queue = new LinkedList<>();
        List<Integer> answer = new ArrayList<>();

        for (int i = 0; i < progresses.length; i++) {
            if ((100 - progresses[i]) % speeds[i] == 0) {
                queue.offer((100 - progresses[i]) / speeds[i]);
            } else {
                queue.offer(((100 - progresses[i]) / speeds[i]) + 1);
            }
        }

        int now = queue.poll();
        int count = 1;

        while (!queue.isEmpty()) {
            if (now >= queue.peek()) {
                count++;
                queue.poll();
            } else {
                answer.add(count);
                count = 1;
                now = queue.poll();
            }
        }
        answer.add(count);

        return answer.stream().mapToInt(i -> i).toArray();
    }
}