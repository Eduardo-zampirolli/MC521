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

struct Inter {
    double start, end;
    bool operator<(const Inter& other) const {
        return start < other.start;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector<double> X(n);
    for(int i = 0; i < n; i++) cin >> X[i];
    vector<Inter> forb;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            double d = abs(X[i] - X[j]);
            forb.pb({d,1e12});

            for (int k = 1; ; k++){
                double v_max = d / (k*l - 1.0);
                double v_min = d / (k*l + 1.0);
                if (v_max < 0.1) break;
                forb.pb({v_min, v_max});
            }
        }
    }
    sort(forb.begin(), forb.end());
    vector<Inter> merged;
    if (!forb.empty()) {
        merged.pb(forb[0]);
        for (int i = 1; i < forb.size(); i++) {
            if (forb[i].start <= merged.back().end + 1e-11)
                merged.back().end = max(merged.back().end, forb[i].end);
            else 
                merged.pb(forb[i]);
        }
    }
    double max_v = 10.0;
    for (int i= merged.size()-1; i >= 0; i--){
        if (max_v > merged[i].end + 1e-11) break;
        if (max_v >= merged[i].start) max_v = merged[i].start;
    }
    if (max_v < 0.1) cout << "no fika\n";
    else cout <<fixed<< setprecision(10) << max_v << "\n";

    return 0;
}
