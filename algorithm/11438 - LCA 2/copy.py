from sys import stdin
from collections import deque as dq


def solution(graph: dict[int, list[tuple[int]]],
             queries: list[list[int]], n: int) -> str:
    def fill():
        q = dq([1])
        while q:
            for dst in graph[src := q.popleft()]:
                if dst == p[0][src]:
                    continue
                d[dst], p[0][dst] = d[src] + 1, src
                q.append(dst)
        for r in range(1, len(p)):
            for c in range(1, n):
                p[r][c] = p[r - 1][p[r - 1][c]]

    def lca(fr, to) -> str:
        if d[fr] < d[to]:
            fr, to = to, fr
        for i in range(len(p) - 1, -1, -1):
            if d[fr] - d[to] >= (1 << i):
                fr = p[i][fr]
        if fr == to:
            return str(fr)
        for i in range(len(p) - 1, -1, -1):
            if p[i][fr] != p[i][to]:
                fr, to = p[i][fr], p[i][to]
        return str(p[0][fr])

    p, d = [[0] * n for _ in range(len(bin(n - 1)[2:]))], [0] * n
    fill()
    return '\n'.join(lca(f, t) for f, t in queries)


def reader():
    read = stdin.readline
    n = int(read().rstrip())
    g = {}
    for _ in range(n - 1):
        u, v, = map(int, read().split())
        g.setdefault(u, []).append(v)
        g.setdefault(v, []).append(u)
    k = int(read().rstrip())
    q = [list(map(int, read().split())) for _ in range(k)]
    print(solution(g, q, n + 1))


if __name__ == '__main__':
    reader()
