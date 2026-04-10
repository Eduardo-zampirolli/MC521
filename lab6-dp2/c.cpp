#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
#define MAX 10e5
const double EPS = 1e-7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tam;
    cin >> tam;
    cin.ignore();
    string A;
    while (tam--){
        getline(cin, A);
        int n = A.size();
        int last[3] = {-1,-1,-1};
        int min_sub = n+1;
        int min_local;
        for (int i = 0; i < n; i++) {
            int value = A[i] - '1';
            if (value < 0 || value > 2)
                continue;
            int first = min(last[(value + 1)%3], last[(value + 2)%3]);
            if (first != -1){
                min_local = i - first;
                min_sub = min(min_sub, min_local);
            }
            last[value] = i;
        }
        if (min_sub == n+1)
            cout << 0 << endl;
        else
            cout << min_sub+1 << endl;
    }
    return 0;
}

