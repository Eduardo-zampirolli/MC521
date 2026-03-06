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
    vector<int> dy = {-1,-1,-1, 0}; //d1, h, d2, v
    vector<int> dx = {-1,0,1, -1}; //d1, h, d2, v

    while (cin >> n && n){
        vector<string> D(n);
        for (int i = 0; i < n; i++) {
            cin >> D[i];
        }
        int maxAll = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][j]=='1'){
                    for (int d = 0; d < 4; d++) {
                        int curr = 0;
                        for (int k = 0; k < 255; k++) {
                            int n_i = i+(dx[d]*k);
                            int n_j = j+(dy[d]*k);
                            if (n_i <0 || n_j < 0 || n_i >=n|| n_j >=n){
                                break;
                            }
                            if (D[n_i][n_j]=='1'){
                                curr++;
                            } else{
                                break;
                            }
                        }
                        maxAll = max(maxAll, curr);
                        
                    }
                }
            }
            
        }
        cout << maxAll << endl;
    }
    return 0;
}
 
