import java.util.*;

// top-down은 경우의 수가 너무 많음. bottom-up으로 스캔?
// 하나하나 끊어보는 건 연산량 너무 방대함 -> 이분 탐색이라면?
class Solution {
    private static final int MAX_SIZE = 10001;
    private int N = 0;
    private int K = 0;
    private int groupCount = 0;
    
    private boolean[] visited = new boolean[MAX_SIZE];
    private int[] degree = new int[MAX_SIZE];
    private int[] participant = new int[MAX_SIZE];
    
    private Map<Integer, List<Integer>> graph = new HashMap<>();
    
    public int solution(int k, int[] num, int[][] links) {
        N = num.length;
        K = k;
        System.arraycopy(num, 0, participant, 0, N);

        int left = 0;
        int right = 0;
        
        for (int i=0; i<N; ++i) {
            left = Math.max(left, num[i]);
            right += num[i];
            
            for (int j=0; j<2; ++j) if (links[i][j] != -1) {
                if (graph.get(i) == null) {
                    graph.put(i, new ArrayList(2));
                }
                
                graph.get(i).add(links[i][j]); // 하위 노드 관계 파악
                ++degree[links[i][j]]; // 하위 노드 깊이 +1
            }
        }
        
        int root = searchRootIndex();
        // System.out.println("<<DEBUG>> root = " + root);
        
        return binarySearch(root, left, right);
    }
    
    private int searchRootIndex() {
        for (int i=0; i<N; ++i) {
            if (degree[i] == 0) {
                return i;
            }
        }
        
        throw new IllegalStateException("루트 노드가 존재하지 않습니다.");
    }
    
    // 초기 left: 가장 큰 단일 원소 값(하한선), 초기 right: 모든 원소의 합. 
    // left < right가 아닐 때까지 분할
    private int binarySearch(int root, int left, int right) {
        int l = left;
        int r = right;
        
        int groupSize = 0; // 원소의 합
        
        while (l < r) {
            // System.out.println("<<DEBUG>> left = " + l + ", right = " + r);
            
            for (int i=0; i<N; ++i) { // 방문 초기화
                visited[i] = false;
            }
            groupCount = 0; // 그룹 개수 초기화
            
            groupSize = (l + r) / 2;
            dfs(root, groupSize);
            
            // System.out.println("<<DEBUG>> groupCount = " + groupCount + ", groupSize = " + groupSize);
            
            if (groupCount < K) { // 더 나눌 수 있다면, 상한선을 낮춤
                r = groupSize;
            } else { // 더 나눌 수 없다면, 하한선을 높임
                l = groupSize + 1;
            }
        }
        
        return r;
    }
    
    // 순회하면서 기준값보다 크면 잘라냄. (자르는 횟수 최소화하려면?)
    // 분할된 개수를 카운트
    private int dfs(int node, int limitSize) {
        visited[node] = true;
        
        if (graph.get(node) == null) { // 기저 사례에선 탈출
            return participant[node];
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); // 큰 놈부터 자르려면 역전해야 할까?
        
        int sum = 0;
        int sumSubTree = 0;
        
        for (Integer nxt: graph.get(node)) {
            if (!visited[nxt]) {
                sumSubTree = dfs(nxt, limitSize); // bottom-up으로 sub tree의 max값 계산
                // System.out.println(node + "의 next(=" + nxt + ")의 값 = " + sumSubTree);
                sum += sumSubTree;
                // System.out.println("sum = " + sum);
                
                pq.offer(sumSubTree);
            }
        }
        
        while (!pq.isEmpty() && sum + participant[node] > limitSize) { // 한계점을 넘어섰다면
            // System.out.println(node + " 위치에서 값이 " + (sum+participant[node]) + "이므로 분리");
            ++groupCount; // 분할 개수 +1
            sum -= pq.poll();
            // System.out.println("분리된 값 = " + (sum+participant[node]));
        }
        
        return sum + participant[node];
    }
}