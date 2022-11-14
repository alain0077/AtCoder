#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    long long ans = 0;

    int n = s.length() - 1;

    for (int bit = 0; bit < (1 << n); bit++) {
        long long tmp = 0;
        long long num = s[0] - '0';

        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                tmp += num;
                num = 0;
            }

            num = num * 10 + s[i + 1] - '0';
        }

        tmp += num;
        ans += tmp;
    }

    cout << ans << endl;
}