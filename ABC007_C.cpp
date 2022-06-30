#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100100100;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main()
{
    int r, c;
    pair<int, int> s, g;

    cin >> r >> c;
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;

    vector<pair<int, int>> q;
    vector<vector<int>> dist(r, vector<int>(c, INF));
    vector<string> map(r);

    for (int i = 0; i < r; i++) cin >> map[i];

    q.push_back(make_pair(s.first - 1 , s.second - 1));
    dist[s.first - 1][s.second - 1] = 0;
    map[s.first - 1][s.second - 1] = '#';

    while (q.size())
    {
        pair<int, int> p = q[0];
        q.erase(q.begin());

        for (int i = 0; i < 4; i++) {
            int x = p.first + dx[i], y = p.second + dy[i];
            if (map[x][y] == '.') {
                q.push_back(make_pair(x, y));
                dist[x][y] = dist[p.first][p.second] + 1;
                map[x][y] = '#';
            }
        }
    }

    cout << dist[g.first - 1][g.second - 1] << endl;
}