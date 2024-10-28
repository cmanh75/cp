//problem "1886C-CF"
//created in 18:10:12 - Mon 14/10/2024
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

void solve() {
    int j;
    long long x;
    string s;
    cin >> s >> x;
    for (int i = 0; i < s.size(); i++) {
        if (x - (int)s.size() + i <= 0) {
            j = i;
            break;
        }
        x -= s.size() - i;
    }
    stack < char > st;
    int k = 0;
    for (int i = 0; i < s.size(); i++) {
        while (k < j && st.size() && st.top() > s[i]) {
            st.pop();
            k++;
        }
        st.push(s[i]);
    }
    while (k < j) {
        k++;
        st.pop();
    }
    vector < char > ans;
    while (st.size()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans[x - 1];
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