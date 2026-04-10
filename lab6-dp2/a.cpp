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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll sum = 0;
        int i = 0;
        while (i < n){
            ll curr = a[i];
            int j = i+1;
            while (j < n && (a[j]>0) == (curr > 0)){
                curr = max(curr, a[j]);
                j++;
            }
            sum += curr;
            i=j; 
        }
        cout << sum << endl;
    }
    return 0;
}
