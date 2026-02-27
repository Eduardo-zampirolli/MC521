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
    int n;
    cin >> n;
    int A=100, B=100, d_a, d_b;
    while (n--)
    {
        cin >> d_a >> d_b; 
        if (d_a > d_b)
        {
            B-=d_a;
        }else if (d_a != d_b)
        {
            A-=d_b;
        }
    }
    cout << A << endl << B << endl;
    
    return 0;
}
