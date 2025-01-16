#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x.size())

const int mxN = 5000;
const int mxA = 1000 * 1000 * 1000;

void generate_testcase(int n, vector<ll> &vec, ll mn = 1, ll mx = mxA) {
    vec.clear();
    vec.resize(n);
    for (int i = 0; i < n; ++i)
        vec[i] = rnd.next(mn, mx);
}

void print_tc(int n, int k, ll x, vector<ll> &vec) {
    cout << n << " " << k << " " << x << '\n';
    for (int i = 0; i < n; ++i) {
        cout << vec[i];
        if (i < n-1)
            cout << " ";
    }
    cout << '\n';
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int testcases = 200, cur = 0;

    cout << testcases << '\n';

    vector<ll> vec;
    int n, k, x;

    // All numbers are same

    n = mxN;
    k = rnd.next(0, n/2);
    x = 1;
    generate_testcase(n, vec, 1, 1);
    print_tc(n, k, x, vec);

    n = mxN-1;
    k = rnd.next(0, n/2);
    x = 2;
    generate_testcase(n, vec, 1, 1);
    print_tc(n, k, x, vec);

    n = mxN;
    k = rnd.next(0, n/2);
    x = rnd.next(1, mxA);
    generate_testcase(n, vec, mxA, mxA);
    print_tc(n, k, x, vec);

    n = mxN-1;
    k = rnd.next(0, n/2);
    x = rnd.next(1, mxA);
    generate_testcase(n, vec, mxA, mxA);
    print_tc(n, k, x, vec);

    for (int i = 0; i < 46; ++i) {
        n = rnd.next(2500, mxN);
        k = rnd.next(0, n/2);
        int a = rnd.next(1, mxA);
        // x < 2a in half the cases
        if (i&1)
            x = rnd.next(1, min(mxA, a+a));
        else
            x = rnd.next(1, mxA);
        generate_testcase(n, vec, a, a);
        print_tc(n, k, x, vec);
    }

    cur += 50;

    // k = 0

    k = 0;

    for (int i = 0; i < 50; ++i) {
        n = rnd.next(2500, mxN);
        x = rnd.next(1, mxA);
        generate_testcase(n, vec);
        print_tc(n, k, x, vec);
        ++cur;
    }

    // x == 1

    x = 1;

    for (int i = 0; i < 50; ++i) {
        n = rnd.next(2500, mxN);
        if ((n&1) != (i&1))
            --n;
        k = rnd.next(0, n/2);
        generate_testcase(n, vec);
        print_tc(n, k, x, vec);
        ++cur;
    }

    // vec is sorted

    for (int i = 0; i < 50; ++i) {
        n = rnd.next(2500, mxN);
        if ((n&1) != (i&1))
            --n;
        k = rnd.next(0, n/2);
        x = rnd.next(1, mxA);
        generate_testcase(n, vec);
        sort(all(vec));
        print_tc(n, k, x, vec);
        ++cur;
    }

    cerr << "cur : " << cur << '\n';
    assert(cur == testcases);
}

