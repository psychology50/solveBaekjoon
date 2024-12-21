import java.util.*;

class Solution {
    Map<Integer, int[][]> card; // 각 숫자카드 좌표 Map
	 int n, result, R, C, order[][], map[][];
	 boolean used[];
	 int[] dr = { -1, 1, 0, 0 };
	 int[] dc = { 0, 0, -1, 1 };

	 int solution(int[][] board, int r, int c) {
		card = new HashMap<>();
		n = 0;
		R = r; // 시작좌표
		C = c;
		map = board;
		result = Integer.MAX_VALUE;

		// 각 카드별로 2개의 좌표 Map에 저장
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (board[i][j] != 0) {
                	// board[i][j]번 카드 중 첫 번째 카드
					if (!card.containsKey(board[i][j])) {
						card.put(board[i][j], new int[2][]);
						card.get(board[i][j])[0] = new int[] { i, j };
						n++;
					} 
                    // board[i][j]번 카드 중 두 번째 카드
                    else
						card.get(board[i][j])[1] = new int[] { i, j };
				}
			}

		order = new int[2 * n][];
		used = new boolean[n + 1];
		dfs(0);

		return result;
	}

	 // 카드 뒤집을 순열 생성
	 void dfs(int cnt) {
		if (cnt == n) {
			// order 배열대로 카드를 뒤집어 최솟값 갱신
			result = Integer.min(result, findCard());
			return;
		}

		for (int i = 1; i <= n; i++) {
			if (!used[i]) {
				used[i] = true;
				
                // 첫 번째 카드 -> 두 번째 카드 순으로 뒤집기
				order[cnt * 2] = card.get(i)[0];
				order[cnt * 2 + 1] = card.get(i)[1];
				dfs(cnt + 1);

				// 두 번째 카드 -> 첫 번째 카드 순으로 뒤집기
				order[cnt * 2] = card.get(i)[1];
				order[cnt * 2 + 1] = card.get(i)[0];
				dfs(cnt + 1);

				used[i] = false;
			}
		}
	}

	 // order대로 카드를 뒤집어가며 BFS를 사용해 비용 계산
	int findCard() {
		// map 복사
		int[][] copy = new int[4][4];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				copy[i][j] = map[i][j];

		int[] start = { R, C, 0 };
		int cost = 0;
		
		// order순열에서 다음 좌표를 뽑아가며 탐색
		for (int[] next : order) {
			Queue<int[]> q = new ArrayDeque<>();
			boolean[][] visited = new boolean[4][4];
			q.offer(start);
			visited[start[0]][start[1]] = true;

			while (!q.isEmpty()) {
				int[] cur = q.poll();
				int r = cur[0];
				int c = cur[1];
				int w = cur[2];

				// 목표 좌표까지 도달했으면 비용 +1(뒤집는 비용) 후 cost에 누적
				if (r == next[0] && c == next[1]) {
					cost += w + 1;
					copy[next[0]][next[1]] = 0;
					break;
				}

				// 일반 커서 옮기기
				for (int d = 0; d < 4; d++) {
					int nr = r + dr[d];
					int nc = c + dc[d];

					if (nr < 0 || nc < 0 || nr == 4 || nc == 4)
						continue;

					if (!visited[nr][nc]) {
						visited[nr][nc] = true;
						q.offer(new int[] { nr, nc, w + 1 });
					}
				}

				// Ctrl 커서 옮기기
				for (int d = 0; d < 4; d++) {
					int nr = r;
					int nc = c;

					while (true) {
						// 경계 벗어나면 이전값 넣기
						if (nr + dr[d] < 0 || nc + dc[d] < 0 || nr + dr[d] == 4 || nc + dc[d] == 4) {
							if (!visited[nr][nc]) {
								visited[nr][nc] = true;
								q.offer(new int[] { nr, nc, w + 1 });
							}
							break;
						}
						nr += dr[d];
						nc += dc[d];

						// 제일 가까운 카드 만나면 해당 좌표 넣기
						if (copy[nr][nc] != 0) {
							if (!visited[nr][nc]) {
								visited[nr][nc] = true;
								q.offer(new int[] { nr, nc, w + 1 });
							}
							break;
						}
					}
				}
			}

			// 목표로 했던 좌표를 시작점으로 세팅
			start[0] = next[0];
			start[1] = next[1];
			start[2] = 0;
		}

		return cost;
	}
}