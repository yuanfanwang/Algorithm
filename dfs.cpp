#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;

    // v からいける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);
    for(int v = 0; v < N; ++v) {
        if (seen[v]) continue;
        dfs(G, v);
    }
}









// 辺と頂点の関係　辺に重み
// 重みと行き先さえあればよい i -> j なら i グループに 「行き先」j と「重み」i があればよい

// 木用のdfs
using Edge = pair<int, int>;
using EGraph = vector<vector<Edge>>;

int N;
EGraph G;
vector<int> res;

void dfs(int v, int p) {
    for (auto e : G[v])  {
        if (e.first == p) continue;
        dfs(e.first, v);
    }
}