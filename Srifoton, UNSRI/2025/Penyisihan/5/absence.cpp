#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int countAttendance(int n) {
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int a = 0; a <= 1; ++a) {
            for (int l = 0; l <= 2; ++l) {
                int val = dp[i][a][l];
                if (val == 0) continue;

                dp[i+1][a][0] = (dp[i+1][a][0] + val) % MOD;

                if (l + 1 <= 2)
                    dp[i+1][a][l+1] = (dp[i+1][a][l+1] + val) % MOD;

                if (a == 0)
                    dp[i+1][1][0] = (dp[i+1][1][0] + val) % MOD;
            }
        }
    }

    int result = 0;
    for (int a = 0; a <= 1; ++a)
        for (int l = 0; l <= 2; ++l)
            result = (result + dp[n][a][l]) % MOD;

    return result;
}

int main() {
    int n;
    cin >> n;
    cout << countAttendance(n) << endl;
    return 0;
}
