//problem "test"
//created in 14:30:57 - Sat 10/05/2025
#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
int n, m, a[N], d[N];

void solve() {
	string s, t;
	cin >> s >> t;
	if (s.size() != t.size()) {
		cout << "NO" << "\n";
		return;
	}
	int d = 0, pos1 = -1, pos2;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i]) {
			d++;
			if (pos1 < 0) {
				pos1 = i;
			}
			else {
				pos2 = i;
			}
		}
	}
	if (d != 2) {
		cout << "NO" << "\n";
	}
	else {
		if (s[pos1] == t[pos2] && s[pos2] == t[pos1]) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
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