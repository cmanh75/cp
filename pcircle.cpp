//problem "pcircle"
//created in 21:07:15 - Wed 09/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int x[N], d[N], l[N], n, f[N][24], sl = 0;
int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

void cal(int i) {
    if (i > n * 2) {
        if (l[x[n * 2] + x[1]]) {
            sl++;
            for (int j = 1; j <= n * 2; j++) {
                f[sl][j] = x[j];
            }
        }
        return;
    }
    for (int j = 2; j <= n * 2; j++) {
        if (!d[j] && l[j + x[i - 1]]) {
            d[j] = 1;
            x[i] = j;
            cal(i + 1);
            d[j] = 0;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < 12; i++) {
        l[a[i]] = 1;
    }
    x[1] = 1;
    cal(2);
    cout << sl << "\n";
    for (int j = 1; j <= min(sl, 10000); j++) {
        for (int i = 1; i <= 2 * n; i++) {
            cout << f[j][i] << " ";
        }
        cout << "\n";
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