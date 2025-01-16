#include "bits/stdc++.h"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long int;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());


int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	const int LOG = 19;

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<int>> adj(n+1);
		for (int i = 1; i < n; ++i) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 1; i <= n; ++i) sort(begin(adj[i]), end(adj[i]));

		vector<int> tin(n+1), ord, subsz(n+1, 1), enter(n+1);
		vector<array<int, LOG>> anc(n+1), left(n+1), right(n+1);
		int timer = 0;
		auto dfs = [&] (const auto &self, int u, int par) -> void {
			tin[u] = timer++;
			ord.push_back(u);
			for (int i = 1; i < LOG; ++i) anc[u][i] = anc[anc[u][i-1]][i-1];
			for (int v : adj[u]) {
				if (v == par) {
					left[u][0] = timer - tin[u];
					continue;
				}
				anc[v][0] = u;
				self(self, v, u);
				subsz[u] += subsz[v];
			}
			right[u][0] = left[u][0] + n - subsz[u] - 1;
			for (int v : adj[u]) {
				if (v == par) continue;
				enter[v] = tin[v] - tin[u];
				if (v > par) enter[v] += n - subsz[u];
			}
		};
		auto kth = [&] (int u, int k) {
			for (int i = LOG - 1; i >= 0; --i) {
				if (k >= (1 << i)) {
					k -= 1 << i;
					u = anc[u][i];
				}
			}
			return u;
		};
		auto upd = [&] (auto &table, int u, int i) {
			table[u][i] = left[u][i-1] + table[anc[u][i-1]][i-1];
			if (anc[u][i-1] > 1) {
				int x = kth(u, (1 << (i-1)) - 1);
				if (x < anc[x][1]) table[u][i] -= subsz[x];
			}
		};
		auto query = [&] (int u, int x) {
			for (int i = LOG - 1; i >= 0; --i) {
				if (anc[u][i] and x >= left[u][i] and x <= right[u][i]) {
					int y = kth(u, (1 << i) - 1);
					x -= left[u][i];
					if (enter[y] <= x) x += subsz[y];
					u = anc[u][i];
				}
			}
			return ord[x + tin[u] - (x >= left[u][0])*(n - subsz[u])];
		};
		dfs(dfs, 1, 0);
		for (int i = 1; i < LOG; ++i) {
			for (int u = 1; u <= n; ++u) {
				upd(left, u, i);
				upd(right, u, i);
			}
		}

		int q, ans = 0; cin >> q;
		while (q--) {
			int u, x; cin >> u >> x;
			u ^= ans;
			x ^= ans;
			ans = query(u, x);
			cout << ans << '\n';
		}
	}
}
