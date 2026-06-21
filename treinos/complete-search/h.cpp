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
    int n, a, b;
    cin >> n >> a >> b;
    int x = 0;
    for (int i = 1; i < n; i++){
        int pa = i, pb = n-i;
        if (pa > a || pb > b) continue;
        int xa = a / pa;
        int xb = b / pb;
        int aux = min(xa, xb);
        x = max(x, aux);
    }
    cout << x << "\n";
    return 0;
}
