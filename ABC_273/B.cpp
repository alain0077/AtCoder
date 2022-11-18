#include <iostream>
using namespace std; 
#define ll long long

int main()
{
    ll n, k, ans = 0;
    cin >> n >> k;

    ll r = 1;

    for(int i = 1; i <= k; i++) { 
        if(n % 10 >= 5) {
            n /= 10;
            n += 1; 
        }
        else n /= 10;

        r *= 10;
    }

    ans += n * r ;

    cout << ans << endl; 
}