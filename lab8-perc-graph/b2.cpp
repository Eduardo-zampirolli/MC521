#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int MOD = 1e9+7;

vector<vector<int>> adj;
vector<int> dfs_num, topoSort;
void dfs(int u) {
    dfs_num[u] = 1;
    for (int v : adj[u]) {
        if (dfs_num[v] == 0)
            dfs(v);
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
            dfs(i);
    reverse(topoSort.begin(), topoSort.end());
    vector<ll> dp(n+1, 0);
    dp[1] = 1;
    for (int u : topoSort) {
        for (int v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
