#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<bool>> map(r, vector<bool>(c, false));

    for(int i = 0; i < r; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < c; j++)
        {
            if(s[j] == '#') continue;

            if(s[j] == '.')
            {
                map[i][j] = true;
            }
            else
            {
                int m = s[j] - '0';
                for(int bi = 0; bi < r; bi++)
                {
                    for(int bj = 0; bj < c; bj++)
                    {
                        if(abs(i - bi) + abs(j - bj) <= m) map[bi][bj] = true;
                    }
                }
            }
        }
    }

    for(int i = 0; i < r; i++)
    {
        for(bool f : map[i])
        {
            if(f) cout << '.';
            else cout << '#';
        }

        cout << endl;
    }

    return 0;
}