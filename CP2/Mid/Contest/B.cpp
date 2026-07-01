#include <bits/stdc++.h>
using namespace std;

const long long MOD = 10000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    for (int caseno = 1; caseno <= cases; caseno++) {
        long long a, b, c, d, e, f, n;
        cin >> a >> b >> c >> d >> e >> f >> n;

        // dp array with base cases
        vector<long long> dp(max(n + 1, 6LL));
        dp[0] = a % MOD;
        dp[1] = b % MOD;
        dp[2] = c % MOD;
        dp[3] = d % MOD;
        dp[4] = e % MOD;
        dp[5] = f % MOD;

        for (long long i = 6; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] +
                    dp[i-4] + dp[i-5] + dp[i-6]) % MOD;
        }

        printf("Case %d: %lld\n", caseno, dp[n] % MOD);
    }

    return 0;
}