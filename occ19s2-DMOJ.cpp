//problem "occ19s2-DMOJ"
//created in 20:53:58 - Wed 09/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int x[N], ans, n;
long long m;

void cal(int i) {
    if (i > n) {
        long long z = 0;
        for (int j = 1; j <= n; j++) {
            if (x[j] == 0) {
                z = z * 10 + 2;
            }
            else {
                z = z * 10 + 3;
            }
        }
        if (z <= m) {
            ans++;
        }
        return;
    }
    x[i] = 0;
    cal(i + 1);
    x[i] = 1;
    cal(i + 1);
}

void solve() {
    cin >> m;
    long long z = m;
    while (z != 0) {
        n++;
        z /= 10;
    }
    int k = n;
    for (int i = 1; i <= k; i++) {
        n = i;
        cal(1);
    }
    cout << ans;
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