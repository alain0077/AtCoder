#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int  bit_count(int bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
}

int main()
{
    int n, ans = 0;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> x(n, vector<int> (n - 1)), y(n, vector<int>(n - 1));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < a[i]; j++) cin >> x[i][j] >> y[i][j];
    }

    for (int bit = 0; bit < (1 << n); bit++) {
        int sum = 0;
        bool f = true;

        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                for (int j = 0; j < a[i]; j++) {
                    if (bit & (1 << x[i][j] - 1) && !y[i][j]) f = false;
                    if (!(bit & (1 << x[i][j] - 1)) && y[i][j]) f = false;
                }
            }
        }

        if (f) ans = max(ans, bit_count(bit));
    }

    cout << ans << endl;
}