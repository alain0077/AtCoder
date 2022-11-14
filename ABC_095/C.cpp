#include <iostream>

using namespace std;

int main()
{
    long long a, b, ab, x, y, ans;

    cin >> a >> b >> ab >> x >> y;

    if(a + b > ab * 2)
    {
        if(x > y) {
            long long tmp = x;
            x = y;
            y = tmp;
            tmp = a;
            a = b;
            b = tmp;
        }

        ans = x * ab * 2;

        if(b > ab * 2) ans += (y - x) * ab * 2;
        else ans += (y - x) * b;
    }
    else ans = x * a + y * b;
    
    cout << ans << endl;
}