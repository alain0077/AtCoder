#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int q;
    cin >> q;
    map<int, int> s;

    for (int i = 0; i < q; i++) {
        int t, x, c;
        cin >> t;
        switch (t)
        {
        case 1:
            cin >> x;
            s[x]++;
            break;
        case 2:
            cin >> x >> c;
            s[x] -= c;
            if (s[x] < 1) s.erase(x);
            break;
        case 3:
            cout << s.rbegin()->first - s.begin()->first << endl;
            break;
        default :
            break;
        }
    }
}