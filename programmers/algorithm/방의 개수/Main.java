import java.util.*;

class Solution {
    private static final int[][] dydx = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    
    // 1 <= N <= 100,000
    // 0 <= 방향 <= 7
    // 한쪽으로 이동: 최대 100,000 * 1 크기 / 두 방향이동: 최대 100,000 * 100,000 (2차원 배열 만들면 공간복잡도 초과)
    // 하나의 공간: 이미 경유한 정점을 지날 때? 좌우 와리가리는 해당 안 됨.
    //              => 이미 경유한 정점을 다른 방향에서 접근할 때?
    // 방문 처리 어떻게? => 방문 정점 Set에 삽입하고, 빠르게 조회?
    // 방문 정점 Vertex : x, y, 해당 정점으로 들어온 방향
    // (1) 정점이 아닌 곳에서 선분이 교차한다면? (대각선 이동의 경우 가능)
    // (2) {아래 - 아래 - 우상 - 좌하} 이동의 경우에 잘못된 케이스 계산 => 왔던 길로 되돌아 온 경우이므로 패스
    // (3) 이미 계산한 지점을 다시 계산하면? (ex 마름모 그리고 반대편 정점으로 이동, 같은 경로로 마름모를 그리면?) => 이미 그어진 선분들 제외해야 함.
    // 정리
    //  - Set<Vertex> : 방문 정점 관리
    //  - Set<Edge> : 방문 간선 관리
    // 한 칸의 정의: 다음 정점으로 이동할 때, 현재 <-> 다음 어느 방향의 간선도 존재하지 않으며, 다음 정점 방문한 적이 있을 때
    public int solution(int[] arrows) {
        int answer = 0;
        
        int y=0, x=0;
        Set vertices = new HashSet();
        Set edges = new HashSet();
        
        Vertex cur = Vertex.of(y, x);
        vertices.add(cur);
        
        for (int i=0; i<arrows.length; ++i) {
            int dir = arrows[i];
            int ny = y + dydx[dir][0], nx = x + dydx[dir][1];
            
            // 다음 정점
            Vertex nxt = Vertex.of(ny, nx);
            
            // 방문한 적이 있고, 새로 이어지는 선분이라면?
            if (vertices.contains(nxt) && !edges.contains(Edge.of(cur, nxt)) && !edges.contains(Edge.of(nxt, cur))) {
                ++answer;             
            }
            
            // 대각선 이동이고, 처음 그려지는 선분인 경우
            if (dir % 2 == 1 && !edges.contains(Edge.of(cur, nxt)) && !edges.contains(Edge.of(nxt, cur))) {
                // 교차하는 대각선이 존재하는 경우
                Vertex point1 = Vertex.of(y + dydx[dir - 1][0], x + dydx[dir - 1][1]);
                Vertex point2 = Vertex.of(y + dydx[(dir + 1) % 8][0], x + dydx[(dir + 1) % 8][1]);
                if (edges.contains(Edge.of(point1, point2)) || edges.contains(Edge.of(point2, point1))) {
                    ++answer;
                }
            }
            
            vertices.add(nxt);
            edges.add(Edge.of(cur, nxt));
            
            // 현재 정점 이동
            y = ny;
            x = nx;
            cur = Vertex.of(ny, nx);
        }   
        
        return answer;
    }
    
    private static class Edge {
        private final Vertex cur;
        private final Vertex nxt;
        
        private Edge(Vertex cur, Vertex nxt) {
            this.cur = cur;
            this.nxt = nxt;
        }
        
        private static final Edge of(Vertex cur, Vertex nxt) {
            return new Edge(cur, nxt);
        }    
        
        public Vertex getCur() {
            return this.cur;
        }
        
        public Vertex getNxt() {
            return this.nxt;
        }
        
        @Override
        public int hashCode() {
            return 31 * cur.hashCode() + nxt.hashCode();
        }
        
        @Override
        public boolean equals(Object o) {
            if (o instanceof Edge) {
                Edge edge = (Edge) o;
                
                return edge.getCur().equals(cur) && edge.getNxt().equals(nxt);
            }
            return false;
        }
    }
    
    private static class Vertex {
        private final int y;
        private final int x;
        
        private Vertex(int y, int x) {
            this.y = y;
            this.x = x;
        }
        
        private static final Vertex of(int y, int x) {
            return new Vertex(y, x);
        }
        
        public int getY() {
            return this.y;
        }
        
        public int getX() {
            return this.x;
        }
        
        @Override
        public int hashCode() {
            int result = Integer.hashCode(this.y);
            return 31 * result + Integer.hashCode(this.x);
        }
        
        @Override
        public boolean equals(Object o) {
            if (o instanceof Vertex) {
                Vertex vertex = (Vertex) o;
                
                return vertex.getY() == this.y && vertex.getX() == this.x;
            }
            return false;
        }
    }
}