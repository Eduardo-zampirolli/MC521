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
//UPPER (65-90) LOWER (97-122) 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string S, T;
    bool isUp;
    cin>>S>>T;
    int lenS = S.size(), lenT = T.size();
    vector<bool> inT(128, false);
    for (int i = 0; i < lenT; i++) {
        inT[T[i]]=true;
    }
    bool poss = true;
    for (int i = 1;poss && i < lenS; i++) {
        if (S[i] <= 90){
            if (!inT[S[i-1]-'A']) poss= false;
        }
    }
    if (poss)
        cout << "Yes" <<endl;
    else
        cout << "No" << endl;
    return 0;
}
