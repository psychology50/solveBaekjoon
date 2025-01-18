class Solution {
    private int[] weak, dist;
    private int[][] weakCases;
    private int n, answer;
    
    // 레스토랑: 원, 총 둘레 n미터 (몇몇 지점이 취악함)
    // 원 둘레: 1 <= n <= 200
    // 취약 지점 위치(오름차순): 1 <= weak.length <= 15
    // 각 친구가 1시간 동안 이동할 수 있는 거리: 1 <= dist.length <= 8
    // 반환: 취약 지점 점검을 위한 친구 수 최소값 (친구 모두 투입해도 취약 지점 전부 점검 불가능하면 -1)
    public int solution(int n, int[] weak, int[] dist) {
        weakCases = new int[weak.length][weak.length];
        this.weak = weak;
        this.dist = dist;
        this.answer = dist.length;
        this.n = n;
        
        makeWeakCases();
        makeDistCases(new boolean[dist.length], new int[dist.length], 0);
        
        if (answer == dist.length+1) {
            return -1;
        }
        
        return answer;
    }
    
    private void makeWeakCases() {
        int[] weakCase = this.weak.clone();
        weakCases[0] = weakCase.clone();
        
        for (int i=1; i<weak.length; ++i) {
            int tmp = weakCase[0];
            
            for (int j=1; j<weak.length; ++j) {
                weakCase[j-1] = weakCase[j];
            }
            
            weakCase[weak.length - 1] = tmp + n;
            weakCases[i] = weakCase.clone();
        }
    }
    
    private void makeDistCases(boolean[] distVisited, int[] distCase, int idx) {
        if (idx == dist.length) {
            for (int[] weakCase: weakCases) {
                validate(distCase, weakCase);
            }
        }
        
        for (int i=0; i<dist.length; ++i) if (!distVisited[i]) {
            distVisited[i] = true;
            distCase[idx] = dist[i];
            makeDistCases(distVisited, distCase, idx+1);
            distCase[idx] = 0;
            distVisited[i] = false;
        }
    }
    
    private void validate(int[] distCase, int[] weakCase) {
        int cur = 0;
        int nxt;
        int distIdx = 0;
        
        while (cur < weakCase.length && distIdx < distCase.length) {
            nxt = cur + 1;
            while (nxt < weakCase.length && weakCase[cur] + distCase[distIdx] >= weakCase[nxt]) {
                ++nxt;
            }
            cur = nxt;
            ++distIdx;
        }
        
        if (cur == weakCase.length && distIdx < answer)
            answer = distIdx;
    }
}