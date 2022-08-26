#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

// 有向グラフであってサイクルのないグラフのことを DAG
// DAG でなければいけない
// 順序がもとまれば、dp ができる
// DAG <=> トポロジカルソート可能

vector<bool> seen;
vector<int> order; // トポロジカルソート順を表す
void rec(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        rec(G, next_v);
    }

    // v-out を記録
    order.push_back(v);
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
    }

    seen.assign(N, false);
    order.clear();
    for(int v = 0; v < N; ++v) {
        if (seen[v]) continue;
        rec(G, v);
    }
    reverse(order.begin(), order.end()); // 逆順に

    // 出力
    for (auto v : order) cout << v << " -> ";
    cout << endl;

}








// bfs でトポロジカル、閉路検出もできる

int main() {
    int N, E;
    cin >> N >> E;
    vector<int> ans;
    vector<int> ind(N);
    vector<vector<int>> G(N);
    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    for (int i = 0; i < N; ++i) {
        for (auto e : G[i]) {
            ind[e]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < N; ++i) {
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while(!que.empty()) {
        int now = que.front();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e]--;
            if (ind[e]==0) {
                que.push(e);
            }
        }
    }
    if (ans.size() == N) cout << 0 << endl;
    else cout << 1 << endl;
}

