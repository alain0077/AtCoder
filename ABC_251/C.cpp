#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>

#define dbg(x) cout << #x << " = " << x << endl
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define chmax(a,b) (a<b?(a=b,1):0)
#define chmin(a,b) (a>b?(a=b,1):0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define elif else if

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;

//const int INF = 100100100;
//const double ESP = 1e-9;

//int dx[] = { 0, 1, 0, -1 };
//int dy[] = { 1, 0, -1, 0 };

int main()
{
    int n;
    map<string, int> o;

    cin >> n;
    vi t(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        auto it = o.find(s);
        if (it == o.end())
        {
            o.insert(make_pair(s, i));
        }
        cin >> t[i];
    }

    int ans = o.begin()->second;

    for (auto i = o.begin(); i != o.end(); i++) {
        if (t[ans] < t[i->second]) {
            ans = i->second;
        }
        else if(t[ans] == t[i->second]) 
            if (ans > i->second) ans = i->second;
    }

    cout << ans + 1 << endl;
}