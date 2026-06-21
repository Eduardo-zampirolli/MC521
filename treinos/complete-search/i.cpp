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

// fits: a<=b . likes: 2a>=b
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a1, a2, a3, am;
    cin >> a1 >> a2 >> a3 >> am;
    min_b1 = max(a1, am);
    max_b1 = 2*a1;
    min_b2 = max(a2, am);
    max_b2 = 2*a2;
    min_b3 = max(a3, am);
    max_b3 = 2*min(a3, am);
    
    if (min_b1 >= max_b1 ||
        min_b2 >= max_b2 ||
        min_b3 >= max_b3){
        cout << "-1\n";
        return 0;
    }
     

    return 0;
}
