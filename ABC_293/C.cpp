#include <iostream>
#include <vector>
#include <map>

using namespace std; 

int bitcount(long bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int main()
{
    int h, w, ans = 0;
    cin >> h >> w;

    vector<vector<int>> vv(h, vector<int>(w));

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> vv[i][j];
        }
    }

    for(int bit = 0; bit < (1 << (h + w - 2)); bit++)
    {
        if(bitcount(bit) != h-1) continue;

        int x = 0, y = 0;
        map<long long, int> flag;

        flag[vv[0][0]];

        for(int i = 0; i < h + w - 2; i++)
        {
            if(bit & (1 << i)) y++;
            else x++;

            flag[vv[y][x]];
        }

        if(flag.size() == h + w - 2 + 1) ans++;
    }

    cout << ans << endl;
}