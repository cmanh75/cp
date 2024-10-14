//problem "ccc22s3-DMOJ"
//created in 00:23:33 - Sun 13/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N];

void solve() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    int z = min(m, n);
    if (1ll * z * (z + 1) / 2 + 1ll * (n - z) * z < k || k < n) {
        cout << -1;
        return;
    } 
    int j = z;
    for (int i = 1; i <= z; i++) {
        if (k - i < n - i) {
            j = i - 1;
            break;
        }
        else {
            k -= i;
            a[i] = i;
        }
    }
    for (int i = j + 1; i <= n; i++) {
        if (k - j <= n - i) {
            a[i] = a[i - (k - (n - i))];
            for (int h = i + 1; h <= n; h++) {
                a[h] = a[h - 1];
            }
            break;
        }
        else {
            a[i] = a[i - j];
            k -= j;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
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