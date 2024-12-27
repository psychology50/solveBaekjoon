class Solution {
    // 결과: "110"을 뽑고 삽입했을 때, 사전 순으로 가장 앞에 오는 문자열을 배열로 반환
    // 1 <= N <= 1,000,000
    // 1 <= s[i] 길이 (& 모든 길이의 합) <= 1,000,000
    
    // 가장 먼저 나오는 "110"을 맨뒤로? 바로 뒤가 "111"이면 오히려 손해
    // 1110(14) -> 1101(13) <= -1
    // 100111100(4 + 8 + 16 + 32 + 256 = 316) -> 100110110(2 + 4 + 16 + 32 + 256 = 310) <= -6
    // 0111111010(2 + 8 + 16 + 32 + 64 + 128 + 256 = 506) 
    //  -> 0110111110(2 + 4 + 8 + 16 + 32 + 128 + 256 = 446) <= -60 
    //  -> 0110110111(1 + 2 + 4 + 16 + 32 + 128 + 256 = 439) <= -7
    // 굳이 비트 형태로 줬다는 건, 써먹으라는 이야기가 아닐까?
    // "110"의 개수를 확인, 나머지 0과 1의 개수를 확인 -> 조합으로 해결? (기존 순서는 유지해야 함)
    // 수열에서 "110"만 모두 제거 -> 최적의 위치에 삽입? -> 이동 과정에서, 존재하지 않던 "110"이 발생할 수 있음.
    // 최적의 위치란?
    //  - 남은 수열에 0이 없으면 가장 앞에
    //  - 남은 수열에 0이 존재하면, 반드시 가장 뒤로 ("111"보다 작은 값이 없으므로)
    public String[] solution(String[] s) {
        String[] answer = new String[s.length];
        StringBuilder sb;
        
        for (int i=0; i<s.length; ++i) {
            String cur = s[i];
            sb = new StringBuilder();
            
            // int cnt = 0;
            int numOf110 = 0;
            int len = 0;
            for (int j=0; j < cur.length(); ++j) {
                Character c = cur.charAt(j);
                
                len = sb.length();
                if (c == '0' && len >= 2 && sb.charAt(len-1) == '1' && sb.charAt(len-2) == '1') {
                    ++numOf110;
                    sb.delete(len - 2, len);
                } else sb.append(c);
                
//                 if (c == '1' && (cnt == 0 || cnt == 1)) ++cnt; // 1이면 카운트 증가
//                 else if (c == '0' && cnt == 2) { // "110"이면 카운트 초기화하고, 개수 갱신
//                     cnt = 0;
                    
//                     int len = sb.length();
//                     if (len >= 1 && sb.charAt(len-1) == '1') { // 새롭게 "110"을 추출할 수 있는지 확인
//                         ++cnt;
//                         sb.delete(len - 1, len);
//                     }
//                     if (len >= 2 && sb.charAt(len-2) == '1') {
//                         ++cnt;
//                         sb.delete(len - 1, len);
//                     }
                        
//                     ++numOf110;
//                 } else if (c == '1' && cnt == 2) sb.append('1'); // "111"이면 가장 앞의 1 삽입하고 진행
//                 else if (c == '0') {
//                     if (cnt != 0) { // 현재 '0'인데, cnt == 2 조건에 안 걸렸다면, 앞의 1모두 삽입
//                         for (int k=0; k<cnt; ++k) sb.append('1');
//                         cnt = 0;
//                     }
//                     sb.append('0');
//                 }
                
                // System.out.println("입력: " + c + ", cnt = " + cnt + ", numOf110 = " + numOf110);
            }
            
            // if (cnt != 0) {
            //     for (int k=0; k<cnt; ++k) sb.append('1');
            //     cnt = 0;
            // }
            
            // System.out.println("파싱한 문자열 : " + sb.toString());
            // System.out.println("110 개수 : " + numOf110);
            while (numOf110-- > 0) {
                int lastZeroIdx = sb.lastIndexOf("0"); 
                
                if (lastZeroIdx == -1) sb.insert(0, "110");
                else sb.insert(lastZeroIdx + 1, "110");
            }
            
            answer[i] = sb.toString();
        }
        
        return answer;
    }
}