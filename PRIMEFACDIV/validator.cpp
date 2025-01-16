#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int testCount = inf.readInt(1, 100000, "testCount");
    inf.readEoln();
    for (int i = 0; i < testCount; i++) {
        setTestCase(i + 1);
        inf.readLong(1LL, 1'000'000'000'000'000'000LL, "a");
        inf.readSpace();
        inf.readLong(1LL, 1'000'000'000'000'000'000LL, "b");
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}
