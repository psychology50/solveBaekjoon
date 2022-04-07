import sys
input = sys.stdin.readline

tree = {}

def preorder(root):
    if not root == '.':
        print(root, end = '')
        preorder(tree[root][0])
        preorder(tree[root][1])

def inorder(root):
    if not root == '.':
        inorder(tree[root][0])
        print(root, end = '')
        inorder(tree[root][1])

def postorder(root):
    if not root == '.':
        postorder(tree[root][0])
        postorder(tree[root][1])
        print(root, end = '')

def solution():
    n = int(input())
    for _ in range(n):
        root, left, right = input().split()
        tree[root] = [left, right]
    preorder('A')
    print()
    inorder('A')
    print()
    postorder('A')

solution()