//problem "93-marisa"
//created in 21:03:48 - Mon 11/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long n, a[N], x, b[N];

bool cmp(int x, int y) {
    return a[x] < a[y];
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
        int k = 1;
        for (int j = i; j >= k; j--) {
            while (k < j && a[k] + a[j] < x - a[i]) {
                k++;
            }
            if (a[k] + a[j] == x - a[i]) {
                cout << b[k] << " " << b[j] << " " << b[i];
                return;
            }
        }
    }
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