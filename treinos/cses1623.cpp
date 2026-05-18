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
#define mod(a) (a+MOD)%MOD
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
#define MAX 10e10

int main(){
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    ll ans = MAX;
    for (int mask = 0; mask < (1<<n); mask++){
        ll s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)) s1 += p[i];
            else s2 += p[i];
        }
        ans = min(ans, abs(s1-s2));
    }


    cout << ans << endl;
    return 0;
}
