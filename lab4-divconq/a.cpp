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

double res(int p, int q, int r, int s, int t, int u, double x){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bisseccao(int p, int q, int r, int s, int t, int u, double a, double b){
   double med = (a+b)/2;
   double val = res(p, q, r, s, t, u, med);
   if(fabs(val)<EPS || fabs(a-b) < EPS)
       return med;
   if (val > 0)
       return bisseccao(p, q, r, s, t, u, med, b);
    return bisseccao(p, q, r, s, t, u, a, med);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int p, q, r, s, t, u;
    double x, max, min; // x é pos menor ou igual a 1
    // max p + q + r + s 
    while (cin >> p >> q >> r >> s >> t >> u){
        if (res(p, q, r, s, t, u, 0) < 0 || res(p, q, r, s, t, u, 1) > 0){
            cout << "No solution" << endl;
            continue;
        }
        double rp = bisseccao(p, q, r, s, t, u, 0.0, 1.0);
        cout << fixed << setprecision(4) << rp << endl;
    }
    return 0;
}
