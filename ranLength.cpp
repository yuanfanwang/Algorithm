#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> ranLength(string S) {

    int N = S.size();
    S.push_back('!'); // non-exsistant character

    vector<pair<char, int>> res;
    int l = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] != S[i+1]) {
            res.push_back({S[i], i+1-l});
            l = i+1;
        }
    }
    return res;
}

int main() {
    
}