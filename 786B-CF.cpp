#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;

int n, o, m, s, pos[N];
long long d[N];
vector < pair < int, int > > a[N];

void add(int x, int y, int z) {
    a[x].push_back(make_pair(y, z));
}

void build(int i, int l, int r) {
    if (l == r) {
        add(i + o, i, 0);
        pos[l] = i;
        return;
    }
    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    add(i * 2, i, 0);
    add(i * 2 + 1, i, 0);
    add(i + o, i * 2 + o, 0);
    add(i + o, i * 2 + 1 + o, 0);
}

void addedge(int i, int l, int r,int le, int ri, int u, int w, int c) {
    if (l > ri || r < le) {
        return;
    }
    if (l >= le && r <= ri) {
        if (c == 2) {
            add(pos[u], i + o, w);
        }
        else {
            add(i, pos[u] + o, w);
        }
        return;
    }
    int mid = (l + r) / 2;
    addedge(i * 2, l, mid, le, ri, u, w, c);
    addedge(i * 2 + 1, mid + 1, r, le, ri, u, w, c);
}

void solve() {
    cin >> n >> m >> s;
    o = n * 4;
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int c, v, l, r, w, u;
        cin >> c >> v;
        if (c == 1) {
            cin >> u >> w;
            add(pos[v], pos[u], w);
            continue;
        }
        cin >> l >> r >> w;
        if (c == 2) {
            addedge(1, 1, n, l, r, v, w, 2);
        }
        if (c == 3) {
            addedge(1, 1, n, l, r, v, w, 3);
        }
    }
    for (int i = 1; i <= n * 8; i++) {
        d[i] = 1e18;
    }
    priority_queue < pair < long long, int >, vector < pair < long long, int > >, greater < pair < long long, int > > > pq;
    pq.push(make_pair(0, pos[s]));
    d[pos[s]] = 0;
    while (pq.size()) {
        pair < long long, int > z = pq.top();
        pq.pop();
        if (z.first != d[z.second]) {
            continue;
        }
        for (pair < int, int > j :  a[z.second]) {
            if (z.first + j.second < d[j.first]) {
                d[j.first] = z.first + j.second;
                pq.push(make_pair(d[j.first], j.first));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[pos[i]] == 1e18) {
            cout << -1 << " ";
            continue;
        }
        cout << d[pos[i]] << " ";
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