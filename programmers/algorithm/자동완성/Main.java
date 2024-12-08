import java.util.*;

class Solution {
    // N: 전체 단어 개수 (2 <= N <= 100,000)
    // L: 모든 단어 길이 총합 (2 <= L <= 1,000,000)
    public int solution(String[] words) {
        int answer = 0;
        
        Tree T = new Tree();
        for (String word: words) {
            T.add(word);
        }
        
        for (String word: words) {
            answer += T.find(word);
        }
        
        return answer;
    }
    
    private static class Tree {
        private static final int ALPHABET_SIZE = 26;
        private final Node[] rootNodes;
        
        public Tree() {
            rootNodes = new Node[ALPHABET_SIZE];
            
            for (int i=0; i<rootNodes.length; ++i) {
                char c = (char) ('a' + i);
                rootNodes[i] = new Node(c);
            }
        }
        
        public void add(String word) {
            Node cur = getRootNode(word);
            cur.increaseCnt();
            
            for (int i=1; i<word.length(); ++i) {
                char c = word.charAt(i);
                Node nxt = cur.getChild(c);
                
                if (nxt == null) {
                    nxt = new Node(c);
                    cur.addChild(nxt);
                }
                
                nxt.increaseCnt();
                cur = nxt;
            }
        }
        
        public int find(String word) {
            Node cur = getRootNode(word);
            int depth = 1;
            
            for (int i = 1; i < word.length(); ++i) {
                if (cur == null || cur.getCnt() == 1) break;
                
                char c = word.charAt(i);
                cur = cur.getChild(c);
                ++depth;
            }
            
            return depth;
        }
        
        private Node getRootNode(String word) {
            int idx = word.charAt(0) - 'a';
            return rootNodes[idx];
        }
    }
    
    private static class Node {
        private final char value;
        private int count;
        ArrayList<Node> children;
        
        public Node(char c) {
            this.value = c;
            this.count = 0;
            this.children = new ArrayList<>();
        }
        
        public Node getChild(char c) {
            for (Node child : children) {
                if (child.getValue() == c) {
                    return child;
                }
            }
            return null;
        }
        
        public char getValue() {
            return this.value;
        }
        
        public int getCnt() {
            return this.count;
        }
        
        public void increaseCnt() {
            this.count++;
        }
        
        public void addChild(Node child) {
            children.add(child);
        }
    }
}