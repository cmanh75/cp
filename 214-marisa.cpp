//problem "214-marisa"
//created in 15:12:52 - Sun 17/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q, a[N], b[N], lz[N * 4], v;

void down(int i, int l, int r) {
    if (lz[i]) {
        if (l != r) {
            lz[i * 2] = lz[i];
            lz[i * 2 + 1] = lz[i] + (l + r) / 2 + 1 - l;
            lz[i] = 0;
        } 
    }
}

void update(int i, int l, int r, int le, int ri) {
    down(i, l, r);
    if (l > ri || r < le) {
        return;
    }
    if (l >= le && r <= ri) {
        lz[i] = v;
        v += r - l + 1;
        down(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, le, ri);
    update(i * 2 + 1, mid + 1, r, le, ri);
}

int get(int i, int l, int r, int p) {
    down(i, l, r);
    if (l == r) {
        return lz[i];
    }
    int mid = (l + r) / 2;
    if (mid >= p) {
        return get(i * 2, l, mid, p);
    } 
    return get(i * 2 + 1, mid + 1, r, p);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    while (q--) {
        int c, x, y;
        cin >> c >> x;
        if (c == 1) {
            int z;
            v = x;
            cin >> y >> z;
            update(1, 1, n, y, y + z - 1);
        }
        else {
            int z = get(1, 1, n, x);
            if (z == 0) {
                cout << b[x] << "\n";
            }
            else {
                cout << a[z] << "\n";
            }
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