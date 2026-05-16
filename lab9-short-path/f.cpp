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
    ios_base::sync_with_stdio(false);    
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<pair<int, ll>>> neighbors(n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            string s;
            cin >> s;
            if (s != "x"){
                ll a = stoll(s);
                neighbors[i].pb({j, a});
                neighbors[j].pb({i, a});
            }
        }
    }

    vector<ll> dist(n, INF);

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
            if (dist[i.first] > cdist + i.second) {
                dist[i.first] = cdist + i.second;
                pq.push({cdist + i.second, i.first});
            }
        }
    }

    ll max_time = 0;
    for (int i = 0; i < n; i++) {
        max_time = max(max_time, dist[i]);
    }
    
    cout << max_time << "\n";

    return 0;
}
