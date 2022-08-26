#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
tree<int,null_type,greater<int>,rb_tree_tag, tree_order_statistics_node_update> s;

int main() {
    int n, k;
    cin >> n >> k;
    while(n--) {
        int v;
        cin >> v;
        s.insert(v);
        if (s.size() >= k) {
            cout << *s.find_by_order(k-1) << endl;
        }
    }
}

// ref: https://atcoder.jp/contests/abc234/editorial/3238
// 多重でない集合においてk番目の値を返すことやk未満の数が何個あるかを知ることができる