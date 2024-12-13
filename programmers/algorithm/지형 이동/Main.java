import java.util.*;

class Solution {
    private static final int MAX_DIFF = 50000;
    private int N = 0;
    private static final int[][] dydx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private int[][] scc;
    private List<Edge>[] bridges; // 인접 리스트로 변경
    private int[] nodes;
    
    // land[i][j]: (i, j)의 높이 (1 <= H <= 10,000)
    // 4 <= N <= 300
    // 이동 조건: |현재 칸 - 이동 칸| <= height
    //  만약 |현재 칸 - 이동 칸| > height면, 사다리 설치 -> 설치 비용 = |현재 칸 - 이동 칸|
    // 반환 값: 사다리 설치 비용 최소화
    //
    // (1) bfs -> 모든 정점에서 시작해서 bfs? 사다리 재활용은?
    // (2) 이동 가능한 그룹 묶기? -> 인접한 그룹은 어떻게 판단? 그룹 사이 최소 사다리 비용은 어떻게 판단? 다른 그룹과 연결되어 있다면?
    // 아이디어 (SCC)
    //  - 사다리 설치 없이 이동 가능한 구역 묶기. (bfs)
    //  - 구역 간에 사다리 최소 설치 비용 탐색 
    //      - ex. 1<->2 (5), 2<->3(10), 1<->3(-1) (단, -1은 이동 불가) ==> 최소 비용 15
    //      - ex. 1<->2 (8), 2<->3(19), 1<->3(10) => 최소 비용 1<->2 && 1<->3 (18)
    public int solution(int[][] land, int height) {
        N = land.length;
        
        int maxGroupNum = makeSCC(land, height);
        if (maxGroupNum == 0) return 0;
        
        // 인접 리스트 초기화
        bridges = new List[maxGroupNum + 1];
        for (int i = 0; i <= maxGroupNum; i++) {
            bridges[i] = new ArrayList<>();
        }
        
        connectBridge(land, maxGroupNum);
        return calcMinCost(maxGroupNum);
    }
    
    private int makeSCC(int[][] land, int height) {
        Deque<int[]> q = new ArrayDeque<>();  // LinkedList 대신 ArrayDeque 사용
        scc = new int[N][N];
        int groupNum = 0;
        
        for (int[] row : scc) {
            Arrays.fill(row, -1);
        }
        
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (scc[row][col] != -1) continue;
                
                q.offer(new int[]{row, col});  // Node 객체 대신 int[] 사용
                scc[row][col] = groupNum;
                
                while (!q.isEmpty()) {
                    int[] cur = q.poll();
                    
                    for (int[] d : dydx) {
                        int ny = cur[0] + d[0];
                        int nx = cur[1] + d[1];
                        
                        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                        if (scc[ny][nx] != -1) continue;
                        if (Math.abs(land[cur[0]][cur[1]] - land[ny][nx]) > height) continue;
                        
                        scc[ny][nx] = groupNum; // 큐에 넣고 계산하지 말고, 처음부터 걸러내야 함.
                        q.offer(new int[]{ny, nx});
                    }
                }
                groupNum++;
            }
        }
        
        return groupNum - 1;
    }
    
    private void connectBridge(int[][] land, int maxGroupNum) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                for (int[] d : dydx) {
                    int ny = row + d[0], nx = col + d[1];
                    
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                    if (scc[row][col] == scc[ny][nx]) continue;
                    
                    int cost = Math.abs(land[row][col] - land[ny][nx]);
                    addEdge(scc[row][col], scc[ny][nx], cost);
                }
            }
        }
    }
    
    private void addEdge(int from, int to, int cost) {
        // 이미 있는 엣지인지 확인하고 더 작은 비용으로 업데이트
        for (Edge edge : bridges[from]) {
            if (edge.to == to) {
                edge.cost = Math.min(edge.cost, cost);
                return;
            }
        }
        bridges[from].add(new Edge(to, cost));
        bridges[to].add(new Edge(from, cost));
    }
    
    private int calcMinCost(int maxGroupNum) {
        nodes = new int[maxGroupNum + 1];
        for (int i = 0; i <= maxGroupNum; i++) {
            nodes[i] = i;
        }
        
        // 모든 엣지를 비용순으로 정렬
        PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> a.cost - b.cost);
        for (int i = 0; i <= maxGroupNum; i++) {
            for (Edge edge : bridges[i]) {
                if (i < edge.to) {  // 중복 방지
                    pq.offer(new Edge(i, edge.to, edge.cost));
                }
            }
        }
        
        int answer = 0;
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            if (!matchParent(edge.from, edge.to)) {
                answer += edge.cost;
                unionParent(edge.from, edge.to);
            }
        }
        
        return answer;
    }
    
    private boolean matchParent(int a, int b) {
        return findParent(a) == findParent(b);
    }
    
    private void unionParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a < b) nodes[b] = a;
        else nodes[a] = b;
    }
    
    private int findParent(int cur) {
        if (nodes[cur] == cur) return cur;
        return nodes[cur] = findParent(nodes[cur]);
    }
    
    private static class Edge {
        int to, cost;
        int from;  // from은 필요한 경우에만 사용
        
        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
        
        Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }
}