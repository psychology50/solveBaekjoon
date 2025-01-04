import java.util.*;

// 이걸로 안 풀림.
public class Solution {

    private static final String IMPOSSIBLE_MESSAGE = "IMPOSSIBLE";
    private static final String EMPTY = ".";

    private String[][] map;

    public String solution(int m, int n, String[] board) {
        StringBuilder answer = new StringBuilder();
        Queue<Tile> queue = new PriorityQueue<>();
        Map<String, List<Point>> tiles = new HashMap<>();

        map = new String[m][n];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length(); j++) {
                map[i][j] = String.valueOf(board[i].charAt(j));

                if (Character.isUpperCase(board[i].charAt(j))) {
                    List<Point> pointList = tiles.getOrDefault(map[i][j], new ArrayList<>());
                    pointList.add(new Point(i, j, map[i][j]));
                    tiles.put(map[i][j], pointList);
                }
            }
        }

        int priority = 0;
        int beforeQueueSize = -1;

        while (!tiles.isEmpty() && beforeQueueSize != queue.size()) {
            beforeQueueSize = queue.size();
            List<String> removableTileList = new ArrayList<>();
            for (String key : tiles.keySet()) {
                List<Point> pointList = tiles.get(key);
                Point point1 = pointList.get(0);
                Point point2 = pointList.get(1);

                if (isRemovable(point1, point2)) {
                    removableTileList.add(point1.name);
                }
            }

            if (removableTileList.size() == 0) {
                continue;
            }

            Collections.sort(removableTileList);

            String name = removableTileList.get(0);
            List<Point> pointList = tiles.get(name);
            Point point1 = pointList.get(0);
            Point point2 = pointList.get(1);
            removeTile(point1.x, point1.y);
            removeTile(point2.x, point2.y);

            queue.add(new Tile(point1.name, priority));
            tiles.remove(name);

            priority++;
        }

        if (tiles.size() != 0) {
            return IMPOSSIBLE_MESSAGE;
        }

        while (!queue.isEmpty()) {
            Tile tile = queue.poll();
            answer.append(tile.name);
        }

        return answer.toString();
    }

    private void removeTile(int x, int y) {
        map[x][y] = EMPTY;
    }

    private boolean isRemovable(Point point1, Point point2) {
        String name = point1.name;

        int startX = Math.min(point1.x, point2.x);
        int endX = Math.max(point1.x, point2.x);
        int startY = Math.min(point1.y, point2.y);
        int endY = Math.max(point1.y, point2.y);

        int position = checkPosition(point1, point2);

        if (position == 1) {
            return (checkWidth(name, startX, endX, startY) && checkLength(name, startY, endY, endX)) || (checkWidth(name, startX, endX, endY) && checkLength(name, startY, endY, startX));
        }

        return (checkWidth(name, startX, endX, startY) && checkLength(name, startY, endY, startX)) || (checkWidth(name, startX, endX, endY) && checkLength(name, startY, endY, endX));
    }

    private boolean checkWidth(String name, int startX, int endX, int y) {
        for (int i = startX; i <= endX; i++) {
            if (map[i][y].equals(EMPTY) || map[i][y].equals(name)) {
                continue;
            }

            return false;
        }

        return true;
    }

    private boolean checkLength(String name, int startY, int endY, int x) {
        for (int j = startY; j <= endY; j++) {
            if (map[x][j].equals(EMPTY) || map[x][j].equals(name)) {
                continue;
            }

            return false;
        }

        return true;
    }

    private int checkPosition(Point point1, Point point2) {
        if (point1.x <= point2.x && point1.y <= point2.y) {
            return 1;
        }

        return 2;
    }

    class Tile implements Comparable<Tile> {
        String name;
        int priority;

        public Tile(String name, int priority) {
            this.name = name;
            this.priority = priority;
        }

        @Override
        public int compareTo(Tile o) {
            if (this.priority == o.priority) {
                return this.name.compareTo(o.name);
            }

            return this.priority - o.priority;
        }
    }

    class Point {
        int x;
        int y;
        String name;

        public Point(int x, int y, String name) {
            this.x = x;
            this.y = y;
            this.name = name;
        }
    }
}