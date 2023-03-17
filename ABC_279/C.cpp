#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <stack>
#include <iomanip>

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
using vvi = vector<vi>;

const int INF = 100100100;
const double ESP = 1e-9;

int main()
{
    int cnt = 0;
    int h, w;
    cin >> h >> w;
    
    vector<string> s(h), t(h);
    
    rep(i,h) {
        cin >> s[i];
    }

    rep(i,h) {
        cin >> t[i];
    }

    vector<string> u(w), v(w);
    
    rep(i,w) {
        string tmp1 = "", tmp2 = "";
        rep(j,h){
            tmp1 += s[j][i];
            tmp2 += t[j][i];
        }
        u[i] = tmp1;
        v[i] = tmp2;
    }

    sort(u.begin(), u.end());
    sort(v.begin(), v.end());

    rep(i,w) {
        if (v[i] != u[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}