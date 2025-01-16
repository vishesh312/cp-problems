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

using ll = unsigned long long;
#define int ll
const int mod = 1e9+7;

int mx = 0;
vector<int> p, primes;
int cnt = 0;

void generate_mul(int cur, int pos) {
    if (pos == sz(primes)) {
        p.push_back(cur);
        ++cnt;
 //     if (cnt%10000==0) cerr << cnt << '\n';
        return;
    }
    int acur = cur;
    int curp = 1;
    for (int pwr = 0; acur * curp <= mx; ++pwr) {
        cur = acur * curp;
        curp *= primes[pos];
        generate_mul(cur, pos+1);
    }
}

void solve(int tc) {
    int n;
    int m;
    cin >> n >> m;
    mx = m;
    vector<int> pr(n);
    for (auto &x : pr)
        cin >> x;
    sort(all(pr));
    for (int x : pr)
        cerr << x << " ";
    cerr << '\n';
    for (int i = 0; i < n; i+=2)
        primes.push_back(pr[i]);
    for (int x : primes)
        cerr << x << " ";
    cerr << '\n';
    generate_mul(1, 0);
    auto p1 = p;
    sort(all(p1));
    p.clear(); primes.clear();
    for (int i = 1; i < n; i+=2)
        primes.push_back(pr[i]);
    generate_mul(1, 0);
    auto p2 = p;
    sort(all(p2));
    p.clear(); primes.clear();
    int ans = 0;
    for (int x : p1)
        ans += upper_bound(all(p2), m/x) - begin(p2);
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) solve(i);
    return 0;
}

