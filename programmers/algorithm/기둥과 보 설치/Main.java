import java.util.*;

class Solution {
    private static final int[][] dydx = {{0, 0}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    private int[][] pillar;
    private int[][] beam;
    private int N;
    
    // 기둥: 바닥 위 or 보의 한쪽 끝 or 다른 기둥 위
    // 보: 한쪽 끝 부분이 기둥 위 or 양쪽 끝 부분이 다른 보와 동시 연결
    // 바닥: 배열(벽면)의 가장 마지막 row
    // 배열은 n * n 크기, 각 격자는 1 * 1 크기
    // build_frame : 작업 순서 (x, y, a:0(기둥)/1(보), b:0(삭제)/1(설치)) -> 설치 불가능하면 패스
    // 결과: 모든 명령어를 수행한 후 구조물 상태 (이차원 배열 (x, y, a) -> x, y, a 순 오름차순 정렬)
    public int[][] solution(int n, int[][] build_frame) {
        N = n;
        pillar = new int[n+1][n+1];
        beam = new int[n+1][n+1];
        
        for (int i=0; i<build_frame.length; ++i) {
            int x = build_frame[i][0], y = build_frame[i][1];
            int type = build_frame[i][2], action = build_frame[i][3];
            
            // 기둥이라면
            if (type == 0) {
                if (action == 0) {
                    removePillar(x, y);
                } else {
                    buildPillar(x, y);                    
                }
            }
            
            // 보라면
            if (type == 1) {
                if (action == 0) {
                    removeBeam(x, y);
                } else {
                    buildBeam(x, y);
                }
            }
        }

        return calcResult();
    }
    
    private void buildPillar(int x, int y) {
        if (!isBuildPillar(x, y)) return;
        
        pillar[y][x] = 1;
        // System.out.println("(" + x + ", " + y + ")에 기둥 추가 (+)");
    }
    
    // 기둥을 제거하는 조건
    // - 위에 기둥이 없어야 함.
    // - 위의 보가 있다면, 양쪽 끝 부분에 다른 보와 연결되어 있거나, 한쪽 끝이 기둥에 있어야 함. 
    private void removePillar(int x, int y) {
        pillar[y][x] = 0;
        
        if (!isRemove(x, y)) { // 삭제해보고 안 되면 rollback
            pillar[y][x] = 1;
        }
        // else System.out.println("(" + x + ", " + y + ")에 기둥 제거 (-)");
    }
    
    private void buildBeam(int x, int y) {
        if (!isBuildBeam(x, y)) return;
        
        // System.out.println("(" + x + ", " + y + ")에 보 추가 (+)");
        
        beam[y][x] = 1;
    }
    
    // 보를 제거하는 조건 (바닥에 보를 설치하는 조건은 없음)
    // - 한쪽 끝에 기둥이 없어야 함.
    // - 기둥이 있다면, 다른 보가 지탱하고 있어야 함.
    // - 양쪽을 보에만 의지하고 있는 이웃한 보가 없어야 함.
    private void removeBeam(int x, int y) {
        beam[y][x] = 0;
        
        if (!isRemove(x, y)) { // 삭제해보고 안 되면 롤백
            beam[y][x] = 1;
        }
        // else System.out.println("(" + x + ", " + y + ")에 보 제거 (-)");
    }
    
    private boolean isRemove(int x, int y) {
        for (int direction = 0; direction<9; ++direction) {
            int ny = y - dydx[direction][0], nx = x - dydx[direction][1];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            
            if (pillar[ny][nx] != 0 && !isBuildPillar(nx, ny)) return false;
            if (beam[ny][nx] != 0 && !isBuildBeam(nx, ny)) return false;
        }
        
        return true;
    }
    
    // 기둥을 설치하는 조건
    // - 바닥이어야 함.
    // - 아래 기둥이 있어야 함.
    // - 아래에 보가 있어야 함.
    private boolean isBuildPillar(int x, int y) {
        // 바닥이면 무조건 가능
        if (y == 0) return true;
        // 바로 아래 기둥이 존재하는 경우
        if (pillar[y-1][x] == 1) return true;
        // 왼쪽 아래, 혹은 바로 아래에 보가 존재하는 경우
        if (beam[y][x] == 1 || (x-1 >= 0 && beam[y][x-1] == 1)) return true;
        
        return false;
    }
    
    // 보를 설치하는 조건
    // - 한쪽 끝 부분이 기둥에 있어야 함
    // - 양쪽 끝 부분이 다른 보와 동시에 연결되어야 함.
    private boolean isBuildBeam(int x, int y) {
        // 아래 혹은 우측 하단에 기둥 존재 여부 확인
        if (y-1 >= 0 && (pillar[y-1][x] == 1 || (x+1 <= N) && pillar[y-1][x+1] == 1)) return true;
        // 양쪽 모두 보가 존재
        if ((x-1 >= 0 && beam[y][x-1] == 1) && (x+1 < N) && beam[y][x+1] == 1) return true;
        
        return false;
    }
    
    private int[][] calcResult() {
        List<int[]> view = new ArrayList<>();
        for (int x=0; x<=N; ++x) for (int y=0; y<=N; ++y) {
            if (pillar[y][x] != 0) {
                int[] elem = {x, y, 0};
                view.add(elem);
            }
            
            if (beam[y][x] != 0) {
                int[] elem = {x, y, 1};
                view.add(elem);
            }
        }
        
        int[][] answer = new int[view.size()][3];
        for (int i=0; i<view.size(); ++i) {
            answer[i] = view.get(i);
        }
        
        return answer;
    }
}