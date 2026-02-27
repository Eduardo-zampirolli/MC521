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
    int N, Q, type, x, rot = 0;
    string s;
    cin >> N >> Q;
    cin >> s;
    while (Q--)
    {
        cin >> type >> x; 
        if (type == 1)
        {
            rot = (rot + x)%N; 
        } else
        {
            cout << s[(N-rot+x-1)%N] << endl;
        }
    }
    return 0;
}
