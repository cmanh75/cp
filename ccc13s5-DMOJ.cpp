//problem "ccc13s5-DMOJ"
//created in 23:17:12 - Sat 12/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
int dp[N];

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    while (n != 1) {
        int ok = 0;
        for (int j = 2; j <= sqrt(n); j++) {
            if (n % j == 0) {
                ans += j - 1;
                ok = 1;
                n -= n / j;
                break;
            }
        }
        if (!ok) {
            ans += n - 1;
            n--;
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