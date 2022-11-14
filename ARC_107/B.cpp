#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    k = abs(k);

    vector<long long> v(2 * n + 1, 0);

    for (long long i = 2; i <= 2 * n; i++) {
        v[i] = min(i - 1, 2 * n + 1 - i);
    }

    long long ans = 0;

    for (int i = k; i <= 2 * n; i++) {
        ans += v[i] * v[i - k];
    }

    cout << ans << endl;
}