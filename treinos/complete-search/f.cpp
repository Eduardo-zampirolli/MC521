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

bool isGood(ll num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum == 10;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin >> k;
    int quant = 1;
    ll curr = 19;
    while (quant < k){
        curr+=9; 
        if (isGood(curr)) {
            quant++;
        }
    }
    cout << curr <<"\n";
    return 0;
}
