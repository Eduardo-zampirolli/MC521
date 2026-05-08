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
//#define MIN -2*10e5
#define UNVISITED -1
#define VISITED 1
#define MOD 1000000007
const double EPS = 1e-7;
const ll INF = 1e15;
vector<vector<int>> adj;
vector<int> dfs_num, topoSort, p;
void dfs2(int u) {
    dfs_num[u] = 1;
    for (int v : adj[u]) {
        if (dfs_num[v] == 0)
            dfs2(v);
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
    vector<ll> paths(n+1, -INF);
    p.assign(n+1, -1);
    paths[1] = 1;
    for (int u : topoSort) {
        if (paths[u]!=-INF){
            for (int v : adj[u]) {
                if (paths[v] < paths[u] + 1){
                    paths[v] = 1 + paths[u];
                    p[v] = u;
                }
            }
        }
    }
    if (paths[n]<0)
        cout << "IMPOSSIBLE\n";
    else{
        cout << paths[n] << endl;
        printPath(n, 1);
        cout << endl;
    }
    return 0;
}
