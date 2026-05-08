

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Use a very small number for initialization to handle long paths correctly
const ll INF = 1e15;

vector<vector<int>> adj;
vector<int> dfs_num, topoSort, p;

void dfs2(int u) {
    dfs_num[u] = 1;
    for (int v : adj[u]) {
        if (dfs_num[v] == 0) dfs2(v);
    }
    topoSort.pb(u);
}

void printPath(int u, int s) {
    if (u == s) {
        cout << s << " ";
        return;
    }
    printPath(p[u], s);
    cout << u << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    adj.assign(n + 1, vector<int>());
    dfs_num.assign(n + 1, 0);
    p.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    // Topo sort from node 1 specifically to find paths starting there
    for (int i = 1; i <= n; i++) {
        if (dfs_num[i] == 0) dfs2(i);
    }
    reverse(topoSort.begin(), topoSort.end());

    vector<ll> dist(n + 1, -INF);
    dist[1] = 1; // Starting node distance is 1 (counting nodes in path)

    for (int u : topoSort) {
        if (dist[u] != -INF) { // Only relax edges from reachable nodes
            for (int v : adj[u]) {
                if (dist[v] < dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    p[v] = u;
                }
            }
        }
    }

    if (dist[n] < 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dist[n] << endl;
        printPath(n, 1); // Trace back from n to 1
        cout << endl;
    }

    return 0;
}
