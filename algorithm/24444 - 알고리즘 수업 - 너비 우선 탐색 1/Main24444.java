import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main24444 {
    ArrayList<Integer>[] graph;
    int[] visited;
    int cnt = 0;

    void bfs(int start) {
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(start);
        visited[start] = ++cnt;

        while (!q.isEmpty()) {
            int now = q.poll();
            for (int nxt : graph[now]) {
                if (visited[nxt] == 0) {
                    visited[nxt] = ++cnt;
                    q.add(nxt);
                }
            }
        }
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n];
        visited = new int[n];

        for (int i=0; i<n; i++) {
            graph[i] = new ArrayList<Integer>();
            visited[i] = 0;
        }
        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken())-1;
            int v = Integer.parseInt(st.nextToken())-1;
            graph[u].add(v); graph[v].add(u);
        }
        for (int i=0; i<n; i++) Collections.sort(graph[i]);

        bfs(r-1);
        for (int i=0; i<n; i++) sb.append(visited[i]).append("\n");
        System.out.println(sb);
    }

    public static void main(String[]args) throws Exception {
        new Main24444().solution();
    }
}
