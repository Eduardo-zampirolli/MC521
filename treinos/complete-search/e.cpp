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
 
#define MAX 10e9
#define MAX_INT 2147483647
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int ans=0;
    for (int a = 1; a <= n; a++){
        for (int b = a; b <= n; b++){
            int c = a ^ b;
            if (c>=b && c <= n && a+b>c && a+c>b && b+c>a) ans++;
        }
    }
    cout << ans <<"\n";
    return 0;
}
