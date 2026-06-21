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
    int n;
    cin >> n;
    vector<ll> A(n), Last(n);
    int ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] == 1) ones++;
    }    
    if (ones > 0){
        cout << n-ones << "\n";
        return 0;
    }
    int min_len = 1e9;
    for (int i = 0; i < n; i++) {
        int curr = A[i];
        for (int j = i + 1; j < n; j++) {
            curr = gcd(curr, A[j]);
            
            if (curr == 1) {
                int curr_len = j - i + 1;
                min_len = min(min_len, curr_len);
                break;
            }
        }
    }
    if (min_len == 1e9) cout << -1 << "\n";
    else cout << (min_len - 1) + (n-1) << "\n";

    return 0;
}
