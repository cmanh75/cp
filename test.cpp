//problem "test"
//created in 19:06:34 - Thu 15/05/2025
#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
const int mod = 1e9 + 7;
string s;
int n, m, dp[N][N][2];

void add(int &x, int y) {
	x = (x + y) % mod;
}

void solve() {
	cin >> n >> m >> s;
	int r = 0, d = 0;
	for (int i = 0; i < m; i++) {
		if (s[i] == ')') {
			d--;
		}
		else {
			d++;
		}
		r = min(r, d);
	}
	dp[0][0][0] = 1;
	for (int i = 1; i <= n - m + 1; i++) {
		for (int j = 0; j <= n - m + 1; j++) {
			for (int k = 0; k < 2; k++) {
				add(dp[i][j + 1][k], dp[i - 1][j][k]);
				if (j > 0) {
					add(dp[i][j - 1][k], dp[i - 1][j][k]);
				}
			}
			if (j + r >= 0 && j + d <= (n - m + 1)) {
				add(dp[i][j + d][1], dp[i - 1][j][0]);
			}
		}
	}
	cout << dp[n - m + 1][0][1];
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