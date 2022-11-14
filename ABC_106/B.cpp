#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;

    for (int i = 3; i <= n; i += 2)
    {
        int tmp = 1;
        int m = i;

        for (int a = 2; a * a <= i; a++) {
            if (m % a != 0) continue;

            int ex = 0;

            while (m % a == 0) {
                ex++;
                m /= a;
            }

            ex++;

            tmp *= ex;
        }

        if (tmp == 8) ans++;
    }

    cout << ans << endl;
}