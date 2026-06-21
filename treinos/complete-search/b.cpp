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

bool solve (int r, int c, vector<bool>& used, vector<vector<int>>& grid, const vii& dom, int val){
    if (c==4){
        if (val != grid[r][0]+grid[r][1]+grid[r][2]+grid[r][3]) return false;
        r++;
        c=0;
    }
    if (r==4){
        for (int j = 0; j < 4; j++) if (val != grid[0][j]+grid[1][j]+grid[2][j]+grid[3][j]) return false;
        if (val != grid[0][0] + grid[1][1] + grid[2][2] + grid[3][3]) return false;
        if (val != grid[0][3] + grid[1][2] + grid[2][1] + grid[3][0]) return false;
        return true;
    }
    if (grid[r][c] != -1) return solve(r, c + 1, used, grid, dom, val);
    for (int i = 0; i < 8; i++){
        if (used[i]) continue;
        used[i] = true;
        int a = dom[i].fi;
        int b = dom[i].se;
        if (c<3 && grid[r][c+1] == -1){
            grid[r][c] = a;
            grid[r][c+1]=b;
            if (solve(r, c+1, used, grid, dom, val)) return true;
            grid[r][c] = b;
            grid[r][c+1]=a;
            if (solve(r, c+1, used, grid, dom, val)) return true;
            grid[r][c] = -1;
            grid[r][c+1]= -1;
        }
        if (r<3 && grid[r+1][c] == -1){
            grid[r][c] = a;
            grid[r+1][c]=b;
            if (solve(r, c+1, used, grid, dom, val)) return true;
            grid[r][c] = b;
            grid[r+1][c]=a;
            if (solve(r, c+1, used, grid, dom, val)) return true;
            grid[r][c] = -1;
            grid[r+1][c]= -1;
        }


        used[i] = false;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    while (cin >> a >> b){
        int tot = a+b;
        vii dom(8);
        dom[0] = {a, b};
        for (int i = 1; i < 8; i++) {
            cin >> a >> b;
            tot += a + b;
            dom[i] = {a, b};
        }
        if (tot % 4 != 0) {
            cout << "N\n";
            continue;
        } 
        int val = tot / 4;    
        vector<vector<int>> grid(4, vector<int>(4, -1));
        vector<bool> used(8, false);
        if (solve(0,0,used, grid, dom, val)) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}
