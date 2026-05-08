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
 
#define MAX 200005
#define MIN -10e9
#define UNVISITED 0
#define VISITED 1
#define MOD 1000000007
const double EPS = 1e-7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int t;
    if (!(cin >> t)) return 0;
    while (t--){
        int n;
        cin >> n;
        vi p(n + 1);
        vi is_leaf(n + 1, 1);
        int root = -1;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            if (p[i] == i) {
                root = i;
            } else {
                is_leaf[p[i]] = 0;
            }
        }

        if (n == 1) {
            cout << "1\n1\n1\n\n";
            continue;
        }

        vi visited(n + 1, 0);
        vector<vi> paths;

        for (int i = 1; i <= n; i++) {
            if (is_leaf[i]) {
                vi curr_path;
                int curr = i;
                while (!visited[curr]) {
                    visited[curr] = 1;
                    curr_path.pb(curr);
                    if (p[curr] == curr) break;
                    curr = p[curr];
                }
                reverse(all(curr_path));
                paths.pb(curr_path);
            }
        }

        cout << paths.size() << "\n";
        for (const auto& path : paths) {
            cout << path.size() << "\n";
            for (int j = 0; j < sz(path); j++) {
                cout << path[j] << (j == sz(path) - 1 ? "" : " ");
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
