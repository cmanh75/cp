//problem "ccc13s1-DMOJ"
//created in 09:37:08 - Sun 13/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int d[20];

void solve() {
    int n;
    cin >> n;
    n++;
    while (1) {
        int x = n;
        for (int i = 0; i < 10; i++) {
            d[i] = 0;
        }
        int ok = 0;
        while (x != 0) {
            if (d[x % 10]) {
                ok = 1;
                break;
            }
            d[x % 10] = 1;
            x /= 10;
        }
        if (!ok) {
            cout << n;
            return;
        }
        n++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test = 1;
    while (test--) {
        solve();
    }
}