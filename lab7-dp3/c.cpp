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
#define N_MAX 3000
const double EPS = 1e-7;

double dp[N_MAX][N_MAX];
bool vis[N_MAX][N_MAX];

double res(int i, int heads, const vector<double>& P, int n){
    if (i==n){
        if(heads > n/2)
            return 1.0;
        return 0.0;
    }
    if (vis[i][heads])
        return dp[i][heads];
    double head = P[i] * res(i+1,heads+1, P, n);
    double tale = (1-P[i]) * res(i+1, heads, P, n);
    vis[i][heads] = true;
    dp[i][heads] = head + tale;
    return dp[i][heads];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<double> P(n,0);
    for (int i = 0; i < n; i++) cin >> P[i]; 
    cout << setprecision(10) << res(0, 0, P, n) << endl;
    return 0;
}

