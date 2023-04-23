#include <iostream>

#define ll long long

using namespace std;

const int MOD = 998244353;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    a = (a*(a+1)) / 2 % MOD;
    b = (b*(b+1)) / 2 % MOD;
    c = (c*(c+1)) / 2 % MOD;

    ll ans = (a * b) % MOD;

    ans = (ans * c) % MOD;

    cout << ans << endl;
}