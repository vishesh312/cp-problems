#include "bits/stdc++.h"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    // tc mn_n mx_n mn_a mx_a mn_g mx_g mn_c mx_c
    // do around 2/3 with gcd others random
    int tc = stoi(argv[1]), mn_n = stoi(argv[2]), mx_n = stoi(argv[3]), mn_a = stoi(argv[4]), mx_a = stoi(argv[5]);
    int mn_g = stoi(argv[6]), mx_g = stoi(argv[7]), mn_c = stoi(argv[8]), mx_c = stoi(argv[9]);
    cout << tc << '\n';
    for (int i = 0; i < tc; ++i) {
        int n = rnd.next(mn_n, mx_n);
        cout << n << '\n';
        if (rnd.next(3)) {
            int g = rnd.next(mn_g, mx_g);
            int c = rnd.next(min(n, mn_c), min(n, mx_c));
            vector<int> v;
            for (int i = 0; i < n-c; ++i)
                v.push_back(g * rnd.next(1, mx_a / g));
            for (int i = 0; i < c; ++i)
                v.push_back(g);
            shuffle(begin(v), end(v));
            for (int i = 0; i < n; ++i) {
                cout << v[i];
                if (i < n-1) {
                    cout << " ";
                } else {
                    cout << '\n';
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                cout << rnd.next(mn_a, mx_a);
                if (i < n-1) {
                    cout << " ";
                } else {
                    cout << '\n';
                }
            }
        }
    }
}

