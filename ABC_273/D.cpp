#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define ll long long

using namespace std; 

int main()
{
    ll h,w,r,c;
    int n;
    cin >> h >> w >> c >> r;

    cin >> n;
    map<ll,vector<ll>> bc, br;

    for(int i = 0; i < n; i++) {
        int y, x;
        cin >> y >> x;
        bc[y].push_back(x);
        br[x].push_back(y);
    }

    for(auto &p : bc) sort(p.second.begin(), p.second.end());
    for(auto &p : br) sort(p.second.begin(), p.second.end());

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        char d;
        ll num;

        cin >> d >> num;

        if(d == 'L') {
            ll l_limit = 1;
            
            auto it = bc.find(c);
            if(it != bc.end()) {
                auto v = it->second;
                auto it2 = upper_bound(v.begin(), v.end(), r);
                
                if(it2 != v.begin()) {
                    it2--;
                    l_limit = *it2 + 1;
                }
            }
            r = max(r - num, l_limit);
        }
        if(d == 'R') {
            ll u_limit = w;
            
            auto it = bc.find(c);
            if(it != bc.end()) {
                auto v = it->second;
                auto it2 = upper_bound(v.begin(), v.end(), r);
                
                if(it2 != v.end()) {
                    u_limit = *it2 - 1;
                }
            }
            r = min(r + num, u_limit);
        }
        if(d == 'U') {
            ll l_limit = 1;
            
            auto it = br.find(r);
            if(it != br.end()) {
                auto v = it->second;
                auto it2 = upper_bound(v.begin(), v.end(), c);
                
                if(it2 != v.begin()) {
                    it2--;
                    l_limit = *it2 + 1;
                }
            }
            c = max(c - num, l_limit);
        }
        if(d == 'D') {
            ll u_limit = h;
            
            auto it = br.find(r);
            if(it != br.end()) {
                auto v = it->second;
                auto it2 = upper_bound(v.begin(), v.end(), c);
                
                if(it2 != v.end()) {
                    u_limit = *it2 - 1;
                }
            }
            c = min(c + num, u_limit);
        }

        cout << c << " " << r << endl;
    }
}