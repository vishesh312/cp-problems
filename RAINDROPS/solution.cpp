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
vector<int> leaf; //leaf[i] = number of leaf at dist i
vector<int> dist;
ll tot;

void dfs(int u, int p = -1) {
    for (int v : adj[u]) {
        if (v != p) {
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
    }
    if (sz(adj[u]) == 1 and u != 0) {
        tot++;
        leaf[dist[u]]++;
    }
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    tot = 0;
    adj.clear(); leaf.clear(); dist.clear();
    adj.resize(n); leaf.resize(n); dist.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> a(m+1);
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    dfs(0);
    ll mxd = n-1;
    while (leaf[mxd] == 0)
        --mxd;
    vector<ll> l(mxd+1);
    ll cursum = 0;
    for (int i = 1; i <= mxd; ++i) {
        l[i] = l[i-1] + (cursum + leaf[i-1]);
        cursum += leaf[i-1];
    }
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        ll t = a[i] - a[i-1];
        if (t <= mxd)
            ans += l[t];
        else
            ans += l[mxd] + (t - mxd) * tot;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) solve(i);
    return 0;
}

