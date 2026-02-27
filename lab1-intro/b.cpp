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
    int a, b;
    cin >> a >> b;
    if (a>b)
    {
        cout << 2*a-1 << endl;
    } else if (b>a)
    {    
        cout << 2*b-1 << endl;
    } else
        cout << a+b << endl;
    return 0;
}
