#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
 
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pint = pair<int, int>;
using Graph = vector<vector<ll>>;
using EGraph = vector<vector<pll>>;

const ll e9 = 1000000000;
const ll e18 = 1000000000000000000;
const ll INF = 1LL << 60;
const int inf = 1LL << 30;
const int MOD = 1e9+7;
const int mOD = 998244353;

const vector<ll> dx = {0, 1, 0, -1, 1, -1, 1, -1};
const vector<ll> dy = {1, 0, -1, 0, 1, 1, -1, -1};

template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; };
template<class T> bool chmin(T& a, T b) { if (b < a) { a = b; return true; } return false; };
template<class T> void printGrid(vector<vector<T>>& G, int s = 4) { for (auto y : G) { for (auto x : y) if (x==INF||x==-INF) cout << "INF "; else cout << left << setw(s) << x; cout << endl; } }
template<class... T> void printEnum(T... args) { for (auto e : { args... }) { cout << e << " "; } cout << endl; }
template<class T> void printVec(vector<T>& v) { for (auto e : v) if (e==INF||e==-INF) cout << "INF "; else cout << e << " "; cout << endl; }
string bitStr(ll X) { stringstream ss; ss << bitset<60>(X); string s = ss.str(); reverse(s.begin(), s.end()); while(s.back()=='0') s.pop_back(); reverse(s.begin(), s.end()); if (s.empty()) s.push_back('0'); return s; }
int strToInt(const string& s) {return stoi(s);}
ll strToLong(const string& s) {return stoll(s);}
template<class T> void out(T a) {cout << a << endl;}
template<class T> T carry(T a, T b) { return ((a + (b-1)) / b); } 
template<class T> T gcd(T a, T b) { if (b==0) return a; else return gcd(b, a%b); }
template<class T> T lcm(T a, T b) { if (!a || !b) return 0; else return a * b / gcd(a, b);}
ll mod(ll a, ll m) { return (a % m + m) % m; }
ll mpow(ll a, ll b, ll m){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2; } return ans; }
void out(double ans) {cout << fixed << setprecision(10) << ans << endl;}
void out(bool ans) { if (ans) cout << "Yes" << endl; else cout << "No" << endl;}
bool compare(const pair<int, int>& a, const pair<int, int>& b) { if (a.first != b.first) return b.first < a.first; else return a.second < b.second; }
double rad(double x, double y, bool positive = false) {double res = atan2(y, x); if (positive && res < 0) res = 2*M_PI + res; return res; } // -π < res <= π positive 0 <= res < 2π
double deg(double x, double y, bool positive = false) {return rad(x, y, positive) * 180 / M_PI;}

template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
using mint = Fp<mOD>;
using pll = pair<ll, ll>;
using eg = vector<vector<pll>>;

int main() {
}