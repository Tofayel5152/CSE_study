#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<long long> dp(x + 1, 0);
    dp[0] = 1; // base case: 1 way to make sum 0

    // Outer loop: sum (order matters → sum is outer, coins inner)
    for (long long j = 1; j <= x; j++) {
        for (int i = 0; i < n; i++) {
            if (j >= c[i]) {
                dp[j] = (dp[j] + dp[j - c[i]]) % MOD;
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}