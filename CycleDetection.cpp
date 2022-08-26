#include <iostream>
#include <vector>
#include <iomanip>
#include <complex>
#include <cmath>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <list>
 
using namespace std;


// BFS
int main() {
    int N, E;
    cin >> N >> E;
    vector<int> ans;
    vector<int> ind(N);
    vector<vector<int>> G(N);
    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    for (int i = 0; i < N; ++i) {
        for (auto e : G[i]) {
            ind[e]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < N; ++i) {
        if (ind[i] == 0) {
            que.push(i);
        }
    }                                       
    while(!que.empty()) {
        int now = que.front();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e]--;
            if (ind[e]==0) {
                que.push(e);
            }
        }
    }
    if (ans.size() == N) cout << 0 << endl;
    else cout << 1 << endl;
}





// DFS

vector<bool> seen, finished;
bool ans = 0;
void dfs(vector<vector<int>>& G, int v) {
    seen[v] = true;
    for (auto nv : G[v]) {
        if (finished[nv]) continue;
        if (seen[nv] && !finished[nv]) {
            // サイクル検出
            ans = 1;
            return;
        }
        dfs(G, nv);
    }
    finished[v] = true;

}

int main() {
    int N, E;
    cin >> N >> E;
    
    vector<vector<int>> G(N);
    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    seen.assign(N, false);
    finished.assign(N, false);

    for (int i = 0; i < N; ++i) {
        dfs(G, i);
    }

    cout << ans << endl;
}

// 無向グラフの閉路検出
// 有向グラフと違って、[未捜査] -> [捜査済み] ということがない
// つまり[捜査済み] -> [未捜査] というパターンしかないことから、
// finished はいらず、簡単になる

vector<bool> seen;
bool ans = true;

void dfs(Graph& G, int v, int p) {
    seen[v] = true;
    for (auto nv : G[v]) {
        if (nv == p) continue;
        if (seen[nv]) {
            ans = false;
            break;
        }
        dfs(G, nv, v);
    }
}