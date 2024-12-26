//problem "cses1641-CF"
//created in 22:03:11 - Sun 01/12/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], x, b[N];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

void solve() {
    int n;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = i;
    }
    sort(b + 1, b + n + 1, cmp);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        int k = 1;
        for (int j = i - 1; j > k; j--) {
            while (k < j - 1 && x - a[i] - a[j] > a[k]) {
                k++;
            }
            if (a[i] + a[j] + a[k] == x) {
                cout << b[k] << " " << b[j] << " " << b[i] << "\n";
                return;
            }
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