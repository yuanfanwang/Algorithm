#include <iostream>
#include <vector>
using namespace std;

int W, H, N;
vector<int> X1, Y1, X2, Y2;
vector<vector<bool>> fld;

int compress(vector<int>& x1, vector<int>& x2, int w) {
    vector<int> xs;
    for (int i = 0; i < N; ++i) {
        for (int d = -1; d <= 1; ++d) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if (1 <= tx1 && tx1 <= w) xs.push_back(tx1);
            if (1 <= tx2 && tx2 <= w) xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < N; ++i) {
        // 座標を更新
        // binary_search でもっと高速に
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }
    return xs.size();
}

void solve() {
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    // 線のある部分を塗りつぶし
    fld.assign(H, vector<bool>(W, false));
    for (int i = 0; i < N; ++i) {
        for (int y = Y1[i]; y <= Y2[i]; ++y) {
            for (int x = X1[i]; x <= X2[i]; ++x) {
                fld[y][x] = true;
            }
        }
    }

    // 領域を数える

}


// https://algo-logic.info/coordinate-compress/

template <typename T>
vector<T> compress(vector<T> &X) {
    vector<T> vec = X;
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 0; i < (int)X.size(); ++i) {
        X[i] = lower_bound(vec.begin(), vec.end(), X[i]) - vec.begin();
    }
    return vec; // 復元用
}