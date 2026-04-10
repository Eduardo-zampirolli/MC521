#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q=0, l=-1;
    char aux;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        if (aux==')'){
            if (q != 0){
                q--;
            }else
                l=i;
                
        }else{
            q++;
        }
    }
    cout << (l+1)<<'\n';
}
