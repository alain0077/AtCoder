#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
    vector<int> a(m, 0), dp(n, 0);

    for(int i = 0; i < m; i++) {
        int b = 0;
        cin >> b;
        if(i == b)
        a[i] = 1;
    }

    dp[0] = 1;

    for(int i = 1; i < n; i++) {
        if(a[i]) {
            dp[i] = 0;
        }else {
            dp[i] += dp[i-1];
            dp = dp[i] % 1000000007;
            
            if(i != 1){
                dp[i] += dp[i-2];
                dp[i] % 1000000007;
            }
        }
    }

	cout << dp[n] << endl;
}