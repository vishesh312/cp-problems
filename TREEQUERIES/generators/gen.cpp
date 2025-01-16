// tc mn_n mx_n mn_q mx_q t_w q_w q_w_2

#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;

#define all(x) begin(x), end(x)

const int n_lim = 3'00'000, q_lim = 3'00'000;

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

void dfs(int u, int p, int dist, vector<vector<int>> &dpt, vector<vector<int>> &adj) {
    dpt[dist].push_back(u);
    for (int v: adj[u]) {
        if (v != p) {
            dfs(v, u, dist+1, dpt, adj);
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    cin.tie(0)->sync_with_stdio(0);
    int tc = stoi(argv[1]), mn_n = stoi(argv[2]), mx_n = stoi(argv[3]), mn_q = stoi(argv[4]), mx_q = stoi(argv[5]), t_w = stoi(argv[6]), q_w = stoi(argv[7]), q_w_2 = stoi(argv[8]);
    cout << tc << '\n';
    for (int i = 0; i < tc; ++i) {
        int n = rnd.next(mn_n, mx_n);
        cout << n << '\n';

        vector<pair<int, int>> edges = make_tree(n, t_w);
        vector<vector<int>> depth(n);
        vector<vector<int>> adj(n);
        for (auto [u, v]: edges) {
            cout << u+1 << " " << v+1 << '\n';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, 0, depth, adj);
        int mx_d = n-1;
        while (depth[mx_d].empty())
            --mx_d;
        
        int q = rnd.next(mn_q, mx_q);
        cout << q << '\n';
        while (q--) {
            int d = rnd.wnext(mx_d+1, q_w);
            int u = depth[d][rnd.next((int)depth[d].size())];
            int x = rnd.wnext(n, q_w_2);
            assert(x < n);
            cout << u+1 << " " << x << '\n';
        }
    }
}

