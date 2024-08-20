#include <bits/stdc++.h>
using namespace std;
const int N = 1e6  + 5;

int n, m, low[N], num[N], p[N], x[N], y[N], z[N], o = 0, d[N];
vector < pair < int, int > > a[N], b[N];
long long f[N];
stack < int > st;

void tarjan(int i) {
    num[i] = low[i] = ++o;
    st.push(i);
    for (pair < int, int > j : a[i]) {
        if (!num[j.first]) {
            tarjan(j.first);
        }
        low[i] = min(low[j.first], low[i]);
    }
    if (low[i] == num[i]) {
        int x;
        do {
            x = st.top();
            st.pop();
            p[x] = i;
            low[x] = 1e9;
        } while (x != i);
    }
}

long long cost(int z) {
    int u = sqrt(z * 2);
    if (u * (u + 1) > z * 2) {
        u--;
    }
    return 1ll * (u + 1) * z - 1ll * u * (u + 1) * (u + 2) / 6;
} 

void dfs(int i) {
    d[i] = 1;
    long long mx = 0;
    for (pair < int, int > j : b[i]) {
        if (!d[j.first]) {
            dfs(j.first);
        }
        mx = max(mx, f[j.first] + j.second);
    }
    f[i] += mx;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> z[i];
        a[x[i]].push_back(make_pair(y[i], z[i]));
    }
    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            tarjan(i);
        }
    } 
    for (int i = 1; i <= m; i++) {
        if (p[x[i]] != p[y[i]]) {
            b[p[x[i]]].push_back(make_pair(p[y[i]], z[i]));
        }
        else {
            f[p[x[i]]] += cost(z[i]);
        }
    }
    int s;
    cin >> s;
    dfs(p[s]);
    cout << f[p[s]];
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