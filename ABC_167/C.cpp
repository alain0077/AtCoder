#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 1 << 30;

int main()
{
    int n, m, x, ans = INF;
    cin >> n >> m >> x;
    
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int> m);

    for (int i = 0; i < n; i++) { 
        cin >> c[i];
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    for(int bit = 0; bit < (1 << n); bit++) {
        int sum = 0;
        vector<int> cnt(m, 0);

        for(int i = 0; i < n; i++) {
            if(bit & (1 << i)) {
                sum += c[i];
                for(int j = 0; j < m; j++) cnt += a[i][j]; 
            }
        }

        bool f = true;
        for(int i = 0; i < n; i++) {
            if(a_count[i]<x) f = false;
        }
        if(f) ans = min(ans, sum);
    }

    if(ans < INF) cout << ans << endl;
    else cout << -1 << endl;
}