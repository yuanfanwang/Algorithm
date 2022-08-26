#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

template<class T> bool chmin(T& a, T b) { if (b < a) { a = b; return true; } return false; };

/*
 * 負の経路があると絶対にダメ
 * 何かしらの方法で 0 以上にすること
 */ 

/*
 * O(ElogV)
 */

using pll = pair<ll, ll>;
using EG = vector<vector<pll>>;
int main() {
    int N, M;
    cin >> N >> M;

    EG G(N);
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back({b, w});
        G[b].push_back({a, w}); // 無向グラフ用
    }
    vector<ll> dist(N, INF);
    int s = 0; // スタート地点
    dist[s] = 0; // 初めの距離

    priority_queue<pll, vector<pll>, greater<pll>> que;
    que.push({dist[s], s});

    while(que.size()) {
        auto [d, v] = que.top();
        que.pop();

        if (d > dist[v]) continue;

        for (auto [nv, w] : G[v]) {
            if (chmin(dist[nv], dist[v]+w)) {
                que.push({dist[nv], nv});
            }
        }
    }

}