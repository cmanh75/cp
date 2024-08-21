#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, a[N], d[N];

void solve() {
    cin >> n;
    if (n % 2 == 0) {
      cout << -1 << "\n";
    }
    else {
      for (int i = n - 1; i > 0; i -= 2) {
        cout << i << " ";
      }
      for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
      }
      cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
	int test;
    cin >> test;
    while (test--) {
        solve();
    }
}