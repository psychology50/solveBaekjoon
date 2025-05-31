class Solution {
    private static int[] dy = {-1,0,1,0};
    private static int[] dx = {0,1,0,-1};

    public int solution(String dirs) {
        boolean[][][] visited = new boolean[11][11][4];
        int y = 5, x = 5, d = 0;
        int answer = 0;

        for (char c : dirs.toCharArray()) {
            if (c == 'U') d = 0;
            if (c == 'R') d = 1;
            if (c == 'D') d = 2;
            if (c == 'L') d = 3;

            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= 11 || nx < 0 || nx >= 11) continue;
            if (!visited[ny][nx][d]) {
                visited[ny][nx][d] = true;
                visited[y][x][(d + 2) % 4] = true;
                answer++;
            }
            y = ny;
            x = nx;
        }

        return answer;
    }
}