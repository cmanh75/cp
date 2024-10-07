//problem "1640-CSES"
//created in 09:41:05 - Sun 29/09/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, x, a[N], b[N];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int bs(int x) {
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    if (ans != -1 && a[ans] == x) {
        return ans;
    }
    return -1;
}

void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = i;
    }
    sort(b + 1, b + n + 1, cmp);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        int j = bs(x - a[i]);
        if (j != -1 && i != j) {
            cout << b[i] << " " << b[j];
            return;
        }
    }
    cout << "IMPOSSIBLE";
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