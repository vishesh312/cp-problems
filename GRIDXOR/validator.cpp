#include "testlib.h"
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int tc = inf.readInt(1, 100, "tc");
    inf.readEoln();
    for (int i = 1; i <= tc; ++i) {
        setTestCase(i);
        int n = inf.readInt(1, 100, "n");
        inf.readEoln();
    }
    inf.readEof();
}
