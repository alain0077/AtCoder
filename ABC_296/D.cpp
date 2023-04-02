#include <iostream>
#include <algorithm>

#define ll long long

using namespace std; 

const ll INF = 2e+18;

int main()
{
    ll n, m, ans = INF;
    cin >> n >> m;

    for(ll a = 1; a <= n; a++)
    {
        ll b = (m + a - 1) / a;
        if(b <= n) ans = min(ans, a*b);
        if(a > b) break;
    }

    if(ans == INF) ans = -1;

    cout << ans << endl;

    return 0;
}