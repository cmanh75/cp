//problem "476-marisa"
//created in 22:13:57 - Mon 02/12/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
set < pair < long long, long long > > s;
int n;
map < long long, long long > d;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, x, y;
        cin >> c;
        if (c == 1) {
            cin >> x >> y;
            auto it = s.find(make_pair(d[x], x));
            if (it == s.end()) {
                d[x] = y;
                s.insert(make_pair(d[x], x));
                continue;
            }
            pair < long long, long long > temp = (*it);
            temp.first += y;
            s.erase(it);
            d[x] = temp.first;
            s.insert(temp);
        }
        if (c == 2) {
            cin >> x >> y;
            auto it = s.find(make_pair(d[x], x));
            if (it == s.end()) {
                continue;
            }
            pair < long long, long long > temp = (*it);
            temp.first -= y;
            s.erase(it);
            if (temp.first > 0) {
                d[x] = temp.first;
                s.insert(temp);
            }   
        }
        if (c == 3) {
            cout << (*s.rbegin()).second << "\n";
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