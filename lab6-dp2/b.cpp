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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin>>a[i]; 
        for (int i = 0; i < n; i++) cin>>b[i];
        for (int i = 0; i < n; i++) cin>>c[i];

        int a1=-1, a2=-1, a3=-1;
        for (int i = 0; i < n; i++) {
            int num = a[i];
            int va1 = (a1 == -1 ? -1 : a[a1]);
            int va2 = (a2 == -1 ? -1 : a[a2]);
            int va3 = (a3 == -1 ? -1 : a[a3]);
            if (num >= va1){
                a3 = a2;
                a2 = a1;
                a1 = i;
            } else if (num >= va2){
                a3 = a2;
                a2 = i;
            } else if (num >= va3) 
                a3 = i;
        }
        int b1=-1, b2=-1, b3=-1;           
        for (int i = 0; i < n; i++) {
            int num = b[i];
            int vb1 = (b1 == -1 ? -1 : b[b1]);
            int vb2 = (b2 == -1 ? -1 : b[b2]);
            int vb3 = (b3 == -1 ? -1 : b[b3]);
            if (num >= vb1){
                b3 = b2;
                b2 = b1;
                b1 = i;
            }else if (num >= vb2){
                b3 = b2;
                b2 = i;
            } else if (num >= vb3) 
                b3 = i;
        }
        int c1=-1, c2=-1, c3=-1;
        for (int i = 0; i < n; i++) {
            int num = c[i];
            int vc1 = (c1 == -1 ? -1 : c[c1]);
            int vc2 = (c2 == -1 ? -1 : c[c2]);
            int vc3 = (c3 == -1 ? -1 : c[c3]);
            if (num >= vc1){
                c3 = c2;
                c2 = c1;
                c1 = i;
            }else if (num >= vc2){
                c3 = c2;
                c2 = i;
            } else if (num >= vc3) 
                c3 = i;
        }
        vector<int> va = {a1, a2, a3};
        vector<int> vb = {b1, b2, b3};
        vector<int> vc = {c1, c2, c3};
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int ai = va[i], bi = vb[j], ci = vc[k];
                    if (ai >= 0 && bi >= 0 && ci >= 0 && ai != bi && ai != ci && bi != ci) {
                        ans = max(ans, a[ai] + b[bi] + c[ci]);
                    }
                }
            }
        }
        cout << ans << endl;

    } 
    return 0;
}
