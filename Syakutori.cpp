#include <iostream>
#include <string>
#include <vector>

using namespace std;
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; };


// https://atcoder.jp/contests/abc229/editorial/2956

int main() {
    int N;

    int r;
    int ans;
    for (int l = 0; l < N; ++l) {
        while(r < N /* && whileを外れる条件 */) {
            /*処理*/
            /* r のインクリメント */
        }
        /* l がインクリメントされる時の処理 */
        /* ans をchmax, chmin などで評価 */
    }
    cout << ans << endl;
}




/**
 * i = 0 がカウントされてない
 * right は初めからインクリメントされるので、そこでバグる可能性が
 */


// [l, r] 
int main() {
    int N;
    string S;
    cin >> N >> S;
    
    // 条件が true なら right をインクリメントする
    auto check = [&](int l, int r) {
        string str = S.substr(l, r - l);
        auto idx = S.rfind(str);
        if (idx == string::npos) return false;
        if (r>idx) return false;
        return true;
    };

    // ミスったらコメントアウトを展開してみる
    int left = 0, right = 0, ans = 0;
    while(right < N) {
        // if (left == right && right < N-1) right++;
        if (left == right) right++;
        // if (right == N) {break;}
        if (check(left, right)) {
            chmax(ans, right-left);
            right++;
        }
        else left++;
    }
    cout << ans << endl;
}

