//problem "211-marisa"
//created in 15:04:32 - Sun 10/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int it[N * 4][3], temp[3], lz[N * 4], n, q;

void down(int i, int l, int r) {
    lz[i] %= 3;
    for (int j = 0; j < 3; j++) {
        temp[(j + lz[i]) % 3] = it[i][j];
    }
    for (int j = 0; j < 3; j++) {
        it[i][j] = temp[j];
    }
    if (l != r) {
        lz[i * 2] += lz[i];
        lz[i * 2 + 1] += lz[i];
    }
    lz[i] = 0;
}

void update2(int i, int l, int r, int le, int ri) {
    down(i, l, r);
    if (l > ri || r < le) {
        return;
    }
    if (l >= le && r <= ri) {
        lz[i]++;
        down(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update2(i * 2, l, mid, le, ri);
    update2(i * 2 + 1, mid + 1, r, le, ri);
    for (int j = 0; j < 3; j++) {
        it[i][j] = it[i * 2][j] + it[i * 2 + 1][j];
    }
}

void update1(int i, int l, int r, int p, int v) {
    if (l > p || r < p) {
        return;
    }
    if (l == r) {
        it[i][v]++;
        return;
    }
    int mid = (l + r) / 2;
    update1(i * 2, l, mid, p, v);
    update1(i * 2 + 1, mid + 1, r, p, v);
    for (int j = 0; j < 3; j++) {
        it[i][j] = it[i * 2][j] + it[i * 2 + 1][j];
    }
}

int get(int i, int l, int r, int le, int ri) {
    down(i, l, r);
    if (l > ri || r < le) {
        return 0;
    }
    if (l >= le && r <= ri) {
        return it[i][0];
    }
    int mid = (l + r) / 2;
    return get(i * 2, l, mid, le, ri) + get(i * 2 + 1, mid + 1, r, le, ri);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update1(1, 1, n, i, x % 3);
    }
    for (int i = 1; i <= q; i++) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 2) {
            cout << get(1, 1, n, l, r) << "\n";
        }
        else {
            update2(1, 1, n, l, r);
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