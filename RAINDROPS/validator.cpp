#include "testlib.h"
#include "bits/stdc++.h"
using namespace std;

int total_n = 0;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void valtc() {
    int n = inf.readInt(1, 100000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 100000, "m");
    inf.readEoln();
    total_n += n;
    adj.clear(); vis.clear();
    adj.resize(n); vis.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readEoln();
        ensuref(u != v, "u is equal to v which is %d", u);
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < n; ++i)
        ensuref(vis[i], "%d is not visited", i);
    vector<int> a = inf.readInts(m, 1, 1'000'000'000, "a");
    inf.readEoln();
    for (int i = 1; i < m; ++i)
        ensuref(a[i] > a[i-1], "%d : %d and %d : %d", i, a[i], i-1, a[i-1]);
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int tc = inf.readInt(1, 1000, "tc");
    inf.readEoln();
    for (int i = 1; i <= tc; ++i) {
        setTestCase(i);
        valtc();
    }
    ensuref(total_n <= 500000, "total n is %d", total_n); 
    inf.readEof();
}
