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
    int p1, p2, p3, p4, a, b;
    cin >> p1 >> p2 >> p3 >> p4 >> a >> b;

    int limit = min({p1, p2, p3, p4});
    int end = min(b, limit-1);
    if (a > end)
        cout << 0 << "\n";
    else cout << (end - a + 1) << "\n";
    return 0;
}
