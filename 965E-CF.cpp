//problem "965E-CF"
//created in 17:00:14 - Tue 27/08/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, cnt = 0, d[N], in[N], out[N], trie[N][26], o = 0, h[N];
long long ans = 0;
pair < int, int > it[N * 4];

void add(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!trie[cur][u]) {
            trie[cur][u] = ++cnt;
        }
        cur = trie[cur][u];
    }
    d[cur] = 1;
} 

void update(int i, int l, int r, int p, int val) {
    if (l > p || r < p) {
        return;
    }
    if (l == r) {
        it[i] = {val, p};
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, p, val);
    update(i * 2 + 1, mid + 1, r, p, val);
    it[i] = max(it[i * 2], it[i * 2 + 1]);
}

pair < int, int > get(int i, int l, int r, int le, int ri) {
    if (l > ri || r < le) {
        return {0, 0};
    }
    if (l >= le && r <= ri) {
        return it[i];
    }
    int mid = (l + r) / 2;
    return max(get(i * 2, l, mid, le, ri), get(i * 2 + 1, mid + 1, r, le, ri));
}

void dfs(int i) {
    in[i] = o++;
    if (d[i]) {
        update(1, 1, cnt, in[i], h[i]);
    }
    for (int j = 0; j < 26; j++) {
        if (trie[i][j]) {
            h[trie[i][j]] = h[i] + 1;
            dfs(trie[i][j]);
        }
    }
    out[i] = o;
    if (i && !d[i]) {
        pair < int, int > z = get(1, 1, cnt, in[i], out[i]);
        ans -= z.first - h[i];
        update(1, 1, cnt, z.second, 0);
        update(1, 1, cnt, in[i], h[i]);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        ans += s.size();
        add(s);
    }
    dfs(0);
    cout << ans;
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