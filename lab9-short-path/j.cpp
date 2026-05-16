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

	int n, m;
	cin >> n >> m;

    vector<vector<pair<int, ll>>>  neighbors(n);
	for (int i = 0; i < m; i++) {
		int a, b;
        ll c;
		cin >> a >> b >> c;
		neighbors[a-1].pb({b-1, c});
	}

	vector<vector<ll>> dist(n,vector<ll>(2, INF));

	// Dijkstra's algorithm
	using T = tuple<ll, int, bool>;
	priority_queue<T, vector<T>, greater<T>> pq;

	int start = 0;
	dist[start][0] = 0;
	pq.push({0, start, false});

	while (!pq.empty()) {
		const auto [cdist, node, used] = pq.top();
		pq.pop();
		if (cdist > dist[node][used]) { continue; }

		for (const auto &i : neighbors[node]) {
			if (dist[i.first][used] > cdist + i.second) {
                dist[i.first][used] = cdist + i.second;
				pq.push({cdist + i.second, i.first, used});
			} if (!used && dist[i.first][1] > cdist + i.second/2){
                dist[i.first][1] = cdist + i.second/2;
                pq.push({dist[i.first][1], i.first, 1});
            }
                
		}
	}

    
    cout << dist[n-1][1] << endl;

    return 0;
}
