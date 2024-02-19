#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define sz(x) int(x.size())
 
using ll = long long;
const ll INF = 7e18 + 10;
 
template<class NODE>
using V = vector<NODE>;
using vi = V<int>;
using pi = pair<int, int>;
using vpi = V<pi>;
using vl = V<ll>;
 
struct NODE {
	ll start, subtree_depth, end, subtree_start, subtree_end, subtree_diameter;
 
	NODE() { start = subtree_depth = end = subtree_start = subtree_end = subtree_diameter = -INF; }
	NODE(ll x) {
		start = x;
        subtree_depth = -2 * x;
        end = x;
        subtree_start = -x;
        subtree_end = -x;
        subtree_diameter = 0;
	}
 
	void upd(ll d) {
		start += d;
        subtree_depth -= 2 * d;
        end += d;
        subtree_start -= d;
        subtree_end -= d;
	}
};
 
struct Seg {
	const NODE ID = NODE(); 
    
    /**
     * 트리 내의 두 노드 결합
     */
    NODE comb(NODE a, NODE b) {
		NODE c = NODE(); 
		c.start = max(a.start, b.start);
        c.subtree_depth = max(a.subtree_depth, b.subtree_depth);
        c.end = max(a.end, b.end);
		c.subtree_start = max({a.subtree_start, b.subtree_start, a.start + b.subtree_depth});
        c.subtree_end = max({a.subtree_end, b.subtree_end, a.subtree_depth + b.end});
		c.subtree_diameter = max({a.subtree_diameter, b.subtree_diameter, a.subtree_start + b.end, a.start + b.subtree_end});
		return c;
	};
 
	V<NODE> seg; 
    vl lazy; 
    int N; 
    
    /** 
     * 세그먼트 트리 초기화
    */
    void init(int n) {
		for(N = 1; N < n; ) N *= 2;
		seg.assign(2 * N, ID); 
        lazy.assign(2 * N, 0);
	}
 
    /**
     * 세그먼트 트리에 값 삽입
     */
	void push(int x, int L, int R) {
		seg[x].upd(lazy[x]);
		if (L != R) for(int i = 0; i < 2; i++) lazy[2*x+i] += lazy[x];
		lazy[x] = 0;
	}
 
    /**
     * 세그먼트 트리의 x번째 노드에 값 삽입
     */
	void set(int p, NODE x) {
		seg[p += N] = x; 
        for(p /= 2; p; p /= 2) pull(p);
	}
 
    /**
     * 상향식 세그먼트 트리 갱신
     */
	void pull(int x) { seg[x] = comb(seg[2*x], seg[2*x+1]); }
 
    /**
     * Lazy Propagation
     */
	void upd(int l, int r, ll v, int x, int L, int R) {
		push(x, L, R); 
        if (r < L || R < l) return;
		if (l <= L && R <= r) {
			lazy[x] += v; push(x, L, R); return;
		}
 
		int M = (L + R) / 2;
		upd(l, r, v, 2 * x, L, M);
		upd(l, r, v, 2 * x + 1, M + 1, R);
		pull(x);
	}
 
	void upd(int l, int r, ll v) { upd(l, r, v, 1, 0, N - 1); }
};

void dfs(int u, int p, vi& st, vi& en, vl& W, Seg& S, vi& ord, int& t, ll& dep, vi& E, const V<vpi>& adj) {
    st[u] = en[u] = t; 
    S.set(t, NODE(dep)); 
    ord.push_back(u); 
    ++t;

    for(auto& e : adj[u]) {
        int v, i; 
        tie(v, i) = e;

        if (v == p) continue;

        dep += W[i];
        E[i] = v; 
        
        dfs(v, u, st, en, W, S, ord, t, dep, E, adj);
        dep -= W[i];

        S.set(t, NODE(dep)); 
        en[u] = t; 
        ord.push_back(u); t++; 
    }
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int N, M; ll MXW; cin >> N >> M >> MXW;
 
	V<vpi> adj(N); 
    vi E(N - 1); 
    vl W(N);
 
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v >> W[i]; --u, --v;
		adj[u].push_back(make_pair(v, i));
		adj[v].push_back(make_pair(u, i));
	}
	
	Seg S; S.init(2*N); 
    vi st(N), en(N);
 
	vi ord; int t = 0; ll dep = 0;
	dfs(0, -1, st, en, W, S, ord, t, dep, E, adj);
 
	ll last = 0;
	for(int i = 0; i < M; i++) {
		ll e, w; cin >> e >> w;
 
		e = ll(e + last) % ll(N - 1);
		w = ll(w + last) % MXW;
 
		int u = E[e];
		S.upd(st[u], en[u], w - W[e]);
		W[e] = w;
 
		last = S.seg[1].subtree_diameter;
		cout << last << endl;
	}
 
	return 0;
}