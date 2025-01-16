// tc same mn mx mxc wp
#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;

using ll = long long;

const int mx_n_f = 1'000'000;
vector<int> f(mx_n_f, 1), primes;
int cnt = 0;

void init() {
    for (int i = 2; i < mx_n_f; ++i)
        for (int j = i; j < mx_n_f; j += i)
            ++f[j];
    for (int i = 0; i < mx_n_f; ++i) {
        if (f[i] == 2) {
            ++cnt;
            primes.push_back(i);
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    init();
    // str stp rr
    int str = stoi(argv[1]), stp = stoi(argv[2]);
    bool rr = stoi(argv[3]);
    assert(str <= stp);
    int tc = (stp - str + 1);
    cout << tc << '\n';
    vector<pair<ll, ll>> v;
    for (int i = str; i <= stp; ++i) {
        ll p = (rr ? primes[rnd.next(cnt)] : primes[i]);
        ll lg = (log2(1'000'000'000'000'000'000LL)/log2(p));
        ll b = 1;
        while (lg--)
            b *= p;
        v.push_back({p,b});
    }
    shuffle(begin(v), end(v));
    for (auto [a, b]: v)
        cout << a << " " << b << '\n';
}

