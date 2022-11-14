#include <iostream>
#include <map>

using namespace std;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

struct P
{
    long long x, y;
};

int main()
{
    long long a, b, c, d;
    map<P, int> Map;
    cin >> a >> b >> c >> d;

    for(int i = 0; i < 8; i++)
    {
        Map[make_pair(a+dx[i], b+dy[i])]++;
        Map[make_pair(c+dx[i], d+dy[i])]++;
    }

    bool flag = false;

    for(auto m : Map)
    {
        if(m.second >= 2) flag = true;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}