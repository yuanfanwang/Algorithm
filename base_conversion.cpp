#include <bits/stdc++.h>
using namespace std;

using ll = long long;


map<char, int> to_num;
map<int, char> to_char;

void init_base() {
    for (int i = 0; i < 10; ++i) to_num['0'+i] = i;
    for (int i = 0; i < 26; ++i) to_num['A'+i] = 10+i;
    for (int i = 0; i < 10; ++i) to_char[i] = '0'+i;
    for (int i = 0; i < 26; ++i) to_char[10+i] = 'A'+i;
}

ll to_base_10(string x, ll m) { // x is base m
    ll res = 0;
    ll m_exp = 1;
    while(x.size()) {
        res += m_exp*(to_num[x.back()]);
        x.pop_back();
        m_exp *= m;
    }
    return res;
}

string to_base_m(ll x, ll base) { // x is base 10
    string res = (x ? "" : "0");
    while(x) {
        res.push_back(to_char[x%base]);
        x /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

string base_conversion(string x, ll from, ll to) {
    ll dec = to_base_10(x, from);
    string res = to_base_m(dec, to);
    return res;
}


// 典型90 067
int main() {
    string N;
    ll K;
    cin >> N >> K;

    init_base();

    while(K--) {
        N = base_conversion(N, 16, 8);
        // for (auto& e : N) if (e == '8') e = '5';
    }

    cout << N << endl;
}