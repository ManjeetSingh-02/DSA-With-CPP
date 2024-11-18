// Coin change

long getWays(int n, vector<long> c) {
    vector<long> dp(n+1,0);
    dp[0]=1;
    for(int i = 0; i < c.size(); i++) {
        for(int j = c[i]; j <= n; j++) {
            dp[j] += dp[j-c[i]];
        }
    }
    return dp[n];
}