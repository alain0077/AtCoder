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
    bool flag = true;
    string s, t;
    
    cin >> s >> t;

    vector<pair<char, int>> group_s = groupby(s);
    vector<pair<char, int>> group_t = groupby(t);

    if(group_s.size() == group_t.size()) {
        for(int i = 0; i < group_s.size(); i++)
        {
            auto gs = group_s[i], gt = group_t[i];

            if(gs.first == gt.first) {
                if(gs.second <= gt.second) {
                    if(gs.second == 1 && gt.second > 1) {
                    flag = false;
                    break;
                    }
                }
                else {
                    flag = false;
                    break;
                }
            }
            else {
                flag = false;
                break;
            }

        }
    }
    else flag = false;

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}