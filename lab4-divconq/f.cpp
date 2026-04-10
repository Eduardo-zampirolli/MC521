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
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].fi >> v[i].se;
    }
    sort(v.begin(), v.end());
    int l = 0;
    ll curr = v[0].second, maior = curr;
    for (int r = 1; r < n; r++) {
        curr +=v[r].se;
        while (v[r].fi - v[l].fi >= d){
            curr-=v[l].se;
            l++;
        } 
        maior = max(curr, maior);
    }
    cout << maior << endl;
    return 0;
}
