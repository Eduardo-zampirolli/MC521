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
 
#define MAX 10e12

int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> permu;
    int num = 0;
    do {
        permu.pb(s);
        num++;
    }while(next_permutation(s.begin(), s.end()));
    cout << num << endl;
    for (int i = 0; i < num; i++){cout << permu[i] << endl;}
    return 0;
}
