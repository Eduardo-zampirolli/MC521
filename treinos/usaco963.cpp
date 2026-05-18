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
    ifstream fin("gymnastics.in");
    ofstream fout ("gymnastics.out");
    int k, n;
    fin >> k >> n;
    vector<vi> ranks(k, vi(n)), pairs(n, vi(n, 0));
    for (int i = 0; i < k; i++) for(int j = 0; j < n; j++) fin >> ranks[i][j];
    
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n-1; j++){
            for (int l = j+1; l < n; l++) {
                int a, b;
                a = ranks[i][j]-1;
                b = ranks[i][l]-1;
                pairs[a][b]++;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pairs[i][j]==k) count ++;
        }
    }
    fout << count << endl;

    fin.close();
    fout.close();
    return 0;
}
