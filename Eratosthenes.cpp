#include <bits/stdc++.h>
using namespace std;


// 高速素因数分解 // テーブルを作るのでint型出ないとメモリ足りない

struct Eratosthenes {

    // 素数判定テーブル
    vector<bool> isprime;
    // 整数 i を割り切る最小の素数
    vector<int> minfactor;

    // 前処理　O(Nlog log N)
    Eratosthenes(int N) : isprime(N+1, true), minfactor(N+1, -1) {

        // 1はあらかじめふるい落としておく
        isprime[1] = false;
        minfactor[1] = 1;

        // 篩
        for (int p = 2; p <= N; ++p) {
            // 既に合成数であるものはスキップ
            if (!isprime[p]) continue;
            // p についての情報更新
            minfactor[p] = p;
            // p 以外の p の倍数から素数ラベルを剥奪
            for (int q = p * 2; q <= N; q += p) {
                // q は合成数なのでふるい落とす
                isprime[q] = false;
                // q は p で割り切れる旨を更新
                if (minfactor[q] == -1) minfactor[q] = p;
            }
        }

    }

    // 高速素因数分解
    // pair (素因数, 指数) の vector を返す
    // O(log N)
    vector<pair<int,int>> factorize(int n) {
        vector<pair<int, int>> res;
        while(n > 1) {
            int p = minfactor[n];
            int exp = 0;

            // n で割り切れる限り割る
            while (minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    // 高速約数列挙
    vector<int> divisors(int n) {
        vector<int> res({1});

        // n を素因数分解 (メンバ関数使用)
        auto pf = factorize(n);

        // 約数列挙
        for (auto p : pf) {
            int s = (int)res.size();
            for (int i = 0; i < s; ++i) {
                int v = 1;
                for (int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};

int main() {
    // エラトステネスの篩
    // 初期化 N : N までの整数が素数か判定
    Eratosthenes er(50);

    // 結果表示
    for (int n = 2; n <= 50; ++n) {
        auto pf = er.factorize(n);
        cout << n << ": ";
        for (int i = 0; i < pf.size(); ++i) {
            if (i > 0) cout << " * ";
            cout << pf[i].first << "^" << pf[i].second;
        }
        cout << endl;
    }
}