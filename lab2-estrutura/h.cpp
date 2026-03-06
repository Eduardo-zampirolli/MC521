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
 
#define MAX 10e12

int main(){
    int n ,x;
    while (true){
        cin >> n >> x;
        if (n==0 && x==0)
            break;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                for (int k = j+1; k <= n; k++) {
                   if (i + j + k == x) {
                        res++; 
                   } 
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
   
