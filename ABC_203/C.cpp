#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long long n, k, ans = 0;
    cin >> n >> k;

    vector<pair<long long, long long>> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    long long pre = 0;

    for(int i = 0; i < n; i++)
    {
        if(i != 0 && ans == a[i].first) {
            k += a[i].second;
            continue;
        }

        if(k - (a[i].first - ans) < 0) {
            break;
        }
        else {
            k -= (a[i].first - ans);
            ans = a[i].first;
            k += a[i].second;
        }
    }

    if(k > 0) ans += k;

    cout << ans << endl;
}