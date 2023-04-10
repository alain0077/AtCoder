#include <iostream>
#include <string>

using namespace std; 

int main()
{
    int r1=0, r2, n1=0, n2, b1=0, b2, q, k;
    string s;

    cin >> s;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'K') k = i+1;
        
        if(s[i] == 'Q') q = i+1;

        if(r1 != 0 && s[i] == 'R') r2 = i+1;
        else if(s[i] == 'R') r1 = i+1;
        
        if(n1 != 0 && s[i] == 'N') n2 = i+1;
        else if(s[i] == 'N') n1 = i+1;
        
        if(b1 != 0 && s[i] == 'B') b2 = i+1;
        else if(s[i] == 'B') b1 = i+1;
    }

    string ans = "Yes";

    if((b1 % 2) == (b2 % 2)) ans = "No";
    if(r1 > k || k > r2) ans = "No";

    cout << ans << endl;

    return 0;
}