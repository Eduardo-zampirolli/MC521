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
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
#define MAX 2*10e5
#define MIN -10e9
#define UNVISITED 0
#define VISITED 1
#define MOD 1000000007
const double EPS = 1e-7;
const int INF = 100000;
int main() {
    ios_base::sync_with_stdio(false);    cin.tie(NULL);

    vector<vector<int>> dist(26, vector<int>(26, INF));
    for (int i = 0; i < 26; i ++) for (int j = 0; j < 26; j++) if (i==j) dist[i][j] = 0;

    string s, t;
    cin >> s >> t;
	int n;
	cin >> n;

    if (s.size() != t.size()){
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        char a, b;
        int w;
        cin >> a >> b >> w;
        dist[a-'a'][b-'a'] = min(dist[a-'a'][b-'a'], w);
    }
    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    ll total = 0;
    string res = "";

    for (int i = 0; i < s.size(); i++){
        int min_cost = INF;
        char best_char = 'a';
        for (int c = 0; c < 26; c++){
            int curr = dist[s[i]-'a'][c] + dist[t[i] - 'a'][c];
            if (curr < min_cost){
                min_cost = curr;
                best_char = c+'a';
            }
        }
        if (min_cost >= INF) {
            cout << -1 << endl;
            return 0;
        }
        total += min_cost;
        res += best_char;
    }
    cout << total << endl << res << endl;

    return 0;
}
