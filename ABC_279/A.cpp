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
    string s;
    cin >> s;

    rep(i,s.size()) {
        if (s[i] == 'v') cnt++;
        if (s[i] == 'w') cnt += 2;
    }

    cout << cnt << endl;
}