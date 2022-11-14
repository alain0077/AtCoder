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
    int n, w, ans = 0;
    vector<int> f(1000001, 0);
    cin >> n >> w;
 
    vector<int> a(n + 1);
 
    for (int i = 0; i < n + 1; i++) cin >> a[i];
 
    for (int i = 0; i < n + 1; i++) {
        if (a[i] < w && !f[a[i]]) {
            ans++;
            f[a[i]]++;
        }
        for (int j = i + 1; j < n + 1; j++) {
            if (a[i] + a[j] < w && !f[a[i] + a[j]]) {
                ans++;
                f[a[i] + a[j]]++;
            }
            for (int k = j + 1; k < n + 1; k++) {
                if (a[i] + a[j] + a[k] < w && !f[a[i] + a[j] + a[k]]) {
                    ans++;
                    f[a[i] + a[j] + a[k]]++;
                }
            }
        }
    }
 
    cout << ans << endl;
}