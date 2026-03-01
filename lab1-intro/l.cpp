#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define mod(a) (a+MOD)%MOD
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
#define MOD 998244353

// RES -> sum(n:0->N){P_{n}^{PROD(letters[i]!)}MOD(MAX)}
// Tem que fazer com DP, tentar fazer depois que aprender

ll fac(int n){
    ll res = 1;
    for (int i = 1; i <= n; ++i) {
        res = (res*i)%MOD;
    }
    return res;
}

int comb(int n, int m, vector<int> rep){
    int res = fac(n);
    for (int i = 0; i < 26; i++) {
        res /= fac(rep[i]);       
    }
    return res;
}

int main(){
    string S;
    vector<int> letters(26, 0);
    cin >> S;
    int len = S.size();
    for(int i = 0; i < len; i++)
    {
       letters(S[i]-'a')++;
    }
    int res = 0;
    for (int i = 0; i < len; i++) {
        res += comb(i, rep);
    }
    return 0;
}
