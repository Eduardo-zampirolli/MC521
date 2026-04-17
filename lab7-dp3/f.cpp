#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
#define MAX 10e9
#define MIN -10e9
#define N_MAX 1000
#define Q_MAX 2*10e5
const double EPS = 1e-7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    
    vector<vector<char>> map(n+1, vector<char>(n+1));
    vector<vector<int>> num_trees(n+1, vector<int>(n+1, 0));
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> map[i][j]; 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            num_trees[i][j] = (int)(map[i][j] == '*') + num_trees[i-1][j] + num_trees[i][j-1] - num_trees[i-1][j-1];
        }
    }
    
    while (q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        
        cout << num_trees[y2][x2] - num_trees[y1-1][x2] - num_trees[y2][x1-1] + num_trees[y1-1][x1-1] << endl;
    }
    return 0;
}
