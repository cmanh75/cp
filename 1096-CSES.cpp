//problem "1096-CSES"
//created in 22:41:36 - Sun 25/08/2024
#include<bits/stdc++.h>
using namespace std;

typedef vector < vector < int > > vvi;
const int N = 1e5 + 5;
const int M = 1e5;
const int mod = 1e9 + 7;
long long n, f[11];
 
vvi operator * (vvi a, vvi b) {
    vvi c(6, vector < int > (6, 0));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                c[i][j] = (c[i][j] + 1ll * a[i][k] * b[k][j] % mod) % mod;
            }
        }
    }
    return c;
}
 
vvi power(vvi a, long long b) {
    if (b == 1) {
        return a;
    } 
    vvi t = power(a, b / 2);
    if (b & 1) {
        return t * t * a;
    }
    return t * t;
}
 
void solve() {
    cin >> n;
    vvi a(6, vector < int >(6, 0));
    vvi b(6, vector < int >(6, 0));
    for (int i = 0; i < 6; i++) {
        a[i][5] = 1;
    }
    for (int i = 0; i < 5; i++) {
        a[i + 1][i] = 1;
    }
    f[0] = 1;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= min(i, 6); j++) {
            f[i] = f[i] + f[i - j];
        }
    }
    for (int i = 0; i < 6; i++) {
        b[0][i] = f[i + 1];
    }
    if (n <= 6) {
        cout << f[n] << "\n";
        return;
    }
    vvi d = (b * power(a, n - 6));
    cout << d[0][5];
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