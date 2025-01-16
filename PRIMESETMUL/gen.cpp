#include "testlib.h"
#include "bits/stdc++.h"
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
*/

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

using ll = long long;
const int mod = 1e9+7;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int max_p = atoi(argv[1]);
    int weight = atoi(argv[2]);
    int nn = atoi(argv[3]);
    int nc = atoi(argv[4]);
    int t = 2;
    cout << t << '\n';
    int mxp = 1005;
    vector<int> primes, f(mxp, 1);
    for (int i = 2; i < mxp; ++i)
        for (int j = i; j < mxp; j+=i)
            ++f[j];
    for (int i = 1; i <= max_p; ++i)
        if (f[i] == 2)
            primes.push_back(i);
    for (int i = 0; i < t; ++i) {
        int n = (nc ? nn : rnd.next(1, nn));
        assert(sz(primes) >= n);
        shuffle(all(primes));
        vector<int> s(begin(primes), begin(primes)+n);
        ll m = rnd.wnext(1LL, 1'000'000'000'000'000'0LL, weight); 
        cout << n << " " << m << '\n';
        for (int j = 0; j < n; ++j) {
            cout << s[j];
            if (j < n-1)
                cout << " ";
        }
        cout << '\n';
    }
}
