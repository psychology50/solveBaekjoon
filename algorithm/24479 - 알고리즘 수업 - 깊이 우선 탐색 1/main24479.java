import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main24479 {
	ArrayList<Integer>[] graph;
	int[] visited;
	int cnt = 0;
	
	void dfs(int node) {
		visited[node] = ++cnt;
		
		for (int nxt : graph[node]) {
			if (visited[nxt] != 0) continue;
			dfs(nxt);
		}
	}
	
	public void solution() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()); 
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken()) - 1;
		graph = new ArrayList[n];
		visited = new int[n];
		
		for (int i=0; i<n; i++) {
			graph[i] = new ArrayList<Integer>();
			visited[i] = 0;
		}
		for (int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			
			int u = Integer.parseInt(st.nextToken()) - 1;
			int v = Integer.parseInt(st.nextToken()) - 1;
			graph[u].add(v);
			graph[v].add(u);
		}
		for (int i=0; i<n; i++) Collections.sort(graph[i]);
		
		dfs(r);
		for (int i=0; i<n; i++) sb.append(visited[i]).append("\n");
		System.out.println(sb);
	}
	
	public static void main(String[] args) throws Exception {
		new Main24479().solution();
	}
}
