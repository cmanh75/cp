//problem "92-marisa"
//created in 21:24:05 - Wed 06/11/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], b[N], c[N], n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int i = 1, j = 1, k = 1;
    while (i <= n || j <= n) {
        if (i <= n && (a[i] <= b[j] || j > n)) {
            c[k] = a[i];
            i++;
            k++;
        }
        else {
            c[k] = b[j];
            j++;
            k++; 
        }
    }
    for (int i = 1; i < k; i++) {
        cout << c[i] << " ";
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