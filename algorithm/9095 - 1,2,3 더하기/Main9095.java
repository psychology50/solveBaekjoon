import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main9095 {
	private int n;
	
	private int dfs(int depth, int sum) {
		if (sum > n) return 0;
		if (depth == n || sum == n) return 1;

		int result = 0;
		for (int i = 1; i <= 3; i++) {
			result += dfs(depth+1, sum+i);
		}
		
		return result;
	}
	
	public void solution() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		for (int i=0; i<t; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());

			System.out.println(dfs(0, 0));
		}
		
	}
	
	public static void main(String[] args) throws Exception{
		new Main9095().solution();
	}
}
