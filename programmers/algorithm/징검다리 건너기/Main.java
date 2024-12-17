class Solution {
    // 각 징검다리에 숫자. 0이 되면 더 이상 밟을 수 X
    // 다음 돌이 0이면, 그 다음 디딤돌로 여러칸 뛰기 가능 (단, 무조건 가장 까다로운 디딤돌로만 가능)
    // 1 <= N <= 200,000 (1 <= stones[i] <= 200,000,000)
    // 한 번에 뛸 수 있는 거리 (1 <= k <= N)
    // 반환: 최대 몇 몇까지 건널 수 있는지?
    
    // 무식한 방법: (건널 수 없는 상황까지) * N번 반복 => 시간 초과 우려
    // 건널 수 없음의 조건: k 구간 이상의 0이 먼저 발생하는 순간
    // minValue(최소값) 찾기 -> 모든 다리에서 minValue 빼기 -> 아직 건널 수 없음 조건 충족 못하면 반복?
    //  - 최악의 경우 (k 최대): 1 2 3 4 5 6 7 8 9 10 ... 200,000,000
    
    // 이분 탐색
    // - left=0, right=200,000,000 -> mid-100,000,000 명이 건널 수 있는가?
    //  - stones[i] >= 100,000,000이면 패스
    //  - stones[i] < 100,000,000이면 k 범위 이내에 100,000,000 이상의 돌이 존재해야 함.
    public int solution(int[] stones, int k) {
        int answer = 0;
        
        int N = stones.length;
        int left = 0, right = 200000000;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            // System.out.println(mid + "명이 뛸 수 있는가?");

            boolean canJump = true;
            for (int cur=0; cur<N; ++cur) {
                if (stones[cur] < mid) { // 뛰어야 하는가?
                    // System.out.println(cur + " 위치에서 " + stones[cur] + "이므로, 이전 위치에서 점프 필요");

                    int pre = cur-1;
                    for (int jump=1; jump<=k; ++jump) {
                        if (pre + jump >= N) {
                            canJump = true;
                            cur = pre + jump;
                            break;
                        }
                        
                        if (pre + jump < N && stones[pre + jump] >= mid) {
                            // System.out.println(jump + "만큼 뛰면, " + (stones[pre + jump]) + "로 이동 가능");

                            canJump = true;
                            cur = pre + jump;
                            break;
                        } else {
                            // System.out.println("점프 불가!! " + pre + " -> " + (pre + jump));
                            canJump = false;
                        }
                    }
                }
                
                if (!canJump) break;
            }
            
            if (canJump) {
                // System.out.println("✅ " + mid + "명 이동 가능");
                left = mid+1;
                answer = mid;
            } else {
                // System.out.println("❌ 모두 이동 불가");
                right = mid-1;
            }
        }
        
        return answer;
    }
}