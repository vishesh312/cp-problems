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
const int mx = (1<<20);;

vector<int> dp(mx, -1);

int calc(int mask) {
    if (dp[mask] != -1)
        return dp[mask];
    if (mask == 1)
        return dp[mask] = 0;
    int ans = (1<<30);
    for (int i = 0; i < 20; ++i) {
        //shift i to the right
        int nmask = mask;
        for (int j = i; j < 20; ++j) {
            if (nmask&(1<<j)) {
                nmask ^= (1<<j);
                nmask |= (1<<(j-i));
            }
        }
        if (mask != nmask) ans = min(ans, calc(nmask) + 1);
    }
    return dp[mask] = ans;
}

void pre() {
    for (int i = 1; i < mx; ++i)
        if (dp[i] == -1)
            calc(i);
}

void solve(int tc) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        int temp = 1;
        while (v[i] % 2 == 0) {
            v[i] /= 2;
            temp *= 2;
        }
        v[i] = temp;
    }
    vector<map<int, int>> masks(n);
    masks[0][v[0]] = 1;
    for (int i = 1; i < n; ++i) {
        masks[i][v[i]] = 1;
        for (auto [mask, len] : masks[i-1]) {
            int nmask = mask | v[i];
            masks[i][nmask] = max(masks[i][nmask], len+1);
        }
    }
    /*for (int i = 0; i < n; ++i) {
        cout << i << ":\n";
        for (auto [a, b] : masks[i])
            cout << a << " " << b << '\n';
    }*/
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int prev = 0;
        for (auto [mask, len] : masks[i]) {
            ans += dp[mask] * (len - prev);
            prev = len;
        }
    }
//  cerr << "mx:" << *max_element(all(dp)) << '\n';
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    pre();
    for (int i = 1; i <= tc; ++i) solve(i);
    return 0;
}

