#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 2147483647;

int main()
{
    int n;
    cin >> n;
    vector<int> t(10, 0);
    vector<string> s(n);

    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < 10; i++) {
        int cnt = 0;
        auto tmp = s;
        while (1) {
            for (int j = 0; j < tmp.size(); j++) {
                if (int(tmp[j][t[i] % 10] - '0') == i) {
                    tmp.erase(tmp.begin() + j);
                    cnt++;
                    break;
                }
            }

            if (tmp.size() == 0) break;

            t[i]++;
        }
    }

    int ans = INF;
    for (int i = 0; i < 10; i++) {
        ans = min(ans, t[i]);
    }

    cout << ans << endl;
}