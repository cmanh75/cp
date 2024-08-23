#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, k, a[N], v[N];
map < int, int > pos;
char c[N];

struct node {
    int sum, max, pre, suf, ok; 
}it[N * 4];

vector < int > s;

node combine(node a, node b)  {
    node z;
    z.sum = a.sum + b.sum;
    z.max = max(a.max, b.max);
    z.pre = a.pre;
    z.suf = b.suf;
    z.ok = b.ok;
    if (a.ok != 0) {
        if (a.pre == a.sum) {
            z.pre += b.pre;
        }
        if (b.suf == b.sum) {
            z.suf += a.suf;
        }
        z.max = max(z.max, a.suf + b.pre);
    }
    return z;
}

void update(int i, int l, int r, int p, int ok) {
    if (l > p || r < p) {
        return;
    }
    if (l == r) {
        it[i].ok = ok;
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, p, ok);
    update(i * 2 + 1, mid + 1, r, p, ok);
    it[i] = combine(it[i * 2], it[i * 2 + 1]);
}

void build(int i, int l, int r) {
    if (l == r) {
        int z = s[l] - s[l - 1];
        it[i] = {z, z, z, z, 1};
        return;
    }
    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    it[i] = combine(it[i * 2], it[i * 2 + 1]);
}

int get(int i, int l, int r, int k) {
    if (l == r) {
        return s[l - 1] + 1;
    }
    int mid = (l + r) / 2;
    if (it[i * 2].max > k) {
        return get(i * 2, l, mid, k);
    }
    if (it[i * 2].ok == 1 && it[i * 2 + 1].pre + it[i * 2].suf > k) {
        return s[mid] - it[i * 2].suf + 1;
    }
    return get(i * 2 + 1, mid + 1, r, k);
}

void out(int i, int l, int r) {
    cout << i << " " << l << " " << r << " " << it[i].max << " " << it[i].ok << "\n";
    int mid = (l + r) / 2;
    if (l == r) {
        return;
    }
    out(i * 2, l, mid);
    out(i * 2 + 1, mid + 1, r);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.push_back(a[i]);
    }
    s.push_back(0);
    s.push_back(1e9);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> c[i] >> v[i];
        s.push_back(v[i]);
    }
    sort(s.begin(), s.end());
    s.resize(distance(s.begin(), unique(s.begin(), s.end())));
    int m = s.size() - 1;
    for (int i = 0; i < s.size(); i++) {
        pos[s[i]] = i;
    }
    build(1, 1, m);
    for (int i = 1; i <= n; i++) {
        update(1, 1, m, pos[a[i]], 0);
    }
    for (int i = 1; i <= q; i++) {
        if (c[i] == '+' || c[i] == '-') {
            update(1, 1, m, pos[v[i]], (c[i] == '+' ? 0 : 1));
        }
        else {
            cout << get(1, 1, m, v[i]) << " ";
        }
    }
    cout << "\n";
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