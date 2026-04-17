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
const double EPS = 1e-7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    int i = n;
    int j = m;
    string res = "";
    while (i > 0 && j > 0){
        if (s[i-1] == t[j-1]){
            res.pb(s[i-1]);
            i--;
            j--;
        } 
        else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    int l = res.size();
    for (int i = l-1; i >=0; i--)
        cout << res[i];
    cout << endl;

    return 0;
}
