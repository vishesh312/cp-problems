// tc same mn mx mxc wp
#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;

using ll = long long;

vector<ll> get_prime_factors(ll n) {
    vector<ll> ret;
    if (n % 2 == 0)
        ret.push_back(2);
    while (n % 2 == 0)
        n /= 2;
    for (int i = 3; i * i <= min(1'000'000LL, n); i += 2) {
        if (n % i == 0)
            ret.push_back(i);
        while (n % i == 0)
            n /= i;
    }
    if (n > 2)
        ret.push_back(n);
    return ret;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    // tc same mn mx mxc wp
    int tc = stoi(argv[1]);
    bool same = stoi(argv[2]);
    ll mn = stoll(argv[3]), mx = stoll(argv[4]);
    int mxc = stoi(argv[5]), wp = stoi(argv[6]);
    cout << tc << '\n';
    for (int i = 0; i < tc; ++i) {
        if (same) {
            ll a = rnd.next(mn, mx);
            cout << a << " " << a << '\n';
            continue;
        }
        if (!rnd.next(3)) {
            ll a = rnd.next(mn, mx);
            ll b = rnd.next(mn, mx);
            cout << a << " " << b << '\n';
        } else {
            ll g = rnd.next(1LL, mx);
            ll a = g * rnd.next(1LL, mx/g);
            ll b = g;
            vector<ll> v = get_prime_factors(g);
            sort(begin(v), end(v));
            int c = rnd.next(1, mxc);
            while (c--) {
                ll mx_p = 1'000'000'000'000'000'000LL / b;
                int ub = upper_bound(begin(v), end(v), mx_p) - begin(v);
                if (!ub) break;
                int id = rnd.wnext(ub, wp);
                b *= v[id];
            }
            cout << a << " " << b << '\n';
        }
    }
}

