#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <cmath>
#include <bitset>

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
    int n, m;
    cin >> n >> m;

    vi v(n);

    rep(i, n) {
        string s;
        cin >> s;

        int bit = 0;
        for(int j = 0; j < m; j++, bit <<= 1) {
            if(s[j] == 'o') bit |= 1;
        }
        
        bit >>= 1;
        
        v[i] = bit;
    }

    int check = (1 << m) - 1;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if((v[i] | v[j]) == check) cnt++;
        }
    }

    cout << cnt << endl;
}