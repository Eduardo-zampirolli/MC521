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
 
#define MAX 2*10e5
#define MIN -10e9
const double EPS = 1e-7;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> X(n), dp(n+1);
    for (int i = 0; i < n; i++) cin >> X[i];
    dp[1] = X[0];
    ll maxMRS = X[0];
    for (int i = 1; i < n; i++) {
        dp[i+1]= max(X[i], dp[i]+X[i]);
        maxMRS = max(maxMRS, dp[i+1]);
    }
    cout << maxMRS << endl;
    return 0;
}
