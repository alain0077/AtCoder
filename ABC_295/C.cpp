#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    //vector<int> a(n);
    map<int, int> num;
    
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        num[a]++;
    }

    int ans = 0;

    for(auto t : num)
    {
        ans += t.second / 2;
    }

    cout << ans << endl;

    return 0;
}