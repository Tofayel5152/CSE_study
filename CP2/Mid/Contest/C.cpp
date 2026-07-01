#include <bits/stdc++.h>
using namespace std;

const long long MOD = 100000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, K;
        cin >> n >> K;

        vector<int> A(n), C(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> C[i];

        // dp[j] = number of ways to make sum j
        vector<long long> dp(K + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            vector<long long> ndp(K + 1, 0);
            for (int j = 0; j <= K; j++) {
                // Use coin i exactly k times (k = 0 to C[i])
                for (int k = 0; k <= C[i] && k * A[i] <= j; k++) {
                    ndp[j] = (ndp[j] + dp[j - k * A[i]]) % MOD;
                }
            }
            dp = ndp;
        }

        printf("Case %d: %lld\n", t, dp[K]);
    }

    return 0;
}