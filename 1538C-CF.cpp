//problem "1538C-CF"
//created in 16:24:40 - Fri 11/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, l, r, a[N], bit[N * 3], m;
map < int, int > pos;

void update(int x, int v) {
    for (; x <= m; x += (x & -x)) {
        bit[x]++;
    }
}

int get(int x) {
    int ans = 0;
    for (; x != 0; x -= (x  & -x)) {
        ans += bit[x];
    }
    return ans;
}

void solve() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector < int > s;
    for (int i = 1; i <= n; i++) {
        s.push_back(a[i]);
        s.push_back(r - a[i]);
        s.push_back(l - 1 - a[i]);
    }
    sort(s.begin(), s.end());
    s.resize(distance(s.begin(), unique(s.begin(), s.end())));
    m = s.size();
    pos.clear();
    for (int i = 1; i <= m; i++) {
        bit[i] = 0;
    }
    for (int i = 0; i < s.size(); i++) {
        pos[s[i]] = i + 1;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += get(pos[r - a[i]]) - get(pos[l - 1 - a[i]]);
        update(pos[a[i]], 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}