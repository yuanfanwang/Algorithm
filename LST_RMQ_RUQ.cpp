#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

class LST_RMQ_RUQ {
private:
    int n;
    vector<ll> node, lazy;
public:
    const ll INF = 1LL << 60;
    LST_RMQ_RUQ(int N) {
        n = 1;
        while (n < N) n *= 2;
        node.assign(2*n - 1, INF);
        lazy.assign(2*n - 1, INF);   
    }

    // set and build
    LST_RMQ_RUQ(vector<ll>& V) {
        int sz = V.size();
        n = 1;
        while (n < sz) n *= 2;
        node.assign(2*n - 1, INF);
        lazy.assign(2*n - 1, INF);  
        for (int i = 0; i < sz; ++i) node[n-1+i] = V[i];
        for (int i = n-2; i >= 0; --i) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void eval(int k) {
        /** INFで更新するときはINF-1とするなど注意が必要 **/
        if (lazy[k] == INF) return;
        if (k < n - 1) {
            lazy[k*2+1] = lazy[k];
            lazy[k*2+2] = lazy[k];
        }
        node[k] = lazy[k];
        lazy[k] = INF;
    }

    // RUQ // 区間[a, b)
    // if you want to update a node you can call this like (a, a+1, x)
    void update(int a, int b, ll x, int k=0, int l=0, int r =-1) {
        if (r < 0) r = n;
        eval(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            eval(k);
            return;
        }
        update(a, b, x, k*2+1, l, (l+r)/2);
        update(a, b, x, k*2+2, (l+r)/2, r);
        node[k] = min(node[k*2+1], node[k*2+2]);
    }

    // RMQ
    ll query(int a=0, int b=-1, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        if (b < 0) b = n;
        eval(k);
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node[k];
        ll vl = query(a, b, k*2+1, l, (l+r)/2);
        ll vr = query(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }

    /**
     * 二分探索を追加する, より深く理解する
     * https://algo-logic.info/segment-tree/
     */

};


// 複数updateする場合は遅延評価が必要だが、一つなら遅延評価はいらないので、普通のセグ木で良い
// 最初はINFのみ、vectorを渡してはいけない、最初だけは評価がされないので
// [l, r)
class ST_RMQ_RUQ {
private:
    int n;
    vector<ll> node;
public:
    const long long INF = 1LL << 60;

    ST_RMQ_RUQ(int N) {
        n = 1;
        while(n < N) n *= 2;
        node.assign(2*n-1, INF);
    }

    void update(int i, ll x) {
        i += n-1;
        node[i] = x;
        while (i > 0) {
            i = (i-1) / 2;
            node[i] = min(node[i*2+1], node[i*2+2]);
        }
    }

    ll query(int a=0, int b=-1, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        if (b < 0) b = n;
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node[k];
        ll vl = query(a, b, k*2+1, l, (l+r)/2);
        ll vr = query(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }

    void print() {
        for (int i = 0; i < 5; ++i) cout << node[i] << " ";
        cout << endl;
    }
};