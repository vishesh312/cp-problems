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
    int t = 100;
    cout << t << '\n';
    vector<int> v(100);
    iota(all(v), 1);
    shuffle(all(v));
    for (int x : v)
        cout << x << '\n';
}
