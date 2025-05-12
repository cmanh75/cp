//problem "212-marisa"
//created in 17:17:52 - Thu 26/12/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q;
const int mod = 1e9 + 7;

struct itree {
    long long sum, x, y;
} it[N * 4];

void add(long long &x, long long y) {
    x = (x + y) % mod;
}

void down(int i, int l, int r) {
    add(it[i].sum, it[i].x * (r - l + 1) % mod + it[i].y * (r - l + 1) * (r - l) / 2 % mod);
    if (l != r) {
        add(it[i * 2].y, it[i].y);
        add(it[i * 2 + 1].y, it[i].y);
        add(it[i * 2].x, it[i].x);
        int mid = (l + r) / 2;
        add(it[i * 2 + 1].x, it[i].x + it[i].y * (mid + 1 - l) % mod);
    }
    it[i].x = 0;
    it[i].y = 0;
}

void update(int i, int l, int r, int le, int ri, int x, int y) {
    down(i, l, r);
    if (l > ri || r < le) {
        return;
    }
    if (l >= le && r <= ri) {
        it[i].x = (it[i].x + 1ll * x * (l - le) % mod + y) % mod;
        it[i].y = (it[i].y + x) % mod;
        down(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, le, ri, x, y);
    update(i * 2 + 1, mid + 1, r, le, ri, x, y);
    it[i].sum = (it[i * 2].sum + it[i * 2 + 1].sum) % mod;
}

long long get(int i, int l, int r, int le, int ri) {
    down(i, l, r);
    if (l > ri || r < le) {
        return 0;
    }
    if (l >= le && r <= ri) {
        return it[i].sum;
    }
    int mid = (l + r) / 2;
    return (get(i * 2, l, mid, le, ri) + get(i * 2 + 1, mid + 1, r, le, ri)) % mod;
}

void solve() {
    cin >> n >> q;
    while (q--) {
        int c, x, y, l, r;
        cin >> c;
        if (c == 1) {
            cin >> l >> r >> x >> y;
            update(1, 1, n, l, r, x, y);
        }
        else {
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << "\n";
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