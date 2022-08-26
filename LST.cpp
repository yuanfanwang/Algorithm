#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;


template<class T, class U>
struct LazySegmentTree{
    virtual T f(const T&, const T&) = 0;
    virtual void m(ll, T&, const U&) = 0;
    virtual void c(U&, const U&) = 0;
    ll size = 1, rank = 0;
    vector<T> data;
    vector<U> lazy;
    const T def_value;
    const U def_lazy;
    LazySegmentTree(ll n, const T& def_value, const U& def_lazy): def_value(def_value), def_lazy(def_lazy){
        while(size < n){
            size *= 2;
            rank++;
        }
        data.assign(size * 2, def_value);
        lazy.assign(size * 2, def_lazy);
    }
    LazySegmentTree(const vector<T>& v, const T& def_value, const U& def_lazy): def_value(def_value), def_lazy(def_lazy){
        while(size < v.size()){
            size *= 2;
            rank++;
        }
        data.assign(size * 2, def_value);
        lazy.assign(size * 2, def_lazy);
        for(ll i = 0; i < v.size(); i++) data[size + i] = v[i];
    }
    void push(ll at){
        if(!at) return;
        ll r = 31 - __builtin_clz(at);
        for(ll i = r; i > 0; i--){
            ll a = at >> i;
            if(lazy[a] != def_lazy){
                m(rank + i - r - 1, data[a * 2], lazy[a]);
                m(rank + i - r - 1, data[a * 2 + 1], lazy[a]);
                c(lazy[a * 2], lazy[a]);
                c(lazy[a * 2 + 1], lazy[a]);
                lazy[a] = def_lazy;
            }
        }
    }
    void update(ll at){
        while(at /= 2){
            data[at] = f(data[at * 2], data[at * 2 + 1]);
        }
    }
    T operator[](ll at){
        at += size;
        push(at);
        return data[at];
    }
    void set(ll at, const T& val){
        at += size;
        push(at);
        data[at] = val;
        update(at);
    }
    void query(ll l, ll r, const U& val){
        if(l >= r) return;
        l += size;
        r += size;
        ll L = l >> __builtin_ctz(l), R = (r >> __builtin_ctz(r)) - 1;
        push(L);
        push(R);
        for(ll rank = 0; l < r; l /= 2, r /= 2, rank++){
            if(l & 1){
                m(rank, data[l], val);
                c(lazy[l++], val);
            }
            if(r & 1){
                m(rank, data[--r], val);
                c(lazy[r], val);
            }
        }
        update(L);
        update(R);
    }
    T get(ll l, ll r){
        if(l >= r) return def_value;
        T L = def_value, R = def_value;
        l += size; r += size;
        push(l);
        push(r - 1);
        for(; l < r; l /= 2, r /= 2){
            if(l & 1) L = f(L, data[l++]);
            if(r & 1) R = f(data[--r], R);
        }
        return f(L, R);
    }
    void clear(){
        for(auto& i : data) i = def_value;
    }
};

template<class T>
struct RUQRMQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){ return max(a, b); }
    void m(ll rank, T& x, const T& val){ x = val; }
    void c(T& a, const T& b){ a = b; }
    RUQRMQ(ll n, const T& def_value, const T& def_lazy = numeric_limits<T>::max()) : Base(n, def_value, def_lazy){}
    RUQRMQ(const vector<T>& v, const T& def_value, const T& def_lazy = numeric_limits<T>::max()) : Base(v, def_value, def_lazy){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};

template<class T>
struct RAQRMQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){ return max(a, b); }
    void m(ll rank, T& x, const T& val){ x += val; }
    void c(T& a, const T& b){ a += b; }
    RAQRMQ(ll n, const T& def_value, const T& def_lazy = T()) : Base(n, def_value, def_lazy){}
    RAQRMQ(const vector<T>& v, const T& def_value, const T& def_lazy = T()) : Base(v, def_value, def_lazy){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};

template<class T>
struct RUQRmQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){ return min(a, b); }
    void m(ll rank, T& x, const T& val){ x = val; }
    void c(T& a, const T& b){ a = b; }
    RUQRmQ(ll n, const T& def_value, const T& def_lazy = numeric_limits<T>::max()) : Base(n, def_value, def_lazy){}
    RUQRmQ(const vector<T>& v, const T& def_value, const T& def_lazy = numeric_limits<T>::max()) : Base(v, def_value, def_lazy){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};

template<class T>
struct RAQRmQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){ return min(a, b); }
    void m(ll rank, T& x, const T& val){ x += val; }
    void c(T& a, const T& b){ a += b; }
    RAQRmQ(ll n, const T& def_value, const T& def_lazy = T()) : Base(n, def_value, def_lazy){}
    RAQRmQ(const vector<T>& v, const T& def_value, const T& def_lazy = T()) : Base(v, def_value, def_lazy){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};

template<class T>
struct RUQRSQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){ return a + b; }
    void m(ll rank, T& x, const T& val){ x = val << rank; }
    void c(T& a, const T& b){ a = b; }
    RUQRSQ(ll n, const T& def_value = T(), const T& def_lazy = numeric_limits<T>::max()) : Base(n, def_value, def_lazy){}
    RUQRSQ(const vector<T>& v, const T& def_value = T(), const T& def_lazy = numeric_limits<T>::max()) : Base(v, def_value, def_lazy){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};

template<class T>
struct RAQRSQ : LazySegmentTree<T, T>{
    using Base = LazySegmentTree<T, T>;
    T f(const T& a, const T& b){ return a + b; }
    void m(ll rank, T& x, const T& val){ x += val << rank; }
    void c(T& a, const T& b){ a += b; }
    RAQRSQ(ll n, const T& def_value = T()) : Base(n, def_value, def_value){}
    RAQRSQ(const vector<T>& v, const T& def_value = T()) : Base(v, def_value, def_value){
        for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};



int main() {
    int N = 10;

    // 初期化　任意の配列必要
    vector<ll> v1(N+1, 0);
    RAQRSQ<ll> seg1(v1);

    // add
    seg1.query(0, 2, 4);
    for (int i = 0; i <= N; ++i) cout << seg1[i] << " "; cout << endl;

    // sum
    cout << seg1.get(0, 3) << endl;

    



   

    // 初期化　任意の配列必要
    vector<ll> v2(N+1, 0);
    // miminum を求めるためのデフォルト最大値
    RUQRmQ<ll> seg2(v2, INF);

    // update
    seg2.query(0, 2, 5);
    seg2.query(5, 9, 6);
    for (int i = 0; i <= N; ++i) cout << seg2[i] << " "; cout << endl;

    // minimum
    cout << seg2.get(5, 9) << endl;

    






    // 初期化　任意の配列必要
    vector<ll> v3(N+1, 0);
    // miminum を求めるためのデフォルト最大値
    RAQRmQ<ll> seg3(v3, INF);

    // add
    seg3.query(0, 5, 3);
    seg3.query(4, 6, 5);
    for (int i = 0; i <= N; ++i) cout << seg3[i] << " "; cout << endl;

    // minimum
    cout << seg3.get(0, 6) << endl;

    


    // 初期化　任意の配列必要
    vector<ll> v4(N+1, 5);
    RUQRSQ seg4(v4);

    // add
    seg4.query(4, 8, 3);
    seg4.query(5, 9, 6);
    for (int i = 0; i <= N; ++i) cout << seg4[i] << " "; cout << endl;

    // sum
    cout << seg4.get(4, 6) << endl;

}