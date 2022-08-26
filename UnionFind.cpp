#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct UnionFind {
    // ext は サイクルの個数(余剰の辺数)
    // edg は 集合の辺数
    /*  
     * 閉路があれば辺数が変わる
     * 構築中に閉路を検出するなら issame で判別すればよい
     * 閉路がなければ常に issame = false である
     */
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
        par[y] = x;
        return true;
    }

    int edge(int x) {
        return edg[root(x)];
    }

    int size(int x) {
        return siz[root(x)];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }
};
