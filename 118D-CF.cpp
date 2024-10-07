//problem "118D-CF"
//created in 15:31:13 - Sun 06/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 100000000;
int dp[205][105][2];

void add(int &x, int y) {
   x = (x + y) % mod; 
}

void solve() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int i = 1; i <= n1 + n2; i++) {
        for (int j = 0; j <= min(i, n1); j++) {
            if (i - j <= n2) {
                for (int h = 1; h <= k2; h++) {
                    if (i >= h) {
                        add(dp[i][j][1], dp[i - h][j][0]);
                    }
                }
                for (int h = 1; h <= k1; h++) {
                    if (j >= h) {
                        add(dp[i][j][0], dp[i - h][j - h][1]);
                    }
                }
            }
        }
    }
    cout << (dp[n1 + n2][n1][1] + dp[n1 + n2][n1][0]) % mod;
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