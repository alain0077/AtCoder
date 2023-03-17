#include <iostream>
#include <string>

using namespace std; 

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    
    string s;
    cin >> s;

    long long ans = 0;

    int off = 0;

    int cnt1 = 0;
    int cnt2 = 0;

    for(int i = 1; i < s.size(); i++) {
        if(s[i - 1] == s[i]) cnt1++,i++;
        else break;
    }

    for(int i = 1; i <= s.size()/2; i++) {
        if(s[0] == s[s.size() - i]) cnt2++;
        else break;
    }

    for(int i = 0; i < cnt1 - cnt2; i++) {
        if((s.size() - 1)*b <= a + ans) break;
        else {
            s += s[0];
            s.erase(s.begin());
            ans += a;
        }
    }

    for(int i = 1; i <= s.size()/2; i++) {
        if(s[i - 1] == s[s.size() - i]) continue;
        else ans += b;
    }

    cout << ans << endl;
}