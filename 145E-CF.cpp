//problem "145E-CF"
//created in 20:06:34 - Thu 26/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, lz[N * 4];
string s;

struct itree {
    int zer, one, fow, rev;
} it[N * 4];

itree combine(itree a, itree b) {
    itree c;
    c.one = a.one + b.one;
    c.zer = a.zer + b.zer;
    c.fow = max(a.fow + b.one, a.zer + b.fow);
    c.rev = max(a.rev + b.zer, b.rev + a.one);
    return c;
}

void build(int i, int l, int r) {
    if (l == r) {
        it[i] = {1, 0, 1, 1};
        return;
    }
    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    it[i] = combine(it[i * 2], it[i * 2 + 1]);
}

void down(int i, int l, int r) {
    if (lz[i]) {
        swap(it[i].fow, it[i].rev);
        swap(it[i].zer, it[i].one);
    }
    if (l != r) {
        lz[i * 2] ^= lz[i];
        lz[i * 2 + 1] ^= lz[i];
    }
    lz[i] = 0;
}

void update(int i, int l, int r, int le, int ri) {
    down(i, l, r);
    if (l > ri || r < le) {
        return;
    }
    if (l >= le && r <= ri) {
        lz[i] ^= 1;
        down(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, le, ri);
    update(i * 2 + 1, mid + 1, r, le, ri);
    it[i] = combine(it[i * 2], it[i * 2 + 1]);
}

void solve() {
    cin >> n >> m >> s;
    build(1, 1, n);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '4') {
            continue;
        }
        update(1, 1, n, i + 1, i + 1);
    }
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (s == "count") {
            cout << it[1].fow << "\n";
        }
        else {
            int x, y;
            cin >> x >> y;
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