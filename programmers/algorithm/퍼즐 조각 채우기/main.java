import java.util.*;

class Solution {
    private static final int[][] dydx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private static int N;
    
    private List<List<Node>> empties = new ArrayList<>();
    private List<List<Node>> blocks = new ArrayList<>();
    
    public int solution(int[][] game_board, int[][] table) {
        N = table.length;
        
        boolean[][] boardVisited = new boolean[N][N], tableVisited = new boolean[N][N];
        for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
            if (game_board[i][j] == 0 && !boardVisited[i][j]) findBlock(i, j, 0, boardVisited, game_board);
            if (table[i][j] == 1 && !tableVisited[i][j]) findBlock(i, j, 1, tableVisited, table);
        }
        
        return findAnswer();
    }

    private void findBlock(int y, int x, int target, boolean[][] visited, int[][] board) {
        visited[y][x] = true;
        
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(y, x));
        
        List<Node> tmp = new ArrayList<>();
        tmp.add(new Node(0, 0));
        
        while (!q.isEmpty()) {
            Node cur = q.poll();
            
            for (int i=0; i<4; ++i) {
                int ny = cur.row() + dydx[i][0];
                int nx = cur.col() + dydx[i][1];
                
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (visited[ny][nx] || board[ny][nx] != target) continue;
                
                visited[ny][nx] = true;
                q.offer(new Node(ny, nx));
                tmp.add(new Node(ny - y, nx - x));
            }
        }
        
        if (target == 1) {
            blocks.add(tmp);
        } else {
            Collections.sort(tmp);
            empties.add(tmp);
        }
    }
    
    private int findAnswer() {
        int res = 0;
        boolean[] visited = new boolean[blocks.size()];
        
        for (int i=0; i<empties.size(); ++i) for (int j=0; j<blocks.size(); ++j) {
            if (visited[j] || empties.get(i).size() != blocks.get(j).size()) continue;
            
            // System.out.println("================");
            // System.out.println(empties.get(i));
            // System.out.println(blocks.get(j));
            
            if (isValid(empties.get(i), blocks.get(j))) {
                visited[j] = true;
                // System.out.println("성공!!!!");
                res += blocks.get(j).size();
                break;
            }
        }
        
        return res;
    }
    
    private boolean isValid(List<Node> emptyNodes, List<Node> blockNodes) {
        for (int i=0; i<4; ++i) {
            Collections.sort(blockNodes);
            
            int curY = blockNodes.get(0).row(), curX = blockNodes.get(0).col();
            // System.out.println("**************");
            // System.out.println("pre -> " + blockNodes);
            for (Node node : blockNodes) {
                node.minusRowAndCol(curY, curX);
            }
            // System.out.println("now -> " + blockNodes);
            // System.out.println("**************");
            
            if (isSameNodes(emptyNodes, blockNodes)) {
                return true;
            } 
            
            rotate(blockNodes);
        }
        
        return false;
    }
    
    private boolean isSameNodes(List<Node> emptyNodes, List<Node> blockNodes) {
        for (int idx=0; idx<emptyNodes.size(); ++idx) {
            if (emptyNodes.get(idx).row() != blockNodes.get(idx).row() || emptyNodes.get(idx).col() != blockNodes.get(idx).col()) {
                return false;
            }
        }
        return true;
    }
    
    private void rotate(List<Node> nodes) {
        for (Node node : nodes) {
            node.rotate();
        }
    }
    
    private static class Node implements Comparable<Node> {
        private int row;
        private int col;
        
        Node(int row, int col) {
            this.row = row;
            this.col = col;
        }
        
        int row() {return this.row;}
        int col() {return this.col;}
        void minusRowAndCol(int row, int col) {
            this.row -= row;
            this.col -= col;
        }

        void rotate() {
            int tmp = this.row;
            this.row = col;
            col = -tmp;
        }
        
        @Override
        public int compareTo(Node node) {
            int tmp = Integer.compare(this.row, node.row());
            return (tmp != 0) ? tmp : Integer.compare(this.col, node.col());
        }
        
        @Override
        public String toString() {
            return "(row = " + row + ", col = " + col + ")";
        }
    }
}