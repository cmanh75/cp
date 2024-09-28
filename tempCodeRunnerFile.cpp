ns = 0;
    for (int i = 0; i < (1 << n); i++) {
        int z = __builtin_popcount(i);
        if (z == k) {
            ans += dp[(1 << n) - 1][i];
        }
    }
    cout << ans;