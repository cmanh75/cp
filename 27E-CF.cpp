//problem "27E-CF"
//created in 15:43:41 - Thu 05/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
const long long oo = 1e18;
long long dp[12][1024];
int s[] = {2, 3, 5, 7, 11, 13, 17, 19, 21, 23};

void solve() {
    cin >> n;
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 1000; j++) {
            dp[i][j] = 1e18;
        }
    }
    dp[0][1] = 1;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            long long u = dp[i - 1][j];
            int z = s[i - 1];
            for (int k = 1; j * (k + 1) <= n && u <= oo / z; u = u * z, k++) {
                dp[i][j * (k + 1)] = min(dp[i][j * (k + 1)], u * z);
            }
        }
    }
    cout << dp[10][n];
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