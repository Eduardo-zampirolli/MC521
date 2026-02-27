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
    string A,B;
    cin >> A >> B;
    int N = A.size();
    map<char, int> dic;
    for (int i = 0; i < N; i++) {
        if (!dic.contains(A[i])) 
        {
            dic[A[i]] = 1;
        } else
        {
            dic[A[i]]++;
        }
    }
    int ast = 0;
    for (int i = 0; i < N; i++)
    {
        if(B[i]=='*')
        {
            ast++;
        }else
        {
            dic[B[i]]--;
        }
    }
    int diff = 0;
    for (const auto& [key, value] : dic){
        diff += abs(value);
    }
    if (diff - ast == 0)
    {
        cout << 'A' << endl;
    }else
    {
        cout << 'N' << endl;
    }
    return 0;
}
