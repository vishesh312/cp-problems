#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    // tc mn mx
    int tc = stoi(argv[1]), mn = stoi(argv[2]), mx = stoi(argv[3]);
    cout << tc << '\n';
    for (int i = 0; i < tc; ++i) {
        if (rnd.next(2)) {
            int n = rnd.next(mn, mx);
            if (n&1) --n;
            cout << n << '\n';
            string s = "";
            for (int i = 0; i < n/2; ++i)
                s += ('a' + rnd.next(26));
            cout << s + s << '\n';
        } else {
            int n = rnd.next(mn, mx);
            if (n&1) --n;
            cout << n << '\n';
            string s = "";
            for (int i = 0; i < n; ++i)
                s += ('a' + rnd.next(26));
            cout << s << '\n';
        }
    }
}

