#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int tc = inf.readInt(1, 3000, "tc");
    inf.readEoln();
 
    for (int i = 0; i < tc; ++i) {
        setTestCase(i+1);
        int n = inf.readInt(1, 1000);
        inf.readEoln();
        string s = inf.readToken("[a-z]{1,1000}");
        ensuref((int)s.size() % 2 == 0, "n is odd");
        ensuref((int)s.size() == n, "n is wrong");
        inf.readEoln();
    }
 
    inf.readEof();
}
