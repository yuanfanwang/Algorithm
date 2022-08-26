#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// [l, r) になってる
template<class T>
class LST_RAQ_RSQ {
private:
    int n;
    vector<T> node, lazy;
public:
    LST_RAQ_RSQ(int N) {
        n = 1;
        while (n < N) n *= 2;
        node.assign(2*n - 1, 0);
        lazy.assign(2*n - 1, 0);   
    }

    // set and build
    LST_RAQ_RSQ(vector<T>& V) {
        int sz = V.size();
        n = 1;
        while (n < sz) n *= 2;
        node.assign(2*n - 1, 0);
        lazy.assign(2*n - 1, 0);  
        for (int i = 0; i < sz; ++i) node[n-1+i] = V[i];
        for (int i = n-2; i >= 0; --i) node[i] = node[2*i+1] + node[2*i+2];
    }

    void eval(int k) {
        if (lazy[k] == 0) return;
        node[k] += lazy[k];
        if (k < n - 1) {
            lazy[2*k+1] += lazy[k]/2;
            lazy[2*k+2] += lazy[k]/2;
        }
        lazy[k] = 0;
    }

    // RAQ(RUQ)
    void add (int a, int b, T x, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        eval(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] += (r-l)*x;
            eval(k);
            return;
        }
        add(a, b, x, 2*k+1, l, (l+r)/2);
        add(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = node[2*k+1] + node[2*k+2];
    }

    // RSQ
    T query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return 0;
        eval(k);
        if (a <= l && r <= b) return node[k];
        T lx = query(a, b, 2*k+1, l, (l+r)/2);
        T rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx + rx;
    }

    /**
     * https://atcoder.jp/contests/abc153/submissions/9747348
     * https://tsutaj.hatenablog.com/entry/2017/03/30/224339
     */

};

// 遅延評価なしのやつ
// 今の所BITでOK