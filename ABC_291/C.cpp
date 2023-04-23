#include <iostream>
#include <map>

using namespace std; 

int main()
{
    int n, x = 0, y = 0;
    string s;
    map<pair<int, int>, int> flag;

    cin >> n;
    cin >> s;

    flag[make_pair(x, y)]++;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'R') x++;
        if(s[i] == 'L') x--;
        if(s[i] == 'U') y++;
        if(s[i] == 'D') y--;

        if(flag[make_pair(x, y)])
        {
            cout << "Yes" << endl;
            return 0;
        }
        else 
        {
            flag[make_pair(x, y)]++;
        }
    }

    cout << "No" << endl;
    return 0;
}