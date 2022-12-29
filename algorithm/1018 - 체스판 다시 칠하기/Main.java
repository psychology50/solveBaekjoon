import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	private int check_position(int nbr, int is_even) {
		return (is_even == 0) ? nbr / 2 : nbr / 2 + 1;
	}
	
	private boolean is_valid(int nb1, int nb2) {
		if (nb1 > nb2) {
			if (nb1 == (nb2 + 1) && nb1 % 2 == 0) { return true; }
		} else { 
			if (nb2 == (nb1 + 1) && nb2 % 2 == 0) { return true; }
		}
		
		return false;
	}
	
	public void solution() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		//	StringBuilder sb = new StringBuilder();
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(st.nextToken());
		int kim = Integer.parseInt(st.nextToken());
		int han = Integer.parseInt(st.nextToken());

		int cnt = 1;
		while (!is_valid(kim, han)) {
			kim = check_position(kim, kim % 2);
			han = check_position(han, han % 2);
			cnt += 1;
		}
		
		// sb.append(data).append('\n');
		// System.out.println(sb); // sb에 출력할 것들을 모아서 출력
		
//		System.out.println(cnt);
		bw.write(cnt);
//		bw.newLine(); // 줄바꿈
//		bw.flush(); // 남아있는 데이터 모두 출력
//		bw.close();
	}
	
	public static void main(String[] args) throws Exception {
		new Main().solution();
	}
}