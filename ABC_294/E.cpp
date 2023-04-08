#include <iostream>
#include <vector>

#define ll long long

using namespace std; 

int main()
{
    ll l;
    int n1, n2;
    cin >> l >> n1 >> n2;

    vector<pair<int, ll>> v1(n1), v2(n2);

    for(int i = 0; i < n1; i++)
    {
        cin >> v1[i].first >> v1[i].second;
    }

    for(int i = 0; i < n2; i++)
    {
        cin >> v2[i].first >> v2[i].second;
    }

    ll ans = 0;
    int i = 0, j = 0;

    while(i != n1 || j != n2)
    {
        if(v1[i].second == v2[j].second)
        {
            if(v1[i].first == v2[j].first) ans += v1[i].second;
            i++; j++;
        }
        else if(v1[i].second > v2[j].second)
        {
            v1[i].second -= v2[j].second;
            if(v1[i].first == v2[j].first) ans += v2[j].second;
            j++;
        }
        else
        {
            v2[j].second -= v1[i].second;
            if(v1[i].first == v2[j].first) ans += v1[i].second;
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}