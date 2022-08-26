
#include <iostream>
using namespace std;
using ll = long long;



/** 拡張ユークリッドの互除法が使える時
 * x が mod b の逆元であるとは、
 * ax ≡ 1 (mod b) が成立するということ
 * すなわち
 * ax + by = 1 を満たす y が存在するということ
 * この式からx = a^-1 を求めるためには
 * 「aとbが互いに素」でなければならない
 */




/** フェルマーの小定理が使える時
 * p を素数、a を 「p の倍数でない整数」として
 * a ^ (p-1) ≡ 1 (mod p) が成立する
 */



// 最大公約数
ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

// ax + by = gcd(a, b) となる x, y, d = gcd(a, b) を求める
ll extGCD(ll a, ll b, ll& x, ll& y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    // 拡張ユークリッド互除法
    ll d = extGCD(b, a%b, y, x);
    y -= a / b * x;
    return d;
}

/* 元々の形(丁寧に) */
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long q = a/b;
    long long r = a%b;
    long long s, t;
    long long d = extGCD(b, r, s, t);
    x = t;
    y = s - q * x;
    return d;
}

// 負の数にも対応したmod
ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

// 法をmとした時, a の逆元 (a^-1) を計算
ll modinv(ll a, ll m) {
    ll x, y;
    extGCD(a, m, x, y);
    return mod(x, m);
}

ll solve() {
    ll N, S, K;
    cin >> N >> S >> K;
    ll x, y;
    ll g = extGCD(N, K, x, y);
    if (S%g) return -1;
    N /= g, S /= g, K /= g;
    ll res = mod(modinv(K, N) * S * -1, N);
    return res;
}

int main() {
    int T;
    cin >> T;
    while(T--) cout << solve() << endl;
}





// // 実装が簡単 フェルマーの小定理を用いたバージョン

// // 二分累乗法
// ll modpow(ll a, ll n, ll mod) {
//     ll res = 1;
//     while (n > 0) {
//         if (n&1) res = res * a % mod;
//         a = a * a % mod;
//         n >>= 1;
//     }
//     return res;
// }

// // a^-1を計算 ただし、フェルマーの小定理を利用しているので
// // mod が 素数であり、かつ、a は mod の倍数でないことが必要
// ll modinv(ll a, ll mod) {
//     return modpow(a, mod-2, mod);
// }