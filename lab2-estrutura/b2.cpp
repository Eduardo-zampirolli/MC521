#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> dy = {-1, -1, -1, 0}; 
    vector<int> dx = {-1, 0, 1, -1};  

    while (cin >> n && n != 0) {
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i]; 
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4, 0)));
        int max_consecutive = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if (grid[i][j] == '1') {
                    for (int d = 0; d < 4; d++) {
                        int prev_i = i + dy[d];
                        int prev_j = j + dx[d];

                        if (prev_i >= 0 && prev_i < n && prev_j >= 0 && prev_j < n) {
                            dp[i][j][d] = dp[prev_i][prev_j][d] + 1;
                        } else {
                            dp[i][j][d] = 1; 
                        }
                        
                        max_consecutive = max(max_consecutive, dp[i][j][d]);
                    }
                }
                
            }
        }
        cout << max_consecutive << "\n";
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    // Directions (looking forward): 
    // Right (0, 1), Down (1, 0), Down-Right (1, 1), Down-Left (1, -1)
    vector<int> dy = {0, 1, 1, 1}; 
    vector<int> dx = {1, 0, 1, -1}; 

    // Read until n is 0
    while (cin >> n && n != 0) {
        // Using vector of strings to easily read "00011" formatted inputs
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i]; 
        }

        int max_consecutive = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                // If we find a 1, we start exploring outward
                if (grid[i][j] == '1') {
                    
                    for (int d = 0; d < 4; d++) {
                        int current_streak = 0;
                        
                        // The k loop sends a scout further down the direction 'd'
                        for (int k = 0; k < 255; k++) {
                            // Calculate the scout's coordinates
                            int next_i = i + (dy[d] * k);
                            int next_j = j + (dx[d] * k);
                            
                            // 1. Check if the scout stepped out of the grid bounds
                            if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n) {
                                break; 
                            }
                            
                            // 2. Check if the scout found a '1' or a '0'
                            if (grid[next_i][next_j] == '1') {
                                current_streak++; // Streak continues!
                            } else {
                                break; // Found a '0', the streak is broken
                            }
                        }
                        
                        // After the scout finishes, see if this direction had the biggest streak
                        max_consecutive = max(max_consecutive, current_streak);
                    }
                }
                
            }
        }
        cout << max_consecutive << "\n";
    }
    return 0;
}
