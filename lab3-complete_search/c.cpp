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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    while(cin >> n && n){
        vector<int> S(n);
        for (int i = 0; i < n; i++) cin >> S[i];
        sort(S.begin(), S.end());
        bool found = false;
        int ans = null;
        for (int i = n-1; i >= 0 && !found; i--) {
            for (int j = 0; j < n && !found; j++) {
                if (i==j) continue;
                for (int k = 0; k < n && !found; k++) {
                    if (i==k) continue;
                    for (int l = 0; l < n && !found; l++) {
                        if (i==l) continue;
                        if (S[i]== S[j] + S[k] + S[l]){
                            ans = S[i];
                            found = true;
                        }
                    }
                }
            }
        }
        if (ans==null)
            cout << "no solution" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
