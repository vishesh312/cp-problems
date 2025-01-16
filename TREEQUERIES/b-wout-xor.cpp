#include "bits/stdc++.h"
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
*/

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

using ll = long long;
const int mod = 1e9+7;

vector<vector<int>> adj;
vector<bool> vis;
int cur, ans, timer;

void dfs(int u) {
    vis[u] = true;
    if (cur == timer++)
        ans = u;
    sort(all(adj[u]));
    for (int v: adj[u])
        if (!vis[v])
            dfs(v);
}

void solve(int tc) {
    int n;
    cin >> n;
    adj.clear(); vis.clear();
    cur = ans = timer = 0;
    adj.resize(n); vis.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin >> q;
    int prev_ans = 0;
    for (int i = 0; i < q; ++i) {
        int u, x;
        cin >> u >> x;
        cerr << "og: " << u << " " << x << '\n';
//      u = prev_ans ^ u;
//      x = prev_ans ^ x;
        cerr << n << " " << u << " " << x << '\n';
        --u;
        cur = x, timer = 0;
        fill(all(vis), false);
        dfs(u);
        cout << ans + 1 << '\n';
        prev_ans = ans + 1;
        if (i > 10) break;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) solve(i);
    return 0;
}

