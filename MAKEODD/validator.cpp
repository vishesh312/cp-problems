#include "testlib.h"
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int tc = inf.readInt(1, 1000, "tc");
    inf.readEoln();
    int sum_n = 0;
    for (int i = 1; i <= tc; ++i) {
        setTestCase(i);
        int n = inf.readInt(1, 1'00'000, "n");
        inf.readEoln();
        sum_n += n;
        vector<int> a = inf.readInts(n, 1, 1'000'000, "a");
        inf.readEoln();
    }
    ensuref(sum_n <= 5'00'000, "sum of n is %d", sum_n);
    inf.readEof();
}
