#include <vector>
#include <iostream>

using namespace std;

template<class T> void compression(vector<T>& V) {
    vector<T> X = V;
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    vector<T> res(V.size());
    for (int i = 0; i < V.size(); ++i) {
        res[i] = lower_bound(X.begin(), X.end(), V[i]) - X.begin();
    }
    V = res;
}
