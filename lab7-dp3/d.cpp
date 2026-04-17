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

ll dp[N_MAX][N_MAX];
bool vis[N_MAX][N_MAX];

ll res(int i, int j, const vector<ll>& A){
    if (i==j)
        return A[i];
    if (vis[i][j])
        return dp[i][j];
    ll left = A[i] - res(i+1, j, A);
    ll right = A[j] - res(i, j-1, A);
    vis[i][j] = true;
    dp[i][j] = max(left, right);
    return dp[i][j];
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> A(n,0);
    for (int i = 0; i < n; i++) cin >> A[i]; 
    cout << res(0, n-1, A) << endl;
    return 0;
}
