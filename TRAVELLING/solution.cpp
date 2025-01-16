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
const int inf = (1<<30);

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<bool> hasedge(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (u > v)
            swap(u, v);
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 0});
        if (u + 1 == v)
            hasedge[u] = true;
    }
    for (int i = 0; i < n-1; ++i) {
        if (!hasedge[i]) {
            adj[i].push_back({i+1, 1});
            adj[i+1].push_back({i, 1});
        }
    }
    vector<int> dist(n, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d)
            continue;
        for (auto [v, w]: adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[n-1] << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) solve(i);
    return 0;
}

