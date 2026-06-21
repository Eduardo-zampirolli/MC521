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
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = sz(s);    
    vector<bool> visit(1000000, false);
    for (int i = 0; i < n; i++){
        int num = 0;
        for (int j = 0; j < 6 && i + j < n; j++){
            num = 10*num + (s[i+j]-'0');
            if (num < 1000000) visit[num] = true;
        }
    }
    int i = 0;
    while (true){
        if (!visit[i]){
            cout << i << "\n";
            return 0;
        }
        i++;
    }
    return 0;
}
