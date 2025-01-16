#include "testlib.h"
#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int mxN = 5000;
    const int mxA = 1000 * 1000 * 1000;
    const int mxT = 200;

    int tests = inf.readInt(1, mxT, "tests");
    inf.readEoln();

    for (int t = 1; t <= tests; ++t) {
        setTestCase(t);
        int n = inf.readInt(1, mxN, "n");
        inf.readSpace();
        int k = inf.readInt(0, n/2, "k");
        inf.readSpace();
        long long x = inf.readLong(1LL, (long long)mxA, "x");
        inf.readEoln();

        std::vector<long long> v = inf.readLongs(n, 1LL, (long long)mxA, "a");
        inf.readEoln();
    }

    inf.readEof();
}

