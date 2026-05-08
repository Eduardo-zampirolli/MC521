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
#define UNVISITED 0
#define VISITED 1
#define MOD 1000000007
const double EPS = 1e-7;
vector<vector<int>> adj;
vector<int> dfs_num, topoSort;
bool dfs2(int u) {
    dfs_num[u] = 2;
    for (int v : adj[u]) {
        if (dfs_num[v] == 0) {
            if (!dfs2(v)) return false;
        } else if (dfs_num[v] == 2) {
            return false;
        }
    }
    dfs_num[u] = 1;
    topoSort.pb(u);
    return true;
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
            if(!dfs2(i)){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
    reverse(topoSort.begin(), topoSort.end());
    for (int i = 0; i < (int)topoSort.size(); i++)
        printf("%d ", topoSort[i]);
    printf("\n");
    return 0;
}

