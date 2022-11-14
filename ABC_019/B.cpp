#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, int>> groupby(string s)
{
    vector<pair<char, int>> res;

    for(int i = 0; i < s.size(); i++)
    {
        pair<char, int> c;

        c.first = s[i];
        c.second = 1;

        while(i < s.size() - 1)
        {
            if(s[i+1] == c.first) {
                c.second++;
                i++;
            }
            else break;
        }

        res.push_back(c);
    }

    return res;
}

int main()
{
    string s;
    
    cin >> s;

    vector<pair<char, int>> res = groupby(s);

    for(auto ans : res) cout << ans.first << ans.second;

    cout << endl;

    return 0;
}