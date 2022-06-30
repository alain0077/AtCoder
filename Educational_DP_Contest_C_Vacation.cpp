#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> a(n, vector<long long>(3, 0)), dp(n, vector<long long>(3, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) cin >> a[i][j];
    }

    for (int j = 0; j < 3; j++) {
        dp[0][j] = a[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    dp[i][j] = max(dp[i][j], a[i][j] + dp[i - 1][k]);
                }
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[n - 1][i]);
    }

    cout << ans << endl;
}