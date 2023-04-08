#include <iostream>
#include <vector>

using namespace std;

const int INF = 2e+9 + 1;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n+1, INF), b(m+1, INF);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int cnt = 0, i = 0, j = 0;

    while(i < n || j < m)
    {
        cnt++;

        if(a[i] < b[j]) {
            cout << cnt << ' ';
            i++;
        }
        else
        {
            b[j] = cnt;
            j++;
        }
    }

    cout << endl;

    for(int i = 0; i < m; i++) cout << b[i] << ' ';

    cout << endl;

    return 0;
}