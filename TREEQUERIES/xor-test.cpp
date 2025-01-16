#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define sp << ' ' <<
#define nl << '\n'

const int Z_small = 2e3, Z = 3e5, B = 20;

// INPUT, 0-indexed
int N;
vector<int> g[Z];
// ................

int dfsTimer, tin[Z], sz[Z], t[Z], e[Z], p[Z][B], q[Z][B], l[Z][B], r[Z][B];
bool h[Z][B];

void dfs(int u) {
	e[tin[u] = dfsTimer++] = u;

	for(int i = 0; i + 1 < B; ++i) {
		p[u][i+1] = p[p[u][i]][i];
		q[u][i+1] = q[p[u][i]][i];
		h[u][i+1] = h[p[u][i]][i];
	}
	sort(begin(g[u]), end(g[u]));

	for(int v : g[u]) {
		if(v != p[u][0]) {
			p[v][0] = u;
			q[v][0] = v;
			h[v][0] = 1;
			dfs(v);
		} else
			l[u][0] = dfsTimer - tin[u];
	}
	sz[u] = dfsTimer - tin[u];

	int add {};
	for(int v : g[u]) {
		if(v != p[u][0]) t[v] = tin[v] - tin[u] + add;
		else add = N - sz[u];
	}

	r[u][0] = l[u][0] + (N - sz[u]) - 1;
}

void init() {
	dfs(0);

	for(int i = 0; i + 1 < B; ++i) {
	    for(int u = 1; u < N; ++u) {
			int &lv = l[u][i+1] = l[p[u][i]][i];
			int &rv = r[u][i+1] = r[p[u][i]][i];

			if(p[u][i] && q[u][i] < p[p[u][i]][0]) {
				lv -= sz[q[u][i]];
				rv -= sz[q[u][i]];
			}

			lv += l[u][i];
			rv += l[u][i];
		}
	}
}

int query(int u, int x) {
	for(int i = B; i--; ) if(h[u][i]) {
		if(l[u][i] <= x && x <= r[u][i]) {
			x -= l[u][i];
			if(t[q[u][i]] <= x) x += sz[q[u][i]];
			u = p[u][i];
		}
	}
	if(!u) return e[x];

	if(x < l[u][0])	return e[tin[u] + x];
	return e[tin[u] + x - (N - sz[u])];
}

void clear_vars() {
//int dfsTimer, tin[Z], sz[Z], t[Z], e[Z], p[Z][B], q[Z][B], l[Z][B], r[Z][B];
//bool h[Z][B];
    dfsTimer = 0;
    for (int i = 0; i < N; ++i) {
        g[i].clear();
        tin[i] = sz[i] = t[i] = e[i] = 0;
        for (int j = 0; j < 20; ++j)
            p[i][j] = q[i][j] = l[i][j] = r[i][j] = h[i][j] = 0;
    }
    N = 0;
}

void solve() {

	cin >> N;
    cout << N << '\n';
	for(int i = 1; i < N; ++i) {
		int u, v; cin >> u >> v;
        cout << u << " " << v << '\n';
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	init();

	int Q; cin >> Q;
    cout << Q << '\n';
    int prev_ans = 0;
	while(Q--) {
		int u, x; cin >> u >> x;
        cout << (prev_ans ^ u) << " " << (prev_ans ^ x) << '\n';
		--u;
		assert(x < N);
        int cur_anss = query(u, x) + 1;
        prev_ans = cur_anss;
	}

    clear_vars();
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
    int tc;
    cin >> tc;
    cout << tc << '\n';
    while (tc--)
        solve();
    return 0;
}
