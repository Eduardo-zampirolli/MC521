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

int s(ll x){
    int soma = 0;
    while (x>0){
        soma += x%10;
        x/=10;
    }
    return soma;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;
    cin >> n;
    //x = (-s(x)+sqrt(s(x)²+4n))/2
    //x² <= 10e18 => x<=10e9 => x<=10e10 => s(x) <= 90
    ll res = -1;
    for (ll S = 0; S <= 90; S++) {
        long double delta = (long double)S*S+4.0*(long double)n;
        long double sqr = (-S + sqrtl(delta))/2.0;
        ll x = round(sqr);
        if (x>0 && s(x) == S && x*x+S*x == n)
            if(res == -1 || x < res)
                res = x;
        
    }
    cout << res << endl;
    
    return 0;
}
