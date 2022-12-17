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
using vvi = vector<vi>;

const int INF = 100100100;
const double ESP = 1e-9;

template <class T>
struct Edge {
    int rev, from, to;  // rev:逆向きの辺の番号
    T cap, original_cap;
    Edge(int r, int f, int t, T c) : rev(r), from(f), to(t), cap(c), original_cap(c) {}
};
template <class T>
struct Graph {
    vector<vector<Edge<T>>> G;
    Graph(int n = 0) : G(n) {}
    vector<Edge<T>>& operator[](int i) { return G[i]; }
    const size_t size() const { return G.size(); }
    Edge<T>& redge(Edge<T> e) {  // 逆向きの辺を返す
        return G[e.to][e.rev];   // 自己ループはないと仮定（あれば G[e.to][e.rev + 1] とする必要がある）
    }
    void add_edge(int from, int to, T cap) {  // 有向辺を加える
        G[from].push_back(Edge<T>((int)G[to].size(), from, to, cap));
        G[to].push_back(Edge<T>((int)G[from].size() - 1, to, from, 0));
    }
};
/* FordFulkerson: Ford-Fulkersonのアルゴリズムで最大流を求める構造体
    max_flow(G,s,t) ：グラフGの最大流が求まる
    副作用：G は最大流の残余ネットワークになる
    計算量: O(|f*||E|) (f*:最大流) 
*/
template <class T>
struct FordFulkerson {
    const T INF = 1e9;
    vector<int> used;
    FordFulkerson(){};
    T dfs(Graph<T>& G, int v, int t, T f) {  // 増加可能経路を見つけて増加分のフローを返す
        if (v == t) return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                T d = dfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G.redge(e).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(Graph<T>& G, int s, int t) {
        T flow = 0;
        while (true) {
            used.assign(G.size(), 0);
            T f = dfs(G, s, t, INF);  // f が増加分のフロー
            if (f == 0) {
                return flow;
            } else {
                flow += f;
            }
        }
        return 0;
    }
};

int main() {
    // 入力を受け取る
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);   // グラフを表現する隣接リスト
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        // 頂点 a から頂点 b への辺を張る
        G[a - 1].push_back(b - 1);
        // 無向グラフのため、頂点 b から頂点 a への辺も張る
        G[b - 1].push_back(a - 1);
    }

    vector<int> color(N, -1);   // color[v]：頂点 v の色が黒なら 1, 白なら 0, 未探索なら -1
    vector<int> a, b;
    bool flag = true;
    // 全ての頂点について
    for(int v = 0; v < N; v++) {
        // 頂点 v がすでに訪問済みであれば、スキップ
        if(color[v] != -1) {continue;}
        // そうでなければ、頂点 v を含む連結成分は未探索
        // 頂点 v の色を白で決め打ちしたうえで、幅優先探索を行う
        queue<int> que; // 探索候補の頂点番号を入れるキュー
        color[v] = 0;
        que.push(v);
        a.push_back(v);
        // キューに要素が残っている限り
        while(que.size() > 0) {
            int qv = que.front();
            que.pop();
            // 頂点 qv に隣接している頂点 nv について、
            for(auto nv : G[qv]) {
                // nv がすでに探索済みならば、スキップする
                if(color[nv] != -1) {
                    // 隣り合う頂点どうしが同じ色なら、答えは No
                    if(color[nv] == color[qv]) {flag = false;}
                    continue;
                }
                if (color[qv]) a.push_back(nv);
                else b.push_back(nv);
                // そうでなければ、頂点 nv の色を color[qv] と逆にしたうえで、nv も探索候補に入れる
                color[nv] = 1 - color[qv];
                que.push(nv);
            }
        }
    }


	return 0;
}