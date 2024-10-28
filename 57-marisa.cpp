//problem "57-marisa"
//created in 09:27:38 - Fri 25/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int r[10][10], c[10][10], a[10][10], f[10][10], ans = 0, oke = 0;

int gr(int x, int y) {
    return (x / 3) * 3 + y / 3;
}

void cal(int x, int y) {
    if (oke == 1) {
        return;
    }
    if (x == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        oke = 1;
        return;
    }
    if (a[x][y]) {
        cal(x + (y + 1) / 9, (y + 1) % 9);
        return;
    }
    for (int i = 1; i <= 9; i++) {
        int u = gr(x, y);
        if (!r[x][i] && !c[y][i] && !f[u][i]) {
            f[u][i] = 1;
            r[x][i] = 1;
            c[y][i] = 1;
            a[x][y] = i;
            cal(x + (y + 1) / 9, (y + 1) % 9);
            a[x][y] = 0;
            r[x][i] = 0;
            f[u][i] = 0;
            c[y][i] = 0;
        }
    }
}

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
            if (x != 0) {
                r[i][x] = 1;
                c[j][x] = 1;
                f[gr(i, j)][x] = 1;
            }
        }
    }
    cal(0, 0);
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