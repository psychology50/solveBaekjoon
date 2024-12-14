import java.util.*;

class Solution {
    private int[][] answer;
    private int idx = 0;
    
    public int[][] solution(int[][] nodeinfo) {
        Node[] G = new Node[nodeinfo.length];
        for (int i=0; i<nodeinfo.length; ++i) {
            G[i] = new Node(nodeinfo[i][0], nodeinfo[i][1], i+1, null, null);
        }
        Arrays.sort(G);
        
        Node root = G[0];
        for (int i=1; i < G.length; ++i) {
            // System.out.println("root : " + root.getValue() + " <-- " + G[i].getValue());
            makeTree(root, G[i]);
        }
        
        answer = new int[2][nodeinfo.length];
        
        preorder(root);
        idx=0;
        postorder(root);
        
        int[][] result = {};
        return result=answer;
    }
    
    private void makeTree(Node parent, Node child) {
        if (parent.getX() < child.getX()) {
            if (parent.getRight() == null) {
                parent.setRight(child);
            } else {
                makeTree(parent.getRight(), child);
            }
        } else {
            if (parent.getLeft() == null) {
                parent.setLeft(child);
            } else {
                makeTree(parent.getLeft(), child);
            }
        }
    }
    
    private void preorder(Node parent) {
        if (parent != null) {
            answer[0][idx++] = parent.getValue();
            // System.out.println("preorder --> " + answer[0][idx-1]);
            preorder(parent.getLeft());
            preorder(parent.getRight());
        }
    }
    
    private void postorder(Node parent) {
        if (parent != null) {
            postorder(parent.getLeft());
            postorder(parent.getRight());
            answer[1][idx++] = parent.getValue();
        }
    }
}

class Node implements Comparable<Node> {
    private int x;
    private int y;
    private int value;
    private Node right;
    private Node left;
    
    public Node(int x, int y, int value, Node right, Node left) {
        this.x = x;
        this.y = y;
        this.value = value;
        this.right = right;
        this.left = left;
    }
    
    public int getX() {
        return this.x;
    }
    
    public int getY() {
        return this.y;
    }
    
    public int getValue() {
        return this.value;
    }
    
    public Node getRight() {
        return this.right;
    }
    
    public void setRight(Node right) {
        this.right = right;
    }
    
    public Node getLeft() {
        return this.left;
    }
    
    public void setLeft(Node left) {
        this.left = left;
    }
    
//     @Override
//     public int compare(Node a, Node b) {
//         if (a.getY() == b.getY()) {
//             return a.getX() - b.getX();
//         }
        
//         return b.getY() - a.getY();
//     }
    
    @Override
    public int compareTo(Node node) {
        if (this.getY() == node.getY()) {
            return this.getX() - node.getX();
        }
        return node.getY() - this.getY();
    }
}