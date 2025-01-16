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
    // nn mask_f mask_mx
    // nn mask_f mask_n [...]
    int nn = atoi(argv[1]);
    int mask_f = atoi(argv[2]);
    int mask_n = -1, mask_mx = -1;
    vector<int> masks_to_use;
    if (mask_f) {
        mask_n = atoi(argv[3]);
        for (int i = 4, j = 0; j < mask_n; ++i, ++j) 
            masks_to_use.push_back(atoi(argv[i]));
    } else {
        mask_mx = atoi(argv[3]);
    }
    int t = min(1000, 5'00'000/nn);
    cout << t << '\n';
    for (int tt = 0; tt < t; ++tt) {
        int mask = (mask_f ? rnd.any(masks_to_use) : rnd.next(1, mask_mx));
        cerr << "mask : " << bitset<20>(mask).to_string() << '\n';
        assert(__builtin_popcount(mask) <= nn);
        int n = nn;
        cout << n << '\n';
        vector<int> v;
        for (int i = 0; i < 20; ++i)
            if (mask & (1<<i))
                v.push_back(1<<i);
        vector<int> a(n);
        for (int i = 0; i < sz(v); ++i) {
            int x = rnd.next(1, 1'000'000/v[i]);
            x -= (x % 2 == 0);
            a[i] = v[i] * x;
        }
        for (int i = sz(v); i < n; ++i) {
            int x = rnd.any(v);
            int y = rnd.next(1, 1'000'000/x);
            y -= (y % 2 == 0);
            a[i] = x * y;
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i];
            if (i < n-1)
                cout << " ";
        }
        cout << '\n';
    }
}
