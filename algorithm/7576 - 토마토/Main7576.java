import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.Entry;

public class Main7576 {
    int[][] graph;
    boolean[][] visited;
    private Entry<Integer, Integer> pair;
    Queue<Entry<Integer, Integer>> q = new LinkedList<>();
    List<Entry<Integer, Integer>> vector = new ArrayList<>(
            Arrays.asList(new AbstractMap.SimpleEntry<>(1, 0),
                          new AbstractMap.SimpleEntry<>(0, 1),
                          new AbstractMap.SimpleEntry<>(-1, 0),
                          new AbstractMap.SimpleEntry<>(0, -1)));

    int tomato(int n, int m) {
        int cnt = q.size(), day = 0;

        while (!q.isEmpty()) {
            pair = q.poll(); cnt--;
            int y = pair.getKey();
            int x = pair.getValue();
            for (Entry<Integer, Integer> tmp : vector) {
                int nxt_y = y + tmp.getKey();
                int nxt_x = x + tmp.getValue();
                if ((0<=nxt_y && nxt_y<n)&&(0<=nxt_x && nxt_x<m)&&!visited[nxt_y][nxt_x]) {
                    visited[nxt_y][nxt_x] = true;
                    if (graph[nxt_y][nxt_x] == -1) continue;
                    q.add(new AbstractMap.SimpleEntry<>(nxt_y, nxt_x));
                }
            }
            if (cnt == 0 && !q.isEmpty()) {
                cnt = q.size();
                day++;
            }
        }
        for (int i=0; i < n; i++) for (int j=0; j<m; j++)
            if (visited[i][j] == false) return -1;

        return day;
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        graph = new int[n][m]; visited = new boolean[n][m];
        for (int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<m; j++) {
                visited[i][j] = false;
                graph[i][j] = Integer.parseInt(st.nextToken());
                if (graph[i][j] == 1) {
                    visited[i][j] = true;
                    q.add(new AbstractMap.SimpleEntry<>(i, j));
                } else if (graph[i][j] == -1) {
                    visited[i][j] = true;
                }
            }
        }
        System.out.println(tomato(n, m));
    }

    public static void main(String[] args) throws Exception {
        new Main7576().solution();
    }
}
