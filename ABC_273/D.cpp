#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std; 

int main()
{
    ll h,w,r,c;
    int n;
    cin >> h >> w >> c >> r;
    c -= 1;
    r -= 1;

    cin >> n;

    vector<bool> bc(h, false);
    vector<bool> br(w, false);

    for(int i = 0; i < n; i++) {
        int y, x;
        cin >> y >> x;
        bc[y - 1] = true;
        br[x - 1] = true;
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        char d;
        ll num, dy = 0, dx = 0;

        cin >> d >> num;

        if(d == 'L') {
            dy = 0;
            dx = -1;
        }
        if(d == 'R') {
            dy = 0;
            dx = 1;
        }
        if(d == 'U') {
            dy = -1;
            dx = 0;
        }
        if(d == 'D') {
            dy = 1;
            dx = 0;
        }

        for(int j = 0; j < num; j++) {
            if(0 > c + dy || 0 > r + dx || h <= c + dy || w <= r + dx || (bc[c + dy] && br[r + dx])) break;

            c += dy;
            r += dx;
        }

        cout << c + 1 << " " << r + 1 << endl;
    }
}