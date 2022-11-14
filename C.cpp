#include <iostream>
#include <vector>

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

using namespace std;

struct P
{
    int x, y;
};

int main()
{
    int n;
    cin >> n;

    vector<P> v(n);
    vector<vector<bool>> map(5005, vector<bool>(5005, false));

    for(int i = 0; i < n; i++)
    {
        cin >> v[i].y >> v[i].x;
        map[v[i].y][v[i].x] = true;
    }

    int ans = 0;

    for(auto t : v) {
        for(auto p : v) {
            if(t.x == p.x && t.y == t.y) continue;

            int x = p.x - t.x;
            int y = p.y - t.y;

            P coor1 = {p.x + y, p.y - x};
            P coor2 = {t.x + y, p.y - x};

            if(coor1.y < 0 || coor1.x < 0 || coor2.y < 0 || coor2.x < 0 ) continue;
            if(coor1.y > 5000 || coor1.x > 5000 || coor2.y > 5000 || coor2.x > 5000 ) continue;

            if(map[coor1.y][coor1.x] && map[coor2.y][coor2.x]) {
                chmax(ans, x * x + y * y);
            }
        }
    }

    cout << ans << endl;
}