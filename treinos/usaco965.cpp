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

string cows_names[8] = {"Beatrice","Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<int> visited(8, 0), degree(8,0);
int gr[8][8] = {0};
ifstream fin("lineup.in");
ofstream fout ("lineup.out");

void dfs(int cow){
    visited[cow] = 1;
    fout << cows_names[cow] << endl;
    for (int i = 0; i < 8; i++){
        if (gr[cow][i] && !visited[i]){
            dfs(i);
        }
    }

}


int main(){
    int n;
    fin >> n;
    map<string, int> cows_pos = {{"Beatrice", 0},{"Belinda", 1}, {"Bella", 2}, {"Bessie", 3}, {"Betsy", 4}, {"Blue", 5}, {"Buttercup", 6}, {"Sue", 7}};
    string a, b, aux;
    for (int i = 0; i < n; i++){
        fin >> a;
        for (int j = 0; j < 4; j++) fin >> aux;
        fin >> b;
        gr[cows_pos[a]][cows_pos[b]] = 1;
        gr[cows_pos[b]][cows_pos[a]] = 1;
        degree[cows_pos[a]]++;
        degree[cows_pos[b]]++;
    }
    for (int i = 0; i < 8; i++) {
        if(!visited[i] && degree[i]<=1) dfs(i);
    }
    fin.close();
    fout.close();
    return 0;
}
