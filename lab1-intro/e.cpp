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
    string S;
    int cols[10] = {3,2,4,1,3,5,0,2,4,6};
    int count_cols[7] = {1,1,2,2,2,1,1};
    cin >> S;
    if (S[0] == '1')
    {
        count_cols[cols[1-1]]--;
        cout << "No"<<endl;
    }
    else
    {
        for (int i = 0; i < 10; i++) {
            if (S[i]=='0'){
                count_cols[cols[i]]--;
            }
        }    
        bool x = false, y = false;
        string isSplit = "No";
        for (int i = 0; i < 7; i++) {
            if (count_cols[i])
            {
                x = true;
                if (x && y){
                    isSplit = "Yes";
                    break;
                }
            }
            else if (x){
                y = true;
            }
        }
        cout << isSplit<<endl;
    }

    return 0;
}
