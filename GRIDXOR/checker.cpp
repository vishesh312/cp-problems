#include <bits/stdc++.h>
#include <spoj.h>
using namespace std;

int main() {
    spoj_init();
    int tc;
    const int mx = 1'000'000'000;
    fscanf(spoj_p_in, "%d", &tc);
    for (int t = 1; t <= tc; ++t) {
        int n;
        fscanf(spoj_p_in, "%d", &n);
        vector<vector<int>> v(n, vector<int>(n));
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                spoj_assert(fscanf(spoj_t_out, "%d", &v[a][b]) == 1);
                spoj_assert(v[a][b] <= mx and v[a][b] >= 1);
            }
        }
        int x = 0;
        for (int i = 0; i < n; ++i)
            x ^= v[i][0];
        int curx = 0;
        // all rows
        for (int i = 0; i < n; ++i) {
            curx = 0;
            for (int j = 0; j < n; ++j)
                curx ^= v[i][j];
            spoj_assert(curx == x);
        }
        // all columns
        for (int j = 0; j < n; ++j) {
            curx = 0;
            for (int i = 0; i < n; ++i)
                curx ^= v[i][j];
            spoj_assert(curx == x);
        }
        // diagonals
        curx = 0;
        for (int i = 0; i < n; ++i)
            curx ^= v[i][i];
        spoj_assert(curx == x);
        curx = 0;
        for (int i = 0; i < n; ++i)
            curx ^= v[i][n-1-i];
        spoj_assert(curx == x);
    }
    return SPOJ_RV_POSITIVE;
}

