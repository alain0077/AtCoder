#include <iostream>
#include <vector>
#include <map>

#define ll long long

using namespace std; 

int main()
{
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n);
    map<ll, int> map;

    for(int i = 0; i < n; i++)
    { 
        cin >> a[i];
        map[a[i]]++;
    }

    for(int i = 0; i < n; i++)
    {
        if(map[x + a[i]])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;

    return 0;
}