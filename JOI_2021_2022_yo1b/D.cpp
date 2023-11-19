#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    map<int, int> m;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++; 
    }

    set<pair<int, int>> s;

    for(auto i : m)
    {
        s.insert({i.second, i.first});
    }

    cout << s.begin()->second << endl;
}