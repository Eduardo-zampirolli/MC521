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
const int INF = 100000;
int main() {
    ios_base::sync_with_stdio(false);    cin.tie(NULL);

    vector<vector<int>> dist(94, vector<int>(94, INF));
    for (int i = 0; i < 94; i ++) dist[i][i] = 0;

    string s, t;
    cin >> s >> t;
	int m;
	cin >> m;

    for (int i = 0; i < m; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        dist[a-33][b-33] = min(dist[a-33][b-33], c);
    }
    for (int k = 0; k < 94; k++)
        for (int i = 0; i < 94; i++)
            for (int j = 0; j < 94; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    ll total = 0;

    for (int i = 0; i < s.size(); i++){
        if (dist[s[i]-33][t[i]-33] == INF){
            cout << -1 << "\n";
            return 0;
        }

        total += dist[s[i]-33][t[i]-33];
    }
    cout << total << "\n";

    return 0;
}
