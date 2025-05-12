//problem "361-marisa"
//created in 18:36:45 - Thu 26/12/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], n, q;
long long it[N * 4];

void update(int i, int l, int r, int p, int x) {
    if (l > p || r < p) {
        return;
    }
    if (l == r) {
        it[i] = x;
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, p, x);
    update(i * 2 + 1, mid + 1, r, p, x);
    it[i] = it[i * 2] + it[i * 2 + 1];
}

long long get(int i, int l, int r,int le, int ri) {
    if (l > ri || r < le) {
        return 0;
    }
    if (l >= le && r <= ri) {
        return it[i];
    }
    int mid = (l + r) / 2;
    return get(i * 2, l, mid, le, ri) + get(i * 2 + 1, mid + 1, r, le, ri);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    for (int i = 1; i <= q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 2) {
            cout << get(1, 1, n, x, y) << "\n";
        }
        if (c == 1) {
            update(1, 1, n, x, y);
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