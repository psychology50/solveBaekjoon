import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main15649 {
	private static int n, m;
	private static int[] arr;
	private static boolean[] visited;
	
	private static StringBuilder sb = new StringBuilder();
	
	public void solution(int depth) throws Exception {
		if (depth == m) {
			for (int nbr : arr) {
				sb.append(nbr).append(" ");
			}
			sb.append("\n");
			return;
		}
		for (int idx = 0; idx < n; idx++) {
			if (!visited[idx]) {
				visited[idx] = true;
				arr[depth] = idx + 1;
				
				solution(depth + 1);
				
				visited[idx] = false;
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		arr = new int[m];
		visited = new boolean[n];
		
		new Main15649().solution(0);
		System.out.println(sb);
	}
}
