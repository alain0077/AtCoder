#include <iostream>
#include <vector>

using namespace std; 

const int MOD = 998244353;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int>(2, 0)), ab(n, vector<int>(2));

    for(int i = 0; i < n; i++)
    {
        cin >> ab[i][0] >> ab[i][1];
    }

    dp[0] = {1, 1};

    for(int i = 1; i < n; i++)
    {
        for(int pre = 0; pre < 2; pre++)
        {
            for(int nxt = 0; nxt < 2; nxt++)
            {
                if(ab[i - 1][pre] != ab[i][nxt])
                {
                    dp[i][nxt] += dp[i-1][pre];
                    dp[i][nxt] %= MOD;
                }
            }
        }
    }

    cout << (dp[n-1][0]+dp[n-1][1]) % MOD << endl;
    return 0;
}