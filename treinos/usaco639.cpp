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
    ifstream fin("diamond.in");
    ofstream fout ("diamond.out");
    int n, k;
    fin >> n >> k;
    vector<int> size(n), diff(n-1);
    for (int i = 0; i < n; i++) fin >> size[i];
    sort(size.begin(), size.end());
    for (int i = 1; i < n; i++) diff[i-1] = size[i] - size[i-1];
    
    int max_count = 1, count = 1, curr_k = 0;
    for (int i = 0; i < n-1; i++) {
        int j = i;
        while(j < n-1){
            curr_k += diff[j];
            if (curr_k <= k){
                count ++;
            } else{
                break;
            } 
            max_count = max(max_count, count);
            j++;
        }
        curr_k = 0;
        count = 1;
    }
    fout << max_count << endl;
    fin.close();
    fout.close();
    return 0;
}
