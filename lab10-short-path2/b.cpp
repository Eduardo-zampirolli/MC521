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

	int n, m, k;
	cin >> n >> m;

    vector<vii>  neighbors(n);
	for (int i = 0; i < m; i++) {
		int a, b;
        ll c;
		cin >> a >> b >> c;
		neighbors[a - 1].pb({b - 1, c});
        neighbors[b - 1].pb({a - 1, c});
	}

	vector<pair<long long, int>> dist(n, {INF, -1});

	// Dijkstra's algorithm
	using T = pair<ll, int>;
	priority_queue<T, vector<T>, greater<T>> pq;

	int start = 0;
	dist[start].first = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		const auto [cdist, node] = pq.top();
		pq.pop();
		if (cdist > dist[node].first) { continue; }
		for (const pair<int, int> &i : neighbors[node]) {
			if (cdist + i.second < dist[i.first].first) {
                dist[i.first].first = cdist + i.second;
                dist[i.first].second = node;
				pq.push({dist[i.first].first, i.first});
			}
		}
	}
    if (dist[n - 1].first == INF) {
        cout << -1 << "\n";
        return 0;
    }
    vector<int> path;
    for (int curr = n - 1; curr != -1; curr = dist[curr].second) path.pb(curr + 1);
    
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) cout << path[i] <<  " ";
    
    cout << "\n";

    return 0;
}
