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
    int t = 1000;
    cout << t << '\n';
    int mn = 1, mx = 100;
    cout << "3 6\n5 10\n8 7\n99 1\n55 55\n33 51\n54 146\n5436 627\n1527 5421\n";
    int i = 3;
    for (; i < t/10; ++i) {
        for (int j = 0; j < 3; ++j) {
            int a = rnd.next(mn, mx);
            int b = rnd.next(mn, mx);
            cout << a << " " << b << '\n';
        }
    }
    mx = 1'000'000'000;
    for (; i < t; ++i) {
        for (int j = 0; j < 3; ++j) {
            int a = rnd.next(mn, mx);
            int b = rnd.next(mn, mx);
            cout << a << " " << b << '\n';
        }
    }
}

