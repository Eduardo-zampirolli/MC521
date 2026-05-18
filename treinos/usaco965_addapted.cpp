#include <bits/stdc++.h>

using namespace std;

set<string> all_cows; // Automatically keeps names sorted alphabetically
map<string, vector<string>> adj; // Adjacency list (the graph)
map<string, int> degree;
map<string, bool> visited;

ofstream fout("lineup.out");

void dfs(const string& cow) {
    visited[cow] = true;
    fout << cow << "\n";
    for (const string& neighbor : adj[cow]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
            break;
        }
    }
}

int main() {
    ifstream fin("lineup.in");
    
    int n;
    fin >> n;
    
    string a, b, aux;
    for (int i = 0; i < n; i++) {
        fin >> a;
        for (int j = 0; j < 4; j++) fin >> aux;
        fin >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
        
        degree[a]++;
        degree[b]++;
        
        all_cows.insert(a);
        all_cows.insert(b);
    }
    
    for (const string& cow : all_cows) {
        if (!visited[cow] && degree[cow] <= 1) {
            dfs(cow);
        }
    }
    
    fin.close();
    fout.close();
    return 0;
}
