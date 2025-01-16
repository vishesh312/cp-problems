#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int testCount = inf.readInt(1, 1000, "testCount");
    inf.readEoln();
    
    for (int i = 0; i < testCount; i++) {
        setTestCase(i + 1);
        int n = inf.readInt(1, 3000, "n");
        inf.readEoln();
        inf.readInts(n, 1, 1'000'000'000, "a");
        inf.readEoln();
    }
 
    inf.readEof();
    return 0;
}
