class Solution {
    // n: 상자 개수
    // w: 창고 가로 길이
    // num: 찾고 싶은 상자
    // 반환: 꺼내야 하는 상자 총 개수
    
    // 홀수(1,3,5,...) row: top = cur + 2*(w-col) + 1
    // 짝수(2,4,6,...) row: top = cur + 2*(col-1) + 1
    public int solution(int n, int w, int num) {
        int answer = 1;
        int row = 1, cur = num, col = 0;
        
        while (true) {
            if (num <= row * w) break;
            ++row;
        }
        // System.out.println(num + "의 row : " + row);
        
        if (row % 2 == 1) {
            col = (num % w == 0) ? w : num % w;
        } else {
            col = (num % w == 0) ? 1 : w - (num % w) + 1;
        }
        // System.out.println(num + "의 col : " + col);
        
        while (true) {
            if (row % 2 == 1) {
                cur += 2*(w-col) + 1;
            } else {
                cur += 2*(col-1) + 1;
            }
            
            if (cur > n) break;
            // System.out.println("현재 : " + cur);
            
            ++answer;
            ++row;
        }
        
        return answer;
    }
}