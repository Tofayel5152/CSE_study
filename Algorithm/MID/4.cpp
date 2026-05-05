/*
4. Extracting the Anomaly (Rabin-Karp + Subset Sum)Problem:
 You are looking for a specific data anomaly (Pattern P) within a large dataset (Text T represented as an array of integers)
 Task: Use the Rabin-Karp algorithm to find all occurrences of P in T. For every index i where a match starts, calculate the sum of the elements in that matching window. Output the total sum of all such matching windows
 Input:  Array T and Pattern Array P.
 Example Case:T = [1, 2, 3, 1, 2, 5], P = [1, 2]
 Matches: Occurs at index 0 (Sum => 1+2=3) and index 3 (Sum => 1+2=3).Total Sum: 3 + 3 = 6.
 */

 #include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> text(n), pattern(m);
    for (int i = 0; i < n; i++) cin >> text[i];
    for (int i = 0; i < m; i++) cin >> pattern[i];

    int d = 10, q = 101, h = 1;
    for (int i = 0; i < m - 1; i++) h = (h * d) % q;

    int p_hash = 0, t_hash = 0;
    for (int i = 0; i < m; i++) {
        p_hash = (d * p_hash + pattern[i]) % q;
        t_hash = (d * t_hash + text[i]) % q;
    }

    long long total_anomaly_sum = 0;

    for (int i = 0; i <= n - m; i++) {
        if (p_hash == t_hash) {
            // Verify match to handle collisions
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                // Sum the elements of this specific window
                for (int j = 0; j < m; j++) total_anomaly_sum += text[i + j];
            }
        }

        if (i < n - m) {
            t_hash = (d * (t_hash - text[i] * h) + text[i + m]) % q;
            if (t_hash < 0) t_hash += q;
        }
    }

    cout << "Total Sum of Anomalies: " << total_anomaly_sum << endl;
    return 0;
}