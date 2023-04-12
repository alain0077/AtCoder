#include <iostream>

#define ll long long

using namespace std; 

int main()
{
    int n;
    cin >> n;

    ll ans = 0;

    // AB == N - CD
    // N * √N
    for(int i = 1; i < n; i++)
    {
        int ab = n - i, cd = i;
        ll cnt1 = 0, cnt2 = 0; 

        for(int j = 1; j*j <= ab; j++)
        {
            if(ab % j == 0) 
            {
                cnt1++;
                if(ab != j*j) cnt1++;
            }
        }

        for(int j = 1; j*j <= cd; j++)
        {
            if(cd % j == 0)
            { 
                cnt2++;
                if(cd != j*j) cnt2++;
            }
        }

        ans += cnt1 * cnt2;
    }

    cout << ans << endl;
}