//problem "ccc14s1-DMOJ"
//created in 10:19:16 - Sun 13/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], m, d[N], k, b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= n; j++) {
            d[j] = true;
        }
        for (int j = x; j <= n; j += x) {
            d[j] = false;
        }
        k = 0;
        for (int j = 1; j <= n; j++) {
            if (d[j] == true) {
                k++;
                b[k] = a[j];
            }
        }
        n = k;
        for (int j = 1; j <= n; j++) {
            a[j] = b[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << "\n";
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