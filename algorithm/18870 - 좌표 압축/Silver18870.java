// @author 21911407 양재서
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private int n;
    int[] origin;

    private void input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        origin = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i=0; i<n; ++i) {
            origin[i] = Integer.parseInt(st.nextToken());
        }
    }

    public void solution() throws Exception {
        input();

        int[] copyArr = origin.clone();
        Arrays.sort(copyArr);

        Map<Integer, Integer> comp = new HashMap<>();
        int tmp = -1;
        for (int key : copyArr) if (!comp.containsKey(key)) {
            comp.put(key, ++tmp);
        }

        StringBuilder sb = new StringBuilder();
        for (int key : origin) {
            sb.append(comp.get(key)).append(" ");
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
