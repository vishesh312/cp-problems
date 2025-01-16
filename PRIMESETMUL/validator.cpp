#include "testlib.h"
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int mxp = 1005;
    vector<int> f(mxp, 1);
    vector<bool> isprime(mxp);
    for (int i = 2; i < mxp; ++i)
        for (int j = i; j < mxp; j+=i)
            ++f[j];
    for (int i = 2; i < mxp; ++i)
        if (f[i] == 2)
            isprime[i] = true;

    int tc = inf.readInt(1, 2, "tc");
    inf.readEoln();
    for (int i = 1; i <= tc; ++i) {
        setTestCase(i);
        int n = inf.readInt(1, 20, "n");
        inf.readSpace();
        long long m = inf.readLong(1, 1'000'000'000'000'000'0LL, "m");
        inf.readEoln();
        vector<int> s = inf.readInts(n, 1, 1000, "s");
        inf.readEoln();
        for (int i = 0; i < n; ++i)
            ensuref(isprime[s[i]], "%d at index %d is not prime", s[i], i);
    }
    inf.readEof();
}
