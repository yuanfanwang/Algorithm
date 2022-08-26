#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
    // ext は サイクルの個数(余剰の辺数)
    // edg は 集合の辺数
    vector<int> par, siz, etr, edg;
    UnionFind(int n) : par(n, -1), siz(n, 1), etr(n, 0), edg(n, 0) {}

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);
        edg[x]++;
        if (x == y) {
            etr[x]++;
            return false;
        }
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y]; etr[x] += etr[y]; edg[x] += edg[y];
        // per[y] = par[x] ではない
        par[y] = x;
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }
};

// 計算量 ElogE

// 辺 e = (u, v) を {w(e), {u, v}} で表す
using Edge = pair<int, pair<int, int>>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(w, {u, v});
    }
    sort(edges.begin(), edges.end());

    // クラスカル法
    long long res = 0;
    UnionFind uf(N);
    for (int i = 0; i < M; ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // 辺(u, v)の追加によってサイクルが形成されるときは追加しない
        if (uf.issame(u, v)) continue;

        res += w;
        uf.unite(u, v);
    }
    cout << res << endl;
}