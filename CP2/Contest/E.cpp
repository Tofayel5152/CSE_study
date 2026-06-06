#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);

    int N;
    cin >> N;

    vector<double> p(N + 1);
    for (int i = 1; i <= N; i++) cin >> p[i];

    // dp[j] = probability of exactly j heads so far
    vector<double> dp(N + 1, 0.0);
    dp[0] = 1.0; // base: 0 coins tossed, 0 heads with prob 1

    for (int i = 1; i <= N; i++) {
        // Iterate backwards to avoid using updated values
        vector<double> ndp(N + 1, 0.0);
        for (int j = 0; j <= i; j++) {
            // coin i is tails
            ndp[j] += dp[j] * (1.0 - p[i]);
            // coin i is heads
            if (j > 0)
                ndp[j] += dp[j - 1] * p[i];
        }
        dp = ndp;
    }

    // Sum probabilities for more heads than tails
    // Need strictly more than N/2 heads → j >= (N+1)/2
    double ans = 0.0;
    int need = (N + 1) / 2;
    for (int j = need; j <= N; j++) {
        ans += dp[j];
    }

    cout << ans << endl;

    return 0;
}