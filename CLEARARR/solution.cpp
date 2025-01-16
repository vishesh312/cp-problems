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
    int n, k;
    ll x;
    cin >> n >> k >> x;
    priority_queue<ll> pq;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        pq.push(a);
    }
    ll ans = 0;
    while (k-- and sz(pq) > 1) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        if (a + b < x) {
            pq.push(a);
            pq.push(b);
            break;
        }
        ans += x;
    }
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) solve(i);
    return 0;
}

