#include <iostream>
#include <vector>
using namespace std;

// 無限大を表す値
const long long INF = 1LL << 60;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
};

int main() {
    // 頂点数, 辺数, 始点
    int N, M, s;
    cin >> N >> M >> s;

    // 有向グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back(Edge(b, w));
    }

    // ベルマンフォード法
    bool exist_negative_cycle = false;
    vector<long long> dist(N, INF);
    dist[s] = 0;

    for(int i = 0; i < N; ++i) {
        bool update = false; // 更新が発生したかどうかを表すグラフ
        for (int v = 0; v < N; ++v) {
            // dist[v] = INF の時は頂点 v からの緩和を行わない
            if (dist[v] == INF) continue;
            for (auto e : G[v]) {
                // 緩和処理を行い, 更新されたら update を true にする
                if (chmin(dist[e.to], dist[v] + e.w)) {
                    update = true;
                }
            }
        }

        // 更新が行われなかったら、すでに最短路が求められている
        if (!update) break;

        // N 回目の反復で更新が行われたならば、負経路をもつ
        if (i == N - 1 && update) exist_negative_cycle = true;
    }

    if (exist_negative_cycle) cout << "negative cycle" << endl;
    else {
        for(int v = 0; v < N; ++v) {
            if (dist[v] < INF) cout << dist[v] << endl;
            else cout << "INF" << endl;
        }
    }

}