#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // base case
    
    for (int i = 1; i <= n; i++) {
        for (int face = 1; face <= 6; face++) {
            if (i - face >= 0) {
                dp[i] = (dp[i] + dp[i - face]) % MOD;
            }
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}