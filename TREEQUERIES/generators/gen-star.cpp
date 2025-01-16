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

pair<vector<pair<int, int>>, int> make_star(int n) {
    int root = rnd.next(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        if (i != root) {
            if (rnd.next(2))
                edges.push_back(make_pair(i, root));
            else
                edges.push_back(make_pair(root, i));
        }
    }
    shuffle(edges.begin(), edges.end());
    return make_pair(edges, root);
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
    int tc = stoi(argv[1]), nn = stoi(argv[2]), qq = stoi(argv[3]);
    cout << tc << '\n';
    for (int i = 0; i < tc; ++i) {
        int n = nn;
        cout << n << '\n';

        auto [edges, root] = make_star(n);
        for (auto [u, v]: edges) {
            cout << u+1 << " " << v+1 << '\n';
        }

        int q = qq*nn;
        cout << q << '\n';
        vector<pair<int, int>> queries;
        for (int i = 0; i < n; ++i) {
            for (int j = n-1, c = 0; j >= 0, c < qq; --j, ++c) {
                queries.push_back({i, j});
            }
        }
        shuffle(begin(queries), end(queries));
        for (auto [u, x]: queries)
            cout << u+1 << " " << x << '\n';
    }
}

