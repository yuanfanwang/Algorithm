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
 * O(V*V)
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

    vector<bool> used(N, false);
    for (int i = 0; i < N; ++i) {

        ll mn_dist = INF;
        int mn_v = -1;

        for (int v = 0; v < N; ++v) {
            if (used[v]) continue;
            if (dist[v] < mn_dist) continue;
            mn_dist = dist[v];
            mn_v = v;
        }

        if (mn_v == -1) break;

        for (auto [nv, w] : G[mn_v]) chmin(dist[nv], dist[v] + w);

        used[mn_v] = true;
    }

}