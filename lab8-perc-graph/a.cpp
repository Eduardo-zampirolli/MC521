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

vector<vector<int>> adj;
vector<int> dfs_num, topoSort;



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vii p(n+1, UNVISITED);
        vi 
        for (int i = 0; i < n; i++) cin >> p[i];
        stack<int> s(n);
        for (int i = n-1; i >= 0 ; i--) {
            int count = 0;
            while(p[p[i].fi].se == UNVISITED){

            }
        }
    }

    return 0;
}


