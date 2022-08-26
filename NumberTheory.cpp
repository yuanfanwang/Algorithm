#include <iostream>

using namespace std;
using ll = long long;

// 最大公約数
template<class T>
T gcd(T a, T b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

//  最小公倍数
template<class T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

// [l, r] の中に x の倍数が何個あるか
template<class T>
T cnt(T x, T l, T r) {
    l--;
    return r/x - l/x;
}

// 繰り上げ
template<class T>
T round_up(T a, T b) {
    return ((a + (b-1)) / b);
}

