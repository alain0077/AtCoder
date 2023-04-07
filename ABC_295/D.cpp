#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> cnt(10, 0);
    map<vector<int>, long long> map;

    map[cnt]++;
    
    for(auto c : s)
    {
        cnt[c - '0']++;
        cnt[c - '0'] %= 2;
        map[cnt]++;   
    }

    long long ans = 0;

    for(auto [_, n] : map)
    {
        //nC2
        ans += (n * (n - 1)) / 2;
    }

    cout << ans << endl;
    return 0;
}