#include <iostream>
#include <vector>
#include <iomanip>
#include <complex>
#include <cmath>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <list>

using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const int MOD = 998244353;

template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; };
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; };
template<class T> void printGrid(vector<vector<T>>& G) { for (auto y : G) { for (auto x : y) cout << x << " "; cout << endl; } }
template<class... T> void printEnum(T... args) { for (auto e : { args... }) { cout << e << " "; } cout << endl; }
template<class T> void printVec(vector<T>& v) { for (auto e : v) cout << e << " "; cout << endl; }
template<class T> void out(T a) {cout << a << endl;}
template<class T> T round_up(T a, T b) { return ((a + (b-1)) / b); } 
void out(double ans) {cout << fixed << setprecision(10) << ans << endl;}
void out(bool ans) { if (ans) cout << "Yes" << endl; else cout << "No" << endl;}

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> imos;
    for (int i = 0; i < N; ++i) {
        ll a, b;
        cin >> a >> b; // [a, b) にする つまり a日目から b-1日目まで連続
        imos.push_back({a, 1});
        imos.push_back({a+b, -1});
    }
    sort(imos.begin(), imos.end());
    vector<ll> ans(N+1);
    ll cnt = 0;
    for (int i = 0; i < imos.size()-1; ++i) {
        cnt += imos[i].second;
        ans[cnt] += imos[i+1].first - imos[i].first;
    }
    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << endl;
}


/*　prev を用意したり、同じ場所でのカウントをまず更新したりしたバージョン */

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> imos;
    for (int i = 0; i < N; ++i) {
        ll a, b;
        cin >> a >> b;
        imos.push_back({a, 1});
        imos.push_back({a+b, -1});
    }
    sort(imos.begin(), imos.end());
    vector<ll> ans(N+1);
    ll cnt = 0;
    ll prev = imos[0].first;
    for (int i = 0; i < imos.size(); ++i) {
        ll now = imos[i].first;
        ll x = imos[i].second;
        if (prev == now) cnt += x;
        else {
            ans[cnt] += now - prev;
            prev = now;
            cnt += x;
        }
    }
    // ans[cnt] += imos.back().first - prev;
    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << endl;
}