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
const int INF = 1e7;

int main() {
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    int t = 1;
    
    while (true){
        int c, s, q;
        cin >> c >> s >> q;
        if (c == 0 && s == 0 && q == 0) break;
        if (t > 1) cout << "\n"; 

        vector<vector<int>> dist(c, vector<int>(c, INF));
        for (int i = 0; i < c; i++) dist[i][i] = 0;

        for (int i = 0; i < s; i++){
            int c1, c2, d;
            cin >> c1 >> c2 >> d;
            c1--; c2--;
            dist[c1][c2] = min(dist[c1][c2], d);
            dist[c2][c1] = min(dist[c2][c1], d);
        }

        for (int k = 0; k < c; k++) 
            for (int i = 0; i < c; i++) 
                for (int j = 0; j < c; j++) 
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
                
        cout << "Case #" << t++ << "\n";
        for (int i = 0; i < q; i++){
            int c1, c2;
            cin >> c1 >> c2;
            c1--; c2--;
            
            if (dist[c1][c2] == INF) cout << "no path\n";
            else cout << dist[c1][c2] << "\n";
        }
    }
    return 0;
}
