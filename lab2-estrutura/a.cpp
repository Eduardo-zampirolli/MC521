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
 
#define MAX 10e5

int main(){
    int n, c;
    cin >> n >> c;
    vector<int> v(n, 0);
    int min = 1;
    int minIdx = -1;
    while (c--){
        int x;
        cin >> x;
        for (int i = 0; i < n; i++) {
            if (v[i] < min){
                min = v[i];
                minIdx = i;
            } 
        } 
        cout << minIdx+1 << " \n"[c==0];
        v[minIdx]+=x;
        min = MAX;
    }
    return 0;
   }
