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
#define mod(a) (a+MOD)%MOD
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
#define MAX 1e18
#define MAX_INT 2147483647

vector<pair<ll, int>> adj[1000005];
bool vis[1000005];
ll best = MAX;
int target, k;

void dfs(int u, ll curr, int edge_count){
    if (curr >= best) return;

    if (edge_count == k){
        if (u == target) best = min(best, curr);
        return;
    }
    if (u==target) return;
    for (auto &edge : adj[u]){
        ll w = edge.fi;
        int v = edge.se;
        if (!vis[v]){
            vis[v] = true;
            dfs(v, curr + w, edge_count + 1);
            vis[v] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m >> k;
    target = n;
    for (int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    if (k>5){
        cout << -1 << "\n";
        return 0;
    }
    
    vis[1] = true;
    dfs(1, 0, 0);

    if (best == MAX) cout << -1 << "\n";
    else cout << best << "\n";
    return 0;
}

