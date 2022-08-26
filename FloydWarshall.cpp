#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll INF = 1LL << 60;

template<class T> bool chmin(T& a, T b) { if (b <= a) { a = b; return true; } return false; };

int main() {
    // 頂点数, 辺数
    int N, M; cin >> N >> M;
    // dp 配列 (INFで初期化)
    // dp[k][i][j] := 頂点 0, 1, ... , k-1 のみを中継点として通ってよいとした場合の、頂点 i から頂点 j への最短路長
    vector<vector<ll>> dp(N, vector<ll>(N, INF));


    // dp 初期条件
    for (int i = 0; i < M; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        // 片方だけ（無向辺もいける）
        dp[a][b] = w;
    }
    for (int i = 0; i < N; ++i) dp[i][i] = 0;


    // dp 遷移
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i==k || j==k) continue;
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    // 結果出力
    // もし dp[v][v] < 0 なら負経路が存在する
    bool exist_negative_cycle = false;
    for (int v = 0; v < N; ++v) {
        if (dp[v][v] < 0) exist_negative_cycle = true;
    }
    if (exist_negative_cycle) {
        cout << "negative cycle" << endl;
    }
    else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j) cout << " ";
                if (dp[i][j] < INF/2) cout << dp[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }

}