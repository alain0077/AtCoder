#include <iostream>
#include <algorithm>

#define ll long long

using namespace std; 

int main()
{
    ll cnt = 0;
    ll a, b;
    cin >> a >> b;

    if(a < b) swap(a, b);

    while ((b > 0)) {
        cnt += a/b;
        a %= b;
        swap(a,b);
    }

    cout << cnt - 1 << endl;

    return 0;
}