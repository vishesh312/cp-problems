#include "testlib.h"
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int tc = inf.readInt(1, 1000, "tc");
    inf.readEoln();
    for (int i = 1; i <= tc; ++i) {
        setTestCase(i);
        for (int i = 0; i < 3; ++i) {
            int a = inf.readInt(1, 1'000'000'000, "a");
            inf.readSpace();
            int b = inf.readInt(1, 1'000'000'000, "b");
            inf.readEoln();
        }
    }
    inf.readEof();
}
