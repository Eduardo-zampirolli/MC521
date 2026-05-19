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
 
#define MAX 10e12

int common(const vector<string>& animal1, const vector<string>& animal2) {
    int com = 0;
    for (int i = 0; i < animal1.size(); i++) {
        for (int j = 0; j < animal2.size(); j++) {
            if (animal1[i] == animal2[j]){
                com++;
                break;
            }
        }
    }
    return com;
}
int main(){
    ifstream fin("guess.in");
    ofstream fout ("guess.out");
    int n;
    fin >> n;
    vector<vector<string>> animals(n);
    for (int i = 0; i < n; i++){
        string name;
        int k;
        fin >> name >> k;
        for (int j = 0; j < k; j++) {
            string atr;
            fin >> atr;
            animals[i].pb(atr);
            
        }
    }
    int max_yes = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int com = common(animals[i], animals[j]);
            max_yes = max(max_yes, com);
        }
        
    }
    fout << max_yes+1 << endl;

    fin.close();
    fout.close();
    return 0;
}
