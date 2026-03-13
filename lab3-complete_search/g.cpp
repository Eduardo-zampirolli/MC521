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
    int a, b, c;
    double ans;
    cin>>a>>b>>c;
    if (a <= b*c)
        ans = double(a)/b; 
    else
        ans = c;
    
    cout << fixed << setprecision(10) <<ans<<endl;
    return 0;
}
