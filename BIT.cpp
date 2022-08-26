#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// BIT の first index は 1 から
template<typename T>
struct BIT
{
    int n;
    vector<T> bit;
    BIT(int n_) : n(n_ + 1), bit(n, 0) {}

    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    // [l, r) first_idx = 1
    T query(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};

// BIT の first index は 1 から

struct BIT {
    int n;
    vector<vector<ll>> bit;
    BIT(int n_) : n(n_+1) {
        bit.assign(2, vector<ll>(n, 0));
    }

    void add_sub(int p, int i, ll x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }

    void add(int l, int r, ll x) {
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r,  x * (r - 1));
        add_sub(1, l,  x);
        add_sub(1, r, -x);
    }

    ll sum_sub(int p, int i) {
        ll s = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            
            s += bit[p][idx];
        }
        return s;
    }
    
    ll sum(int i) {
        return sum_sub(0, i) + sum_sub(1, i) * i;
    }
    
    // [l, r)の区間和
    ll query(int l, int r) {return sum(r-1) - sum(l-1); }


    int lower_bound(ll w) {
        if (w <= 0) return 0;
        int x = 0, r = 1;
        while(r < n) r = r << 1;
        for (int len = r; len > 0; len = len >> 1) {
            if (x + len < n && sum(x+len) < w) { // ここはsum(x+len)のはず
                w -= sum(x+len);
                x += len;
            }
        }
        return x + 1;
    }

    /**
     * https://algo-logic.info/binary-indexed-tree/
     */

};

// index は 1 から始まることに注意
int main() {
    ll N, D, A;
    cin >> N >> D >> A;
    vector<pair<ll, ll>> M(N);
    for (auto& m : M) cin >> m.first >> m.second;
    sort(M.begin(), M.end());
    vector<ll> X(N);
    for(int i = 0; i < N; ++i) X[i] = M[i].first;

    BIT bit(N);
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ll x = M[i-1].first;
        ll h = M[i-1].second;
        ll d = bit.query(i, i+1);
        if (d < h) {
            int cnt = round_up(h-d, A);
            ans += cnt;
            int right = upper_bound(X.begin(), X.end(), x + 2*D) - X.begin();
            bit.add(i, right+1, A*cnt);
        }
    }
    cout << ans << endl;
}