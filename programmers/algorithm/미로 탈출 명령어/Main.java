import java.util.*;

class Solution {
    private static final String[] order = {"d", "l", "r", "u"};
    private static final Map<String, int[]> dydx = Map.of(
        "l", new int[]{ 0, -1}, // 좌 2
        "r", new int[]{ 0,  1}, // 우 3
        "u", new int[]{-1,  0}, // 상 4
        "d", new int[]{ 1,  0} // 하 1
    ); // 가능하다면 {아래, 좌, 우, 상} 순서로 이동.
    private static final String IMPOSSIBLE = "impossible";
    
    private static int N, M;
    
    // [미로 탈출 조건]
    // 1. 격자 바깥 이동 불가
    // 2. 출발점(x, y) -> 도착점(r, c) 이동 거리 총 k (같은 격자 중복 방문 가능)
    // 3. 탈출 경로는 사전 순 빠른 경로
    
    // 2 <= n, m < 50, 1 <= k <= 2,500 
    // 무식한 접근법? 중복 허용으로 인해, 최악의 경우 2500^4 (시간/메모리 초과)
    
    // 1. source -> sink 이동 거리(dist = getDist(curY, curX, destY, destX)) 계산
    // 1-1. !(dist >= k || ((dist % 2 == 0) ? k % 2 == 0 : k % 2 == 1))이면 불가능 // dist가 홀수면 k도 홀수여야 함.
    // 1-2. dist == k면 사분면(quadrant = getQuadrant(curY, curX, zeroY, zeroX)) 판단해서 사전 순 이동
    // 1-3. dist != k면, {아래, 좌, 우, 상} 순서로 이동 (단, 이동이 가능할 때만!!)
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        if (!isPossible(x, y, r, c, k)) return IMPOSSIBLE;
        if (getDist(x, y, r, c) == k) return calcMinCostToString(x, y, r, c);
        
        N = n;
        M = m;
        int destY = r, destX = c;
        int curY = x, curX = y; 
        int remainingMoveCnt = k;
        
        StringBuilder sb = new StringBuilder();
        
        while (true) {
            int dist = getDist(curY, curX, destY, destX);
            
            if (dist == remainingMoveCnt) {
                sb.append(calcMinCostToString(curY, curX, destY, destX));
                break;
            }
            
            for (String o : order) if (canMove(curY, curX, dydx.get(o))) {
                sb.append(o);
                
                curY += dydx.get(o)[0];
                curX += dydx.get(o)[1];
                
                // System.out.println("이동 횟수 버림. -> (" + curY + ", " + curX + ")");
                
                --remainingMoveCnt;
                break;
            }
        }
        
        return sb.toString();
    }
    
    private boolean isPossible(int curY, int curX, int destY, int destX, int k) {
        int dist = getDist(curY, curX, destY, destX);
        
        return (k >= dist && ((dist % 2 == 0) ? k % 2 == 0 : k % 2 == 1));
    }
    
    private boolean canMove(int curY, int curX, int[] vector) {
        int ny = curY + vector[0];
        int nx = curX + vector[1];
        
        return (1 <= ny && ny <= N && 1 <= nx && nx <= M);
    }
    
    private int getDist(int curY, int curX, int destY, int destX) {
        return Math.abs(curY - destY) + Math.abs(curX - destX);
    }
    
    private String calcMinCostToString(int curY, int curX, int destY, int destX) {
        Quadrant quadrant = Quadrant.fromCoordinate(curY, curX, destY, destX);
        String[] order = quadrant.getOrder();
        
        String result = "";
        for (String o : order) {
            int recurCnt = (o.equals("u") || o.equals("d")) ? Math.abs(curY - destY) : Math.abs(curX - destX);
            
            result += o.repeat(recurCnt);
        }
        
        // System.out.println("최적 경로 문자열 : " + result);
        
        return result;
    }
    
    private enum Quadrant { // 가능하다면 {아래 d, 좌 l, 우 r, 상 u} 순서로 이동.
        ONE("d", "l"),
        TWO("l", "u"),
        THREE("r", "u"),
        FOUR("d", "r"),
        ON_PLUS_Y("d"),
        ON_PLUS_X("l"),
        ON_MINUS_Y("u"),
        ON_MINUS_X("r")
        ;
        
        private final String[] order;

        public static Quadrant fromCoordinate(int curY, int curX, int zeroY, int zeroX) {
            int flag = checkQuadrant(curY, curX, zeroY, zeroX);
            
            if (flag == 1) return Quadrant.ONE;
            else if (flag == 2) return Quadrant.TWO;
            else if (flag == 3) return Quadrant.THREE;
            else if (flag == 4) return Quadrant.FOUR;
            else if (flag == 5) return Quadrant.ON_PLUS_Y;
            else if (flag == 6) return Quadrant.ON_PLUS_X;
            else if (flag == 7) return Quadrant.ON_MINUS_Y;
            else return Quadrant.ON_MINUS_X;
        }
        
        private static int checkQuadrant(int curY, int curX, int zeroY, int zeroX) {
            int relativeY = curY - zeroY;
            int relativeX = curX - zeroX;
            
            if (relativeY < 0 && relativeX > 0) return 1;
            else if (relativeY > 0 && relativeX > 0) return 2;
            else if (relativeY > 0 && relativeX < 0) return 3;
            else if (relativeY < 0 && relativeX < 0) return 4;
            else if (relativeY < 0 && relativeX == 0) return 5;
            else if (relativeY == 0 && relativeX > 0) return 6;
            else if (relativeY > 0 && relativeX == 0) return 7;
            else return 8;
        }
        
        private Quadrant(String... order) {this.order = order;}
        
        public String[] getOrder() {
            return this.order;
        }
    }
}