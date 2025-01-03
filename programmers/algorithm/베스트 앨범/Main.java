import java.util.*;

class Solution {
    // 노래 수록 기준
    //  1. 속한 노래가 많이 재생된 장르 우선 (단, 모든 장르는 재생 횟수가 다름)
    //  2. 장르 내에서 많이 재생된 노래 우선
    //  3. 장르 내에서 (재생 회수 같으면) 고유 번호 낮은 순
    
    // 1 <= N <= 10,000 (종류는 100개 미만)
    // 반환: 장르 별, 가장 많이 재생된 노래 2개씩 (장르에 하나밖에 없으면, 하나만 선택) 
    
    // 자료 구조
    // (1) [{전체 스트리밍 수, "장르"}, ...] : 전체 스트리밍 수 순서 정렬
    // (2) {"장르", [{고유 번호, 스트리밍 수}, ...]} : value를 스트리밍 수 -> 고유 번호 순 정렬
    public int[] solution(String[] genres, int[] plays) {
        Map<String, Genre> total = new HashMap<>();
        Map<String, List<int[]>> datas = new HashMap<>();
        
        for (int i=0; i<genres.length; ++i) {
            if (total.get(genres[i]) == null) {
                total.put(genres[i], new Genre(genres[i], 0));
                datas.put(genres[i], new ArrayList<>());
            }
            
            Genre genre = total.get(genres[i]);
            genre.cnt += plays[i];
            
            datas.get(genres[i]).add(new int[]{i, plays[i]});
        }
        
        List<Genre> order = new ArrayList<>();
        for (Genre g : total.values()) {
            order.add(g);
        }
        Collections.sort(order, (a, b) -> b.cnt - a.cnt);
        
        // for (Genre g : order) {
        //     System.out.println("순서 : " + g.name);
        // }
        
        for (List<int[]> values : datas.values()) {
            Collections.sort(values, (a, b) -> (a[1] != b[1]) ? b[1] - a[1] : a[0] - b[0]);
        }
        
        // for (Map.Entry<String, List<int[]>> entry : datas.entrySet()) System.out.println(entry.getKey() + " 목록 : " + entry.getValue());
        
        List<Integer> answer = new ArrayList<>();
        
        for (Genre g : order) {
            List<int[]> playList = datas.get(g.name);
            
            for (int i=0; i<2 && i<playList.size(); ++i) answer.add(playList.get(i)[0]);
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
    
    private static class Genre {
        public String name;
        public int cnt;
        
        public Genre(String name, int cnt) {
            this.name = name;
            this.cnt = cnt;
        }
    }
}