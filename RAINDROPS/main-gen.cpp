#include "testlib.h"
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

vector<pair<int, int>> make_tree(int n, int w = 0) { // makes random tree with N nodes
    vector<int> p(n);
    for (int i = 1; i < n; ++i)
        p[i] = rnd.wnext(i, w);

    vector<int> perm(n);
    iota(all(perm), 0);
    shuffle(perm.begin() + 1, perm.end());
    vector<pair<int,int>> edges;

    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));

    shuffle(edges.begin(), edges.end());
    return edges;
}

vector<int> make_gaps(int m, int mxd, int w) { // makes a with around 2/3 gaps <= mxd
    vector<int> gaps;
    int sum = 1'000'000'000;
    for (int i = 0; i < m; ++i) {
        if (rnd.next(3) or (sum-(m-i-1))-(mxd+1) <= 0) {
            int x = rnd.next(1, min(sum-(m-i-1),mxd));
            sum -= x;
            gaps.push_back(x);
        } else {
            int x = mxd+1 + rnd.wnext((sum-(m-i-1))-(mxd+1), w);
            sum -= x;
            gaps.push_back(x);
        }
    }
    vector<int> ret(m);
    ret[0] = gaps[0];
    for (int i = 1; i < m; ++i)
        ret[i] = ret[i-1] + gaps[i];
    return ret;
}

vector<vector<int>> adj;
vector<int> dist;

void dfs(int u, int p = -1) {
    for (int v : adj[u]) {
        if (v != p) {
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    // nn tree_w min_w mm
    int nn = atoi(argv[1]);
    int tree_w = atoi(argv[2]);
    int min_w = atoi(argv[3]);
    int mm = atoi(argv[4]);
    int mxn = 500000;
    int t = mxn/nn;
    t = min(t, 1000);
    cout << t << '\n';
    while (t--) {
        int m = rnd.next(1, mm);
        cout << nn << " " << m << '\n';
        adj.clear(); dist.clear();
        adj.resize(nn); dist.resize(nn);
        auto edges = make_tree(nn, tree_w);
        for (auto [u, v] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            cout << u+1 << " " << v+1 << '\n';
        }
        dfs(0);
        int mxd = *max_element(all(dist));
        auto a = make_gaps(m, mxd, min_w);
        for (int i = 0; i < m; ++i) {
            cout << a[i];
            if (i < m-1)
                cout << " ";
        }
        cout << '\n';
    }
}
