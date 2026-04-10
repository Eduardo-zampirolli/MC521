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
#define MAX 10e5
const double EPS = 1e-7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;

    string new_s;
    new_s += s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            new_s += s[i];
        }
    }
    s = new_s;
    n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (len == 1) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = 1 + dp[i+1][j];
            for (int k = i + 1; k <= j; k++) {
                if (s[i] == s[k]) {
                    int left = (k-1 >= i+1) ? dp[i+1][k-1] : 0;
                    dp[i][j] = min(dp[i][j], left + dp[k][j]);
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
