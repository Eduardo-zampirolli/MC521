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
    int N, x, y, z;
    cin >> N >> x >> y >> z;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
       cin >> A[i]; 
    }
    for (int i = 0; i < N; i++) {
       cin >> B[i]; 
       C[i] = A[i] + B[i];
    }

    vector<bool> approved(N, false);
    int aux;
    for (int i = 0; i < x; i++) {
        int maxMath = -1;
        for (int j = 0; j < N; j++) {
            if (A[j] > maxMath && !approved[j])
            {
                maxMath = A[j];
                aux = j;
            }    
        }
        approved[aux] = true;
        
    }
    for (int i = 0; i < y; i++) {
        int maxEng = -1;
        for (int j = 0; j < N; j++) {
            if (B[j] > maxEng && !approved[j])
            {
                maxEng = B[j];
                aux = j;
            }    
        }
        approved[aux] = true;
    }
    for (int i = 0; i < z; i++) {
        int maxAll = -1;
        for (int j = 0; j < N; j++) {
            if (C[j] > maxAll && !approved[j])
            {
                maxAll = C[j];
                aux = j;
            }    
        }
        approved[aux] = true;
    }
    for (int i = 1; i <= N; i++) {
        if (approved[i-1])
            cout << i << endl;
    }

    return 0;
}
