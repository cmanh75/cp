//problem "1715E-CF"
//created in 17:22:29 - Tue 03/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, k;
long long d[N];
vector < pair < int, int > > a[N];

struct line {
    int x;
    long long y;
    long long value(int a) {
        return 1ll * a * x + y;
    }
    bool bad_line(line a,line b) {
        return (double)(a.y - y)/(x - a.x) <= (double)(a.y - b.y) / (b.x - a.x);
    }
};
struct convex_hull_trick {
    vector <line> s;
    void add_line(line c) {
        while (s.size() > 1 && c.bad_line(s[s.size() - 2], s.back())) {
            s.pop_back();
        }
        s.push_back(c);
    }
    long long binary_searchh(int a) {
        int l = 0, r = s.size() - 2;
        line ans = s.back();
        while (l <= r) {
            int mid = (l + r) / 2;
            if (s[mid].value(a) >= s[mid + 1].value(a)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                ans = s[mid];
            }
        }
        return ans.value(a);
    }
};

void dijkstra() {
    priority_queue < pair < long long, int >, vector < pair < long long, int > >, greater < pair < long long, int > > > pq;
    for (int i = 1; i <= n; i++) {
        pq.push(make_pair(d[i], i));
    }
    while (pq.size()) {
        pair < long long, int > z = pq.top();
        pq.pop();
        if (z.first != d[z.second]) {
            continue;
        }
        for (auto [v, w] : a[z.second]) {
            if (d[v] > z.first + w) {
                d[v] = z.first + w;
                pq.push(make_pair(d[v], v));
            }
        }
    }

}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        d[i] = 1e18;
    }
    d[1] = 0;
    dijkstra();
    for (int i = 1; i <= k; i++) {
        convex_hull_trick w;
        for (int i = 1; i <= n; i++) {
            w.add_line({-2 * i, d[i] + 1ll * i * i});
        }
        for (int i = 1; i <= n; i++) {
            d[i] = min(d[i], w.binary_searchh(i) + 1ll * i * i);
        }
        dijkstra();
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";
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