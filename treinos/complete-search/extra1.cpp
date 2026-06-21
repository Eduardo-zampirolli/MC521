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
    int quant = 0;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    for (int x = 0; x <= n / a; x++) {
        int rem_x = n - a * x;
        for (int y = 0; y <= rem_x / b; y++) {
            int rem = rem_x - b * y;
            if (rem % c == 0) {
                int z = rem / c;
                quant = max(quant, x + y + z);
            }
        }
    }
    cout << quant << endl;
    return 0;
}
