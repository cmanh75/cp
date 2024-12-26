//problem "65-marisa"
//created in 09:48:38 - Thu 07/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];
long long f[N];

long long get(int i, int j) {
    if (i <= j) {
        return f[j + 1] - f[i];
    }
    return f[n] - (f[i] - f[j + 1]);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[i + 1] = f[i] + a[i];
    }
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += 1ll * min(i, n - i) * a[i];
    }
    long long ans = s;
    for (int i = 1; i < n; i++) {
        s += get((i + n / 2) % n, (i - 1 + n) % n) - get(i , (i + n / 2 - 1) % n) - a[(i + n / 2) % n] * (n % 2 != 0);
        // cout << s << "\n";
        ans = min(ans, s);
    }
    cout << ans << "\n";
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