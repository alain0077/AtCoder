#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(m);
    vector<vector<long long>> dp((1 << n), vector<long long> (n, 0));

    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--;
        a[i].second--;
    }

    for (int i = 0; i < n; i++) dp[(1 << i)][i]++;

    for (int bit = 0; bit < (1 << n); bit++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!(bit & (1 << j))) {
                    bool flag = true;
                    for (int k = 0; k < m; k++) {
                        if (bit & (1 << a[k].second)) {
                            if (!(bit & (1 << a[k].first))) flag = false;
                        }
                    }

                    if (flag) dp[bit | (1 << j)][j] += dp[bit][i];
                }
            }
        }
    }

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += dp[(1 << n) - 1][i];
    }

    cout << sum << endl;
}