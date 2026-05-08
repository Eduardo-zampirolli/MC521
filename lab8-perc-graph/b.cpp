#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
                           
#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
#define MAX 2*10e5
#define MIN -10e9
#define UNVISITED -1
#define VISITED 1
#define MOD 1000000007
const double EPS = 1e-7;

vector<vector<int>> adj;
vector<int> dfs_num, topoSort;

void dfs2(int u) {
    dfs_num[u] = 1;
    for (int v : adj[u]) {
        if (dfs_num[v] == 0)
            dfs2(v);
    }
    topoSort.pb(u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.assign(n+1, vector<int>());
    dfs_num.assign(n+1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for (int i = 1; i <= n; i++)
        if (dfs_num[i] == 0)
            dfs2(i);
    reverse(topoSort.begin(), topoSort.end());
    vector<ll> paths(n+1, 0);
    paths[1] = 1;
    for (int u : topoSort) {
        for (int v : adj[u]) {
            paths[v] = (paths[v] + paths[u]) % MOD;
        }
    }
    cout << paths[n] << endl;
    return 0;
}

