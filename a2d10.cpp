#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
pair<long long, int> it[N * 4];
int a[N], n, q;
void update(int i, int l, int r, int p, int x) {
    if (l > p || r < p) {
        return;
    }
    if (l == r) {
        it[i] = {x, 1};
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, p, x);
    update(i * 2 + 1, mid + 1, r, p, x);
    if (it[i * 2].first == it[i * 2 + 1].first) {
        it[i] = {it[i * 2].first, it[i * 2].second + it[i * 2 + 1].second};
    } else if (it[i * 2].first < it[i * 2 + 1].first) {
        it[i] = it[i * 2];
    } else {
        it[i] = it[i * 2 + 1];
    }
}

pair<long long, int> get(int i, int l, int r, int le, int ri) {
    if (l > ri || r < le) {
        return {LLONG_MAX, 0};
    }
    if (l >= le && r <= ri) {
        return it[i];
    }
    int mid = (l + r) / 2;
    pair<long long, int> left = get(i * 2, l, mid, le, ri);
    pair<long long, int> right = get(i * 2 + 1, mid + 1, r, le, ri);
    if (left.first == right.first) {
        return {left.first, left.second + right.second};
    } else if (left.first < right.first) {
        return left;
    } else {
        return right;
    }
}

void solve() {
    int i;
    cin >> n >> q;
    for (i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    for (i = 1; i <= q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        x++;
        if (c == 2) {
            y++;
            pair<long long, int> res = get(1, 1, n, x, y);
            cout << res.first << " " << res.second << "\n";
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
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int test = 1;
    while (test--) {
        solve();
    }
    return 0;
}
