//problem "longescomtstr"
//created in 21:49:31 - Wed 27/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
string s, t;
int dp[N][N], tr[N][N];

void solve() {
    cin >> s >> t;
    int m = s.size();
    int n = t.size();
    s = " " + s;
    t = " " + t;
    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         dp[i][j] = INT_MIN;
    //     }
    // }
    // for (int i = 0; i <= m; i++) {
    //     dp[i][0] = 0;
    // }
    // for (int i = 0; i <= n; i++) {
    //     dp[0][i] = 0;
    // }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] <= dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
                tr[i][j] = 1;
            }
            if (dp[i][j] <= dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
                tr[i][j] = 2;
            }
            if (s[i] == t[j]) {
                if (dp[i][j] <= dp[i - 1][j - 1] + 1) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    tr[i][j] = 3;
                }
            }
        }
    }
    int i = m, j = n;
    vector < char > ans;
    while (i != 0 && j != 0) {
        if (tr[i][j] == 1) {
            i--;
            continue;
        }
        if (tr[i][j] == 2) {
            j--;
            continue;
        }
        if (tr[i][j] == 3) {
            ans.push_back(s[i]);
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (char c : ans) {
        cout << c;
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