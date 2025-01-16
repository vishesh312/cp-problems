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

    // 200 testcases with n = 5000, k is >= n/4

    for (int i = 0; i < testcases; ++i) {
        int n = mxN - (i&1);
        int k = rnd.next(n/4, n/2);
        int x = rnd.next(1, mxA);
        vector<ll> vec;
        generate_testcase(n, vec);
        print_tc(n, k, x, vec);
        ++cur;
    }
    cerr << "cur : " << cur << '\n';
    assert(cur == testcases);
}
