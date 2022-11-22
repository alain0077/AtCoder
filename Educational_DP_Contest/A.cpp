#include <iostream>
#include <vector>

const int INF = 1e9;

using namespace std; 

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> dp(n, INF);
    
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        dp[i] = min(dp[i], dp[i-1] + abs(h[i-1] - h[i]));
        if(i < n-1) dp[i + 1] = min(dp[i+1], dp[i-1] + abs(h[i-1] - h[i+1]));
    }

    cout << dp[n-1] << endl; 
}