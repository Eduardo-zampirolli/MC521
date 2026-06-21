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

int getLucky(int a){
    int res = 0, pot = 1; 
    while(true){
       if (a==0) break; 
       int aux = a%10;
       a /= 10;
       if (aux == 4 || aux == 7) {
           res += pot*aux;
           pot *= 10;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> a >> b;

    int c = a+1;
    while(true){
        if (getLucky(c) == b) break;
        c++;
    }
    cout << c << "\n";
    return 0;
}
