#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;


#define INF 1E9
#define MAX 100

int m[MAX][MAX]; // DP table with optimum values (should be initialized with INF)
int s[MAX][MAX]; // Index table of the optimal subdivisions of the matrix chain
int b[MAX];      // Array containing matrix dimensions (should be initialized with data input)

int matrix_chain_td(int i, int j) {
    // memoization
    if (m[i][j] < INF) {
        return m[i][j];
    }
    
    // base case: single matrix costs 0 multiplications
    if (i == j) {
        return m[i][j] = 0;
    }
    
    // recurrence
    for (int k = i; k < j; ++k) {
        int q = matrix_chain_td(i, k) + matrix_chain_td(k + 1, j) + (b[i] * b[k + 1] * b[j + 1]);
        
        if (q < m[i][j]) {
            m[i][j] = q;
            s[i][j] = k;
        }
    }
    
    return m[i][j];
}

int main() {
    int n, d[2];
    cin >> n;
    cin >> d[0] >> d[1];
    b[0] = d[0];
    b[1] = d[1];
    for (int i = 2; i <= n; i++) {
        cin >> d[0] >> d[1];
        b[i] = d[1];
    }
    // 1. Initialize the DP table 'm' with INF
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            m[i][j] = INF;
        }
    }

    // 2. Call the top-down DP function (0-indexed for the matrices)
    int min_mults = matrix_chain_td(0, n - 1);

    cout << min_mults << endl;

    return 0;
}
