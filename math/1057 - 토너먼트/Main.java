import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
//	private ArrayList<Integer> board = new ArrayList<Integer>(51);
	
//	public int count(char start, int row, int col, String[] board) {
//		int cnt = 0;
//			
//		return cnt; 
//	}
	
	public void solution() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
//		int answer = Integer.MAX_VALUE;
		ArrayList<Integer> answer = new ArrayList<Integer>();
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		String board[] = new String[n];
		for (int i = 0; i < n; i++) board[i] = br.readLine();
		
		for (int i = 0; i < n-7; i++) {
			for (int j = 0; j < m-7; j++) {
				int white = 0, black = 0;
				
				for (int row = i; row < i+8; row++) {
					for (int col = j; col < j+8; col++) {
						if (((row + col) % 2) == 0) {
							if (board[row].charAt(col) != 'W') 
								white += 1;
							else 
								black += 1;
						} else {
							if (board[row].charAt(col) != 'B') 
								white += 1;
							else 
								black += 1;
						}
					}
				}
				answer.add(Math.min(white, black));
			}
		}
		System.out.println(Collections.min(answer));
	}
	
	public static void main(String[] args) throws Exception {
		new Main().solution();
	}
}
