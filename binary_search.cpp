#include <iostream>
using namespace std;
using ll = long long;
const int INF = 1 << 60;

bool check(int x) {
    return true;
}

int binary_search() {
    // ff..f|tt...t
    ll ng = -1, ok = INF, mid; // ok = 0 ng = -1 ok-ng = 1 
    while(ok-ng>1) {
        mid = (ng+ok) / 2;
        (check(mid) ? ok : ng) = mid;
    }
}

int binary_search() {
    // tt..t|ff...f
    ll ng = INF, ok = 0, mid;
    while(ng-ok>1) {
        mid = (ng+ok) / 2;
        (check(mid) ? ok : ng) = mid;
    }
}

