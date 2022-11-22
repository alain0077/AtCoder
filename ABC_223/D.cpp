#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> e(n, 0);
    
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        g[a].push_back(b);
        e[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;

    for(int i = 0; i < n; i++)
    {
        if(e[i] == 0) pq.push(i);
    }

    while(!pq.empty())
    {
        int q = pq.top();
        pq.pop();
        ans.push_back(q);
        for(auto v : g[q])
        {
            e[v]--;
            if(e[v] == 0) pq.push(v);
        }
    }

    if(ans.size() != n) cout << -1;
    else {
        for(int i = 0; i < n; i++) 
        {
            cout << ans[i] + 1;
            if(i != n-1) cout << " ";
        }
    }
    cout << endl;
}