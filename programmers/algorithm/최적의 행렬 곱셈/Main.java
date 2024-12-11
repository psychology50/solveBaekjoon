class Solution {
    // private Map<Integer, List<Element>> graph = new HashMap();
    // private int answer = 0;
    private int[][] cache = new int[201][201];
    
    // dp를 사용할 수 없을까?
    // 행렬 A, B, C, D
    // [계산 순서 조합]
    // A(B(CD)) or A((BC)D) or (AB)(CD) or ((AB)C)D
    // cache[i][j] : i번째 행렬부터, j번째 행렬까지의 최소 연산 횟수
    public int solution(int[][] matrix_sizes) {
        int answer = 0;
        int n = matrix_sizes.length;
        
        int matrix1, matrix2;
        for (int i=0; i<n; ++i) for (int j=0; j<n-i; ++j) {
            matrix1 = j;
            matrix2 = j+i;
            
            if (matrix1 == matrix2) cache[matrix1][matrix2] = 0;
            else {
                cache[matrix1][matrix2] = Integer.MAX_VALUE;
                for (int k=matrix1; k<matrix2; ++k) {
                    cache[matrix1][matrix2] = Math.min(
                        cache[matrix1][matrix2],
                        cache[matrix1][k] + cache[k+1][matrix2] + (matrix_sizes[matrix1][0] * matrix_sizes[k][1] * matrix_sizes[matrix2][1])
                    );
                }
            }
        }
        
        return cache[0][n-1];
    }
    
    // ========= 너무 조건을 랜덤으로 잡아서 망함 ==========
//     // 행렬 곱셈 조건 matrix[x, y]일 때, y1과 x2의 값이 동일해야 함.
//     // matrix[x1, y1] * matrix[x2, y2] = matrix[x1, y2]
//     // 연산 순서가 강제되는 경우: [[5,3], [3,10], [3,9], [9,3]] // 0 -> 1을 바로 선택할 수 없음.
//     // 데이터 전처리: 
//     //  - Map<행, List<열, 연산 횟수>>: 방문 처리 어떻게? (map.size() == 1 될 때까지 반복)
//     //  - Tree: 모든 x에 매칭되는 y가 있는 경우 -> 순환 그래프
//     // 캐싱? N이 작아서 무의미 하기도 하고, 그래프가 너무 복잡해서 오히려 위험할 듯.
//     public int solution(int[][] matrix_sizes) {
//         for (int i=0; i<matrix_sizes.length; ++i) {
//             Integer row = Integer.valueOf(matrix_sizes[i][0]);
//             Integer col = Integer.valueOf(matrix_sizes[i][1]);
            
//             if (graph.get(row) == null) graph.put(row, new ArrayList());
            
//             graph.get(row).add(Element.of(col, 0));
//         }        
        
//         for (Integer key : graph.keySet()) {
//             recur(key);
//         }
        
//         return answer;
//     }
    
//     private void recur(Integer row) { // : 이전 연산으로 생성된 row
//         if (graph.size() == 1) {
//             System.out.println("최종 결과 : " + graph.get(row).get(0));
//             answer = Math.min(answer, graph.get(row).get(0).getCount());
//             return;
//         }
        
//         List<Element> elements = graph.get(row);
//         boolean flag = true;
//         for (Element elem: elements) {
//             if (graph.get(elem.getCol()) != null && !graph.get(elem.getCol()).isEmpty()) {
//                 flag = false;
//             }
//         }
//         if (flag) return; // 다음 연산을 수행할 행렬이 하나도 없을 경우 종료.
        
//         for (Map.Entry<Integer, List<Element>> entry: graph.entrySet()) {
//             for (int i=0; i<entry.getValue().size(); ++i) {
//                 Element elem = graph.get(entry.getKey()).get(i);
                
//                 if (graph.get(elem.getCol()) == null) continue;
                
//                 for (int j=0; j<graph.get(elem.getCol()).size(); ++j) {
//                     Element nxt = graph.get(elem.getCol()).get(j);
//                     Element multipliedElem = Element.of(nxt.getCol(), entry.getKey() * elem.getCol() * nxt.getCol() + nxt.getCount());
//                     System.out.println("row = " + entry.getKey());
//                     System.out.println("cur = " + elem + "\nnxt = " + nxt + "\n곱한 결과 = row: " + entry.getKey() + ", " + multipliedElem);
                    
//                     graph.get(entry.getKey()).remove(i);
//                     graph.get(elem.getCol()).remove(j);
//                     if (graph.get(entry.getKey()) == null) graph.put(entry.getKey(), new ArrayList());
//                     graph.get(entry.getKey()).add(multipliedElem);
                    
//                     recur(entry.getKey());

//                     graph.get(entry.getKey()).remove(multipliedElem);
//                     graph.get(elem.getCol()).add(j, nxt);
//                     graph.get(entry.getKey()).add(i, elem);
//                 }
//             }
//         }
//     }
    
//     private static class Element {
//         private final Integer col;
//         private final int count;
        
//         private Element(Integer col, int count) {
//             this.col = col;
//             this.count = count;
//         }
        
//         private static Element of(Integer col, int count) {
//             return new Element(col, count);
//         }
        
//         public Integer getCol() {
//             return this.col;
//         }
        
//         public int getCount() {
//             return this.count;
//         }
        
//         @Override
//         public String toString() {
//             return "col: " + col + " -> count: " + count;
//         }
//     }
}