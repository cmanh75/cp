//problem "292E-CF"
//created in 15:53:39 - Wed 11/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q, a[N], b[N], pos, it[N * 4];

void down(int i, int l, int r) {
    if (l != r && it[i]) {
        it[i * 2] = it[i];
        int mid = (l + r) / 2;
        it[i * 2 + 1] = it[i] + mid - l + 1;
        it[i] = 0; 
    }
}

void update(int i, int l, int r, int le, int ri) {
    down(i, l, r);
    if (l > ri || r < le) {
        return;
    }
    if (l >= le && r <= ri) {
        it[i] = pos;
        pos = pos + ri - le;
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, le, ri);
    update(i * 2 + 1, mid + 1, r, le, ri);
}

int get(int i, int l, int r, int p) {
    down(i, l, r);
    if (l == r) {
        return it[i];
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
    cout << 1;
    while (q--) {
        int c, x, y, k;
        cin >> c >> x;
        if (c == 1) {
            cin >> y >> k;
            pos = x;
            update(1, 1, n, y, y + k - 1);
        }
        else {
            int u = get(1, 1, n, x);
            if (!u) {
                cout << b[x] << "\n";
            }
            else {
                cout << a[u] << "\n";;
            }
        }
    }
}
// alt + shift + n
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test = 1;
    // cout << "hi";
    while (test--) {
        solve();
    }
}
/*
python main.py
g++ ads.cpp -o a.exe
*/