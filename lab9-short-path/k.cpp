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
	cin >> n >> m >> k;

    vector<vector<pair<int, ll>>>  neighbors(n);
	for (int i = 0; i < m; i++) {
		int a, b;
        ll c;
		cin >> a >> b >> c;
		neighbors[a - 1].pb({b - 1, c});
	}

	vector<vector<ll>> dist(n, vector<ll>(k, INF));

	// Dijkstra's algorithm
	using T = pair<ll, int>;
	priority_queue<T, vector<T>, greater<T>> pq;

	int start = 0;
	dist[start][0] = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		const auto [cdist, node] = pq.top();
		pq.pop();
		if (cdist > dist[node][k-1]) { continue; }

		for (const auto &i : neighbors[node]) {
			if (dist[i.first][k-1] > cdist + i.second) {
                dist[i.first][k-1] = cdist + i.second;
                sort(dist[i.first].begin(), dist[i.first].end());
				pq.push({cdist + i.second, i.first});
			}
		}
	}

    for (int i = 0; i < k; i++) cout << dist[n-1][i] <<  " ";
    
    cout << "\n";

    return 0;
}
