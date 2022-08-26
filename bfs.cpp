#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> BFS(const Graph &G, int s) {
    int N = (int)G.size();
    vector<int> dist(N, -1);
    queue<int> que;

    dist[s] = 0;
    que.push(s);

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for(int nv : G[v]) {
            if (dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    return dist;
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

    vector<int> dist = BFS(G, 0);

    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}