#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <cmath>

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
    ll a, b;
    double ans;
    cin >> a >> b;

    ans = (double)a;
    
    for(ll i = 1LL; i < 1e18; i++) {
        double x = (double)b * (double)i + (double)a / sqrt(1 + i);
        if(ans < x) break;
        ans = x;
    }

    cout << std::fixed << std::setprecision(10) << ans << endl;
}