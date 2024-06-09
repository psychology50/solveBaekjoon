import java.io.*;
import java.util.*;

class StringWrapper implements Comparable<StringWrapper> {
    private final String str;

    public StringWrapper(String str) {
        this.str = str;
    }

    public String getStr() {
        return str;
    }

    @Override
    public int compareTo(StringWrapper tmp) {
        if (str.length() != tmp.getStr().length()) {
            return Integer.compare(str.length(), tmp.getStr().length());
        }
        return str.compareTo(tmp.getStr());
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        List<StringWrapper> result = new ArrayList<>();
        for (int i = 0; i<n; ++i) {
            st = new StringTokenizer(br.readLine());
            result.add(new StringWrapper(st.nextToken()));
        }
        Collections.sort(result);

        String cache = "";
        StringBuilder sb = new StringBuilder();
        for (StringWrapper s : result) {
            if (s.getStr().equals(cache)) continue;
            sb.append(s.getStr()).append("\n");
            cache = s.getStr();
        }

        System.out.println(sb);
    }
}
