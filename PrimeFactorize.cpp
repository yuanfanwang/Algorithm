#include <iostream>
#include <vector>
using namespace std;

// 素数とその指数を返す O(√N)  (高速素因数分解 O(logN) with Eratosthenes ↓)
vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

// 素数を返す
vector<int> prime_factorize(int n) {
    vector<int> res;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(p);
    }
    if (n != 1) res.push_back(n);
    return res;
}

// 約数全列挙
vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    // O(√N)
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    // O(√N logN)
    sort(res.begin(), res.end());
    return res;
}

int main() {
    long long N;
    cin >> N;
    const auto &res = enum_divisors(N);
    for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << end
}


