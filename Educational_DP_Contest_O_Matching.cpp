#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), dp(n + 1, vector<int>((1 << n), 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (!dp[i][j]) continue;
            for (int k = 0; k < n; k++) {
                if (a[i][k] && !(j & (1 << k))) {
                    dp[i + 1][j | (1 << k)] += dp[i][j];
                    dp[i + 1][j | (1 << k)] %= MOD;
                }
            }
        }
    }

    cout << dp[n][(1 << n) - 1] << endl;
}