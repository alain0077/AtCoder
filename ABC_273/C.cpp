#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std; 

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n), ans(n,0);

    ll r = 1;

    for(int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    auto b = a;

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for(int i = 0; i < n; i++) {
        auto p = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans[b.size() - p]++;
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}