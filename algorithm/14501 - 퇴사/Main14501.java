import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Map.Entry;
import java.util.AbstractMap.SimpleEntry;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main14501 {
	private int n;
	private int result;
	
	private Entry<Integer, Integer> pair;
	private List<Entry<Integer, Integer>> paid = new ArrayList<>();
	
	private void dfs(int pay, int depth) {
		if (depth >= n) {
			result = Math.max(result, pay);
			return;
		}
		
		if (depth + paid.get(depth).getKey() <= n) {
			dfs(pay + paid.get(depth).getValue(), depth + paid.get(depth).getKey());
		} else {
			dfs(pay, depth + paid.get(depth).getKey());
		}
		dfs(pay, depth+1);
	}
	
	public void solution() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
	
		n = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int t = Integer.parseInt(st.nextToken());
			int p = Integer.parseInt(st.nextToken());
			
			pair = new SimpleEntry<>(t, p);
			paid.add(pair);
		}
		
		// 풀이 1번 : dfs
		result = 0;
		dfs(0, 0);
		
		// 풀이 2번 : dp
		int[] cache = new int[n+1];
		
		for (int i=0; i<n; i++) {
			if (i + paid.get(i).getKey() <= n)
				cache[i + paid.get(i).getKey()] = Math.max(cache[i + paid.get(i).getKey()], cache[i] + paid.get(i).getValue());
			cache[i+1] = Math.max(cache[i+1], cache[i]);
		}
		
		System.out.println(result);
		System.out.println(cache[n]);
	}
	
	public static void main(String[] args) throws Exception {
		new Main14501().solution();
	}
}
