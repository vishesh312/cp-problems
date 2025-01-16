#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

#define sz(x) (int)x.size()
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

const int MAXN = 2'00'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int nn = atoi(argv[1]);
    int we = atoi(argv[2]);
    bool connected = atoi(argv[3]);
    bool exact = atoi(argv[4]);
    int t = min(MAXN/nn, MAXN/((nn*(nn-1))/2));

    cout << t << '\n';

    while (t--) {
        int n = exact ? nn : rnd.next(2, nn);
        long long an = n;
        int m = rnd.wnext(0LL, (an*(an-1))/2, we);
        UnionFind uf(n);
        
        cout << n << " " << m << '\n';

        set<pair<int, int>> s;

        for (int i = 0; i < m; ++i) {
            int u = -1, v = -1;
            int a = uf.find(0), b = uf.find(n-1);
            if (a > b)
                swap(a, b);
            while (true) {
                u = rnd.next(0, n-1);
                v = rnd.next(0, n-1);
                if (u == v)
                    continue;
                if (u > v)
                    swap(u, v);
                if (s.count({u, v}))
                    continue;
                int c = uf.find(u), d = uf.find(v);
                if (c > d)
                    swap(c, d);
                if (!connected and c == a and d == b)
                    continue;
                s.insert({u, v});
                uf.unite(u, v);
                if (rnd.next(1))
                    swap(u, v);
                cout << u+1 << " " << v+1 << '\n';
                break;
            }
        }
    }
}
