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
const ll INF = 1e7;

int main() {
    ios_base::sync_with_stdio(false);    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++){
        int n, r;
        cin >> n;
        vector<vector<ll>> dist(n, vector<ll>(n, INF));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> dist[i][j];

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);



        cin >> r;
        ll total = 0;
        for (int i = 0; i < r; i++){
            int s, d;
            cin >> s >> d;
            s--; d--;
            total += dist[s][d];
        }

        
    
        cout << "Case #" << t << ": " << total << "\n";
    }
        return 0;
}
