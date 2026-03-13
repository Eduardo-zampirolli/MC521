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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, num_x = 0;
    cin>>n;
    vector<char> S(n);
    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
        if (S[i] == 'x'){
            R[num_x] = i;
            num_x++;
        }
    }
    bool changed = true;
    while(changed){
        changed = false;
        for (int i = 0; i < num_x; i++) {
            int idx = R[i];
            if (idx == 0 || idx == n - 1)
                continue;
            if (S[idx] == 'x' && S[idx-1] == S[idx+1] && (S[idx-1] == 'a' || S[idx-1] == 'e' || S[idx-1] == 'i' || S[idx-1] == 'o' || S[idx-1] == 'u')){
                S[idx-1] = '.';
                S[idx] = '.';
                S[idx+1] = '.';
                changed = true;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
       cout << S[i]; 
    }
    cout << endl;
    
    return 0;
}
