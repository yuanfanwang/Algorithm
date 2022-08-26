
const int MOD = 1000000007;
const int MAX = 5100000;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// MOD を書き換えるときの注意
// mod > n を仮定している
// 常に mod > n が成り立っている時において逆元を用いることができる
// 0 の逆元はないから

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// mod しない用
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll INF = 1LL << 60;
using Graph = vector<vector<ll>>;
Graph dp(35, vector<ll>(35, 0));

ll COMB(int n, int k) {
    return dp[n-k][k];
}

int main() {
    // ll A, B, K; cin >> A >> B >> K;

    dp[0][0] = 1;
    for (int i = 0; i < 31; ++i) {
        for (int j = 0; j < 31; ++j) {
            dp[i][j+1] += dp[i][j];
            dp[i+1][j] += dp[i][j];
        }
    }

    cout << COMB(60, 30) << endl;

}