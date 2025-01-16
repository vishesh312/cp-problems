#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int testCase = inf.readInt(1, 1000, "t");
    inf.readEoln();

    int nsum = 0, msum = 0;

    for (int test = 1; test <= testCase; ++test) {
        setTestCase(test);
        int n = inf.readInt(1, 2'00'000, "n");
        inf.readSpace();
        int m = inf.readInt(0, 2'00'000, "m");
        inf.readEoln();

        nsum += n;
        msum += m;

        set<pair<int, int>> s;
        for (int i = 0; i < m; ++i) {
            int u = inf.readInt(1, n, "u");
            inf.readSpace();
            int v = inf.readInt(1, n, "v");
            inf.readEoln();
            if (u > v)
                swap(u, v);
            ensuref(u != v, "Graph can't have self loops");
            ensuref(!s.count({u, v}), "Graph can't have multiple edges");
            s.insert({u, v});
        }
    }

    ensuref(nsum <= 2'00'000, "sum of n more than limit");
    ensuref(msum <= 2'00'000, "sum of m more than limit");

    inf.readEof();
}
