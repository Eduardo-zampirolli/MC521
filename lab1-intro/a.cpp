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
    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    int c, f, g, h, i1, i2;
    int count = 0;
    for (int a = 1; a <= 30; a++) {
        for (int b = 1; b <= 30; b++) {
            for (int d = 1; d <= 30; d++) {
                for (int e = 1; e <= 30; e++) {
                    c = h1 - a - b;
                    f = h2 - d - e;
                    g = w1 - a - d;
                    h = w2 - b - e;
                    i1 = h3 - g - h;
                    i2 = w3 - c - f;
                    if (i1 == i2 && c>0 && f>0 && g>0 && h>0 && i1>0)
                        count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}
