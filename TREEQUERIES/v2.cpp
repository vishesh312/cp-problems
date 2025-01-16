#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;

#define all(x) begin(x), end(x)

struct UnionFind {
    vector<int> link, siz;
    int cc;
    UnionFind(int n) {
        siz.resize(n, 1);
        link.resize(n);
        iota(all(link), 0);
        cc = n;
    }
    int find(int x) {
        if (x == link[x])
            return x;
        return link[x] = find(link[x]);
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b)
            return;
        if (siz[a] < siz[b])
            swap(a, b);
        siz[a] += siz[b];
        link[b] = a;
        --cc;
    }
};

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int test_cases = inf.readInt(1, 1000);
    inf.readEoln();
    int sum_n = 0, sum_q = 0;
    for (int tc = 0; tc < test_cases; ++tc) {
        setTestCase(tc + 1);
        int n = inf.readInt(1, 3'00'000);
        inf.readEoln();
        sum_n += n;
        set<pair<int, int>> edges;
        UnionFind uf(n);
        for (int i = 0; i < n-1; ++i) {
            int u = inf.readInt(1, n, "u_i");
            inf.readSpace();
            int v = inf.readInt(1, n, "v_i");
            inf.readEoln();
            --u, --v;
            ensuref(u != v, "Tree can't contain loops");
            ensuref(edges.count(make_pair(u, v)) == 0, "Tree can't contain multiple edges");

            edges.insert(make_pair(u, v));
            edges.insert(make_pair(v, u));

            ensuref(!uf.same(u, v), "Tree can't contain cycles");
            uf.unite(u, v);
        }

        int q = inf.readInt(1, 3'00'000);
        inf.readEoln();
        sum_q += q;

        int lim = (1<<19)-1;

        while (q--) {
            int u = inf.readInt(1, n);
            inf.readSpace();
            int x = inf.readInt(0, n-1);
            inf.readEoln();
        }

    }
    ensuref(sum_n <= 3'00'000, "nsum");
    ensuref(sum_q <= 3'00'000, "qsum");
    inf.readEof();
}
