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

void solve(int tc) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x: v)
        cin >> x;
    int mn = *min_element(all(v));
    bool f = true;
    for (int x: v) {
        if (x % mn != 0) {
            f = false;
            break;
        }
    }
    if (f) {
        cout << n - count(all(v), mn) << '\n';
    } else {
        cout << n << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) solve(i);
    return 0;
}
