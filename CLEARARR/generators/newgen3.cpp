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

    // x >= a[i] + a[j] for all a[i], a[j] and half of all n are even / odd

    for (int i = 0; i < 200; ++i) {
        n = rnd.next(2500, mxN);
        if ((n&1) != (i&1))
            --n;
        k = rnd.next(0, n/2);
        generate_testcase(n, vec);
        auto tmp = vec;
        sort(all(tmp));
        x = rnd.next(min((int)(tmp[n-1] + tmp[n-2]), mxA), mxA);
        print_tc(n, k, x, vec);
        ++cur;
    }

    cerr << "cur : " << cur << '\n';
    assert(cur == testcases);
}

