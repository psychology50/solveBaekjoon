import java.util.*;

class Solution {
    private static final int[][] dydx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; // 상하좌우 + 좌상, 우상, 좌하, 우하 회전 기동
    
    // 드론 시작 (0, 0), (0, 1) (문제에선 (1, 1)를 시작점으로 잡으니 주의)
    // 성공: 드론 두 좌표중 하나라도 (N-1, N-1)에 도착
    // 회전 기동에 장애물 없으면 가능
    // 5 <= N <= 100
    // 반환: 이동하기 위한 최소 시간 (언제나 가능함을 전제)
    
    // 동작: 상, 하, 좌, 우 + 회전 기동(좌상, 좌하, 우상, 우하)
    // dfs보단 bfs가 적절할 듯. -> 방문 처리 어떻게? 두 위치 중 row가 더 크거나, (row가 같으면) col이 더 큰 경우
    public int solution(int[][] board) {
        int answer = 0;
        Queue<Robot> q = new LinkedList<>();
        int[] dr = {0, 0, 1, -1};
        int[] dc = {1, -1, 0, 0};
        
        int len = board.length;
        boolean[][][] visited = new boolean[len][len][2];
        
        q.add(new Robot(new Point(0, 0), new Point(0, 1), 0, 0));
        
        while(!q.isEmpty()){
            Robot ro = q.poll();
            
            //범위를 벗어나는 경우
            if(ro.p1.r<0 || ro.p1.c<0 || ro.p1.r>=len || ro.p1.c>=len || 
            ro.p2.r<0 || ro.p2.c<0 || ro.p2.r>=len || ro.p2.c>=len) continue;
        
            //벽인 경우
            if(board[ro.p1.r][ro.p1.c]==1 || board[ro.p2.r][ro.p2.c]==1) continue;
            
            //이미 방문한 경우
            if(visited[ro.p1.r][ro.p1.c][ro.vertical] && visited[ro.p2.r][ro.p2.c][ro.vertical]) continue;
            
            //종료 조건
            if((ro.p1.r==len-1 && ro.p1.c==len-1) || 
              (ro.p2.r==len-1 && ro.p2.c==len-1)) {
                answer = ro.t;
                break;
            }
            
            visited[ro.p1.r][ro.p1.c][ro.vertical] = true;
            visited[ro.p2.r][ro.p2.c][ro.vertical] = true;

            
            for(int i = 0; i < 4; i++){
                int nr1 = ro.p1.r+dr[i];
                int nr2 = ro.p2.r+dr[i];
                int nc1 = ro.p1.c+dc[i];
                int nc2 = ro.p2.c+dc[i];
        
                q.add(new Robot(new Point(nr1, nc1), new Point(nr2, nc2), ro.t+1, ro.vertical));
            }
            
            //회전시키기
            if(ro.vertical==1){
                //수직인 경우, 좌우 2칸 확인
                if(ro.p1.c-1>=0 && board[ro.p1.r][ro.p1.c-1]==0 && board[ro.p2.r][ro.p2.c-1]==0){
                    q.add(new Robot(new Point(ro.p1.r, ro.p1.c), new Point(ro.p1.r, ro.p2.c-1), ro.t+1, 0));
                    q.add(new Robot(new Point(ro.p2.r, ro.p1.c-1), new Point(ro.p2.r, ro.p2.c), ro.t+1, 0));
                }
                if(ro.p1.c+1<len && board[ro.p1.r][ro.p1.c+1]==0 && board[ro.p2.r][ro.p2.c+1]==0){
                    q.add(new Robot(new Point(ro.p1.r, ro.p1.c), new Point(ro.p1.r, ro.p2.c+1), ro.t+1, 0));
                    q.add(new Robot(new Point(ro.p2.r, ro.p1.c+1), new Point(ro.p2.r, ro.p2.c), ro.t+1, 0));
                }
            }
            else{
                //수평인 경우, 상하 2칸 확인
                if(ro.p1.r-1>=0 && board[ro.p1.r-1][ro.p1.c]==0 && board[ro.p2.r-1][ro.p2.c]==0){
                    q.add(new Robot(new Point(ro.p1.r-1, ro.p2.c), new Point(ro.p2.r, ro.p2.c), ro.t+1, 1));
                    q.add(new Robot(new Point(ro.p1.r, ro.p1.c), new Point(ro.p2.r-1, ro.p1.c), ro.t+1, 1));
                    
                }
                if(ro.p1.r+1<len && board[ro.p1.r+1][ro.p1.c]==0 && board[ro.p2.r+1][ro.p2.c]==0){
                    q.add(new Robot(new Point(ro.p1.r+1, ro.p2.c), new Point(ro.p2.r, ro.p2.c), ro.t+1, 1));   
                    q.add(new Robot(new Point(ro.p1.r, ro.p1.c), new Point(ro.p2.r+1, ro.p1.c), ro.t+1, 1));   
                }
            }
            
        }
 
        return answer;
    }
    
    class Robot{
        Point p1; 
        Point p2;
        int t;
        int vertical;
        Robot(Point p1, Point p2, int t, int vertical){
            this.p1 = p1;
            this.p2 = p2;
            this.t = t;
            this.vertical = vertical;
        }
    }
    
    class Point{
        int r, c;
        Point(int r, int c){
            this.r = r;
            this.c = c;
        }
    }
}