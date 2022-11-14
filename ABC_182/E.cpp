#include <iostream>
#include <vector>

using namespace std;

/*!
@brief ランレングス圧縮をABC_182_E向けに拡張した．
@param v 横1行または縦1列．
@return 圧縮した結果を返す．pair型の各要素は次の通り．firstはbool型で圧縮した数字の中に1があったかどうかを表す．secondはint型で圧縮した要素数を表す．
@details int型の1次元の配列を引数として受け取り，各要素について，0とそれ以外にランレングス圧縮し，結果をpair型の1次元配列として返す．
*/
vector<pair<bool, int>> ex_groupby(vector<int> v)
{
    vector<pair<bool, int>> res;

    for(int i = 0; i < v.size(); i++)
    {
        pair<bool, int> t;

        // v[i]が証明ならTRUE，それ以外はとりあえずFALSE
        if(v[i] == 1) t.first = true;
        else t.first = false;

        // 要素数は1に初期化
        t.second = 1;

        while(i < v.size() - 1)
        {
            // v[i]がBlockの時
            // v[i+1]がBlockなら圧縮
            if(v[i] == 0 && v[i + 1] == 0) {
                t.second++;
                i++;
            }
            // v[i]がBlock以外の時
            // v[i+1]がBlock以外なら圧縮
            else if(v[i] != 0 && v[i + 1] != 0) {
                //圧縮する要素に証明があればTRUEにする
                if(v[i + 1] == 1) t.first = true;
                t.second++;
                i++;
            }
            else break;
        }

        res.push_back(t);
    }

    return res;
}

int main()
{
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    // 照らされているかどうか
    vector<vector<bool>> check(h, vector<bool>(w, false));

    // 何も置かれていない状態に初期化
    // 横向きについて
    vector<vector<int>> row(h, vector<int>(w, -1));
    // 縦向きについて
    vector<vector<int>> col(w, vector<int>(h, -1));

    // 入力受け取り
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        row[a - 1][b - 1] = 1;
        col[b - 1][a - 1] = 1;
    }

    for(int i = 0; i < m; i++)
    {
        int c, d;
        cin >> c >> d;
        
        row[c - 1][d - 1] = 0;
        col[d - 1][c - 1] = 0;
    }

    // 横について確認
    for(int i = 0; i < h; i++)
    {
        int now = 0;
        auto res = ex_groupby(row[i]);

        for(auto r : res)
        {
            // 照明があればcheckをTrueに
            if(r.first) {
                for(int j = 0; j < r.second; j++)
                {
                    check[i][now + j] = true;
                }
            }

            now += r.second;
        }
    }

    // 縦について確認
    for(int i = 0; i < w; i++)
    {
        int now = 0;
        auto res = ex_groupby(col[i]);

        for(auto r : res)
        {
            // 照明があればcheckをTrueに
            if(r.first) {
                for(int j = 0; j < r.second; j++)
                {
                    check[now + j][i] = true;
                }
            }

            now += r.second;
        }
    }

    // 照らされているマスを数える
    int ans = 0;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            if(check[i][j]) ans++;

    cout << ans << endl;

    return 0;
}