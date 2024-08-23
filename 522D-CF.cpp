#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, lazy[N * 4], a[N], it[N * 4];

void down(int i, int l, int r) {
    it[i] += lazy[i];
    if (l != r) {
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
    }
    lazy[i] = 0;
}

void update(int i, int l, int r, int le, int ri, int v) {
    down(i, l, r);
    if (l > ri || r < le) {
        return;
    }
    if (l >= le && r <= ri) {
        lazy[i] = v;
        down(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, le, ri, v);
    update(i * 2 + 1, mid + 1, r, le, ri, v);
    it[i] = max(it[i * 2], it[i * 2 + 1]);
}

int get(int i, int l, int r) {
    down(i, l, r);
    if (l == r) {
        return l;
    }
    int mid = (l + r) / 2;
    down(i * 2 + 1, mid + 1, r);
    if (it[i * 2 + 1] > 0) {
        return get(i * 2 + 1, mid + 1, r);
    }
    return get(i * 2, l, mid);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p, t;
        cin >> p >> t;
        update(1, 1, n, 1, p, ((t == 0) ? -1 : 1));
        if (t == 1) {
            cin >> a[p];
        }
        if (it[1] <= 0) {
            cout << -1 << "\n";
            continue;
        }
        cout << a[get(1, 1, n)] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
	  int test = 1;
    while (test--) {
        solve();
    }
}