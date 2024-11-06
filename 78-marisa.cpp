//problem "78-marisa"
//created in 20:52:58 - Mon 28/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];
long long s[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long s = 0, ans = 0;
    int j = 1;
    for (int i = 1; i <= n; i++) {
        s += a[i];
        while (s - a[j] >= k) {
            s -= a[j];
            j++;
        }
        if (s >= k) {
            ans += j;
        }
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