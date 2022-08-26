#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// ll を mint に変更してもよい
// n P r
ll P(ll n, ll r) {
    if (n < 0 || r < 0 || n < r) return 0;
    ll res = 1;
    while(r--) {
        res *= n;
        n--;
    }
    return res;
}






// 順列全列挙 P!
int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (auto& y : A) for (auto& x : y) cin >> x;

    vector<int> v(10);
    iota(v.begin(), v.end(), 0);
    do {
        for(auto e : v) cout << e << " ";
        cout << endl;
    } while(next_permutation(v.begin(), v.end()));
}





// 部分順列全列挙 nPr

vector<bool> used;

void prm(vector<int>& v) {
    do {
        for (auto e : v) cout << e << " "; cout << endl;
    } while(next_permutation(v.begin(), v.end()));
}

void cmb(int cnt, int last, int n, int r) {
    if (cnt==r) {
        vector<int> st;
        for (int i = 0; i < n; ++i) if (used[i]) st.push_back(i);
        prm(st); return;
    }

    for (int i = last; i < n; ++i) {
        if (!used[i]) {
            used[i] = true;
            cmb(cnt+1, i, n, r);
            used[i] = false;
        }
    }
}

void prm_enum(int n, int r) {
    used.assign(n, false);
    cmb(0, 0, n, r);
}

// int main() {
//     int n, r;
//     cin >> n >> r;
//     prm_enum(n, r); 
//     cout << sum << endl;
// }