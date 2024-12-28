import java.util.*;

class Solution {
    // 1 <= N <= 500
    // 입력: {작업 요청 시점, 작업 소요 시간}
    // 우선 순위: 작업 소요 시간 > 작업 요청 시각 > 작업 번호}
    // 출력: 모든 요청 작업 반환 시간의 평균의 정수 부분
    // 반례: [[0, 10], [15, 3], [15, 2]] -> 추가로 더 받을 때, 15 둘 다 받아야 하는데, 하나만 받아버려서 5가 아니라, 6이 나옴
    public int solution(int[][] jobs) {
        Arrays.sort(jobs, (o1, o2) -> (o1[0] != o2[0]) ? o1[0] - o2[0] : o1[1] - o2[1]);
        
        int answer = 0;
        int curTime = 0;
        PriorityQueue<Job> pq = new PriorityQueue<>();
        pq.offer(new Job(0, jobs[0][0], jobs[0][1]));
        
        int id = 1;
        while (!pq.isEmpty() || id < jobs.length) {
            int lastJobAccessAt = 0;
            while (id < jobs.length) { // 현재 시간 이전에 요청된 작업들 대기 큐 삽입
                int[] requestJob = jobs[id];
                // System.out.println("id: " + id + ", 요청 시간 : " + requestJob[0] + ", 작업 소요 시간 : " + requestJob[1]);
                
                if (!pq.isEmpty() && lastJobAccessAt != requestJob[0] && requestJob[0] > curTime) break; // 대기 중인 작업이 있고, 아직 받을 수 없는 작업이면 패스
                pq.offer(new Job(id, jobs[id][0], jobs[id][1])); // 받을 수 있으면 대기 큐 삽입
                ++id;
                
                lastJobAccessAt = requestJob[0];
            }
            
            Job job = pq.poll();
            if (job.accessAt > curTime) curTime = job.accessAt; // 만약 현재 시간보다 이후 요청이면 curTime 갱신
            
            // System.out.println("현재 시간 : " + curTime);
            // System.out.println(job.id + "의 소요 시간: " + calcAverage(job, curTime));
            
            answer += calcAverage(job, curTime);
            curTime += job.processTime;
        }
        
        return answer / jobs.length;
    }
    
    private int calcAverage(Job job, int curTime) {
        return curTime - job.accessAt + job.processTime;
    }
    
    private static class Job implements Comparable<Job> {
        public int id; // 작업 번호
        public int accessAt; // 접근 시간
        public int processTime; // 작업 소요 시간
        
        public Job(int id, int accessAt, int processTime) {
            this.id = id;
            this.accessAt = accessAt;
            this.processTime = processTime;
        }
        
        @Override
        public int compareTo(Job job) {
            if (this.processTime != job.processTime) return this.processTime - job.processTime;
            else if (this.accessAt != job.accessAt) return this.accessAt - job.accessAt;
            else return this.id - job.id;
        }
    }
}