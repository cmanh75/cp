//problem "390-marisa"
//created in 15:50:30 - Sun 10/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, it[N * 4], a[N], bit[N];
long long k, f[N];
vector < long long > s;

int pos(long long x) {
    return upper_bound(s.begin(), s.end(), x) - s.begin();
}

void update(int i, int l, int r, int p, int v) {
    if (l > p || r < p) {
        return;
    }
    if (l == r) {
        it[i] += v;
        return;
    }
    int mid = (l + r) / 2;
    update(i * 2, l, mid, p, v);
    update(i * 2 + 1, mid + 1, r, p, v);
    it[i] = it[i * 2] + it[i * 2 + 1];
}

int get(int i, int l, int r, int le, int ri) {
    if (l > ri || r < le) {
        return 0;
    }
    if (l >= le && r <= ri) {
        return it[i];
    }
    int mid = (l + r) / 2;
    return get(i * 2, l, mid, le, ri) + get(i * 2 + 1, mid + 1, r, le, ri);
}

void update1(int x, int v) {
    for (; x <= m; x += (x & -x)) {
        bit[x] += v;
    }
}

int get1(int x) {
    int ans = 0;
    for (; x != 0; x -= (x & -x)) {
        ans += bit[x];
    }
    return ans;
}

bool check(long long x) {
    long long ans = 0;
    for (int i = 1; i <= m ; i++) {
        bit[i] = 0;
    }
    update1(pos(0), 1);
    for (int i = 1; i <= n; i++) {
        ans += get1(pos(f[i] - x));
        update1(pos(f[i]), 1);
    }
    return ans >= k;
}

void solve() {
    cin >> n >> k;
    long long z = 0;
    s.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        z += a[i];
        f[i] = z;
        s.push_back(z);
    }
    sort(s.begin(), s.end());
    s.resize(distance(s.begin(), unique(s.begin(), s.end())));
    m = s.size();
    long long l = -1e12, r = 1e12, ans;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
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