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
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);    cin.tie(NULL);
    while(true){
        int n, m;
        cin >> n >> m;

        if (!n && !m) return 0;

        vector<vector<tuple<int, ll, ll>>>  neighbors(n);
        for (int i = 0; i < m; i++) {
            ll u, v;
            int d, c;
            cin >> u >> v >> d >> c;
            neighbors[u-1].pb({v-1, d, c});
            neighbors[v-1].pb({u-1, d, c});
        }

        vector<ll> dist(n,INF);

        // Dijkstra's algorithm
        using T = pair<ll, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        int start = 0;
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            const auto [cdist, node] = pq.top();
            pq.pop();
            if (cdist > dist[node]) { continue; }

            for (const auto &i : neighbors[node]) {
                auto [b, d, c] = i;
                if (dist[b] > cdist + d) {
                    dist[b] = cdist + d;

                    pq.push({cdist + d, b});
                }
            }
        }
        ll total = 0;
        for (int i = 2; i <= n; i++) {
            ll min_cost = INF;
            
            for (const auto &i : neighbors[i]) {
                auto [b, d, c] = i; 
                if (dist[b] + d == dist[i]) {
                    min_cost = min(min_cost, c);
                }
            }
            total += min_cost;
        }
        cout << total << "\n";
    }
    return 0;
}
