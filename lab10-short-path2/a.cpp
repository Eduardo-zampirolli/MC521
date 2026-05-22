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
    int t = 1;
    while (true){
        int n;
        cin >> n;
        if (!n) break;

        vector<vector<double>> dist(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++) dist[i][i] = 1.0;

        map<string, int> Curr;
        for (int i = 0; i < n; i++){
            string aux; 
            cin >> aux;
            Curr[aux] = i;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++){
            string a, b;
            double w;
            cin >> a >> w >> b;
            dist[Curr[a]][Curr[b]] = w;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = max(dist[i][j], dist[i][k]*dist[k][j]);


        bool poss = false; 
        for (int i = 0; i < n; i++)
            if (dist[i][i] > 1.0){
                poss = true;
                break;
            }
        if (poss) cout << "Case " << t++ << ": Yes\n";
        else cout << "Case " << t++ << ": No\n";

    }
    
    return 0;
}
