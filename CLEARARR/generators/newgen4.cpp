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

    // need to do M operations of third kind where 0 < M < k

    for (int i = 0; i < 100; ++i) {
        n = rnd.next(2500, mxN);
        if ((n&1) != (i&1))
            --n;
        k = rnd.next(2, n/2);
        int m = rnd.next(1, k-1);
        x = rnd.next(2, mxA);
        vec.clear();
        for (int j = 0; j < m; ++j) {
            ll sum = rnd.next(x+1, (int)(mxA+mxA));
            ll a = sum / 2;
            ll b = sum - a;
            vec.push_back(a);
            vec.push_back(b);
        }
        int left = n - sz(vec);
        for (int j = 0; j < left; ++j) {
            int sum = rnd.next(2, x);
            ll a = rnd.next(1, sum-1);
            ll b = sum - a;
            vec.push_back(a);
            vec.push_back(b);
        }
        shuffle(all(vec));
        print_tc(n, k, x, vec);
        ++cur;
    }

    // do exactly k operations of third kind

    for (int i = 0; i < 100; ++i) {
        n = rnd.next(2500, mxN);
        if ((n&1) != (i&1))
            --n;
        k = rnd.next(0, n/2);
        x = rnd.next(1, mxA);
        vec.clear();
        for (int j = 0; j < k; ++j) {
            int sum = rnd.next(x+1, mxA+mxA);
            ll a = sum / 2;
            ll b = sum - a;
            vec.push_back(a);
            vec.push_back(b);
        }
        int left = n - sz(vec);
        for (int j = 0; j < left; ++j) {
            int sum = rnd.next(2, x);
            ll a = rnd.next(1, sum-1);
            ll b = sum - a;
            vec.push_back(a);
            vec.push_back(b);
        }
        shuffle(all(vec));
        print_tc(n, k, x, vec);
        ++cur;
    }


    cerr << "cur : " << cur << '\n';
    assert(cur == testcases);
}

