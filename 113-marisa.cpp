//problem "113-marisa"
//created in 17:55:24 - Thu 31/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long ans = 0, u, v;
pair < int, int > a[N];
pair < long long, long long > w;
map < pair < long long, long long >, int > d;

void cal2(int i) {
    if (i > n) {
        ans += d[make_pair(u - w.first, v - w.second)];
        return;
    } 
    cal2(i + 1);
    w.first += a[i].first;
    w.second += a[i].second;
    cal2(i + 1);
    w.first -= a[i].first;
    w.second -= a[i].second;
}

void cal1(int i) {
    if (i > n / 2) {
        d[w]++;
        return;
    } 
    cal1(i + 1);
    w.first += a[i].first;
    w.second += a[i].second;
    cal1(i + 1);
    w.first -= a[i].first;
    w.second -= a[i].second;
}

void solve() {
    cin >> n >> u >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    cal1(1);
    cal2(n / 2 + 1);
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