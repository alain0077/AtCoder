#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s, ans = "No";
    cin >> s; 

    if(s.size() == 1) {
        if(s == "8") ans = "Yes";

        cout << ans << endl; 
        return 0;
    }

    if(s.size() == 2)
    {
        if(stoi(s) % 8 == 0) ans = "Yes";

        else {
            swap(s[0], s[1]);
            if(stoi(s) % 8 == 0) ans = "Yes";
        }

        cout << ans << endl; 
        return 0;
    }

    vector<int> v(10,0);

    for(char c : s) v[c - '0']++;

    for(int i = 112; i < 1000; i+=8)
    {
        auto tmp = v;
        for(auto c : to_string(i)) tmp[c - '0']--;

        bool f = true;
        for(int n : tmp) if(n < 0) f = false;
        if(f)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}