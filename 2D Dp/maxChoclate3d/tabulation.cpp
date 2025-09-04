#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxChoclate(vector<vector<int>>& grid, int n, int m) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    // Base case (last row)
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Bottom-up DP
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;
                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {
                        int ans;
                        if (j1 == j2) ans = grid[i][j1];
                        else ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + dj1 < 0 || j1 + dj1 >= m) || (j2 + dj2 < 0 || j2 + dj2 >= m))
                            ans += -1e9; // invalid move
                        else
                            ans += dp[i + 1][j1 + dj1][j2 + dj2];

                        maxi = max(ans, maxi);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1]; // starting from row=0, col1=0, col2=m-1
}

int main() {
    vector<vector<int>> grid = {
        {2, 0, 0, 0, 0, 0, 2},
        {2, 1, 0, 0, 0, 4, 0},
        {2, 0, 10, 0, 1, 0, 0},
        {0, 3, 0, 6, 5, 0, 0},
        {1, 0, 3, 4, 0, 0, 6}
    };

    int n = grid.size();
    int m = grid[0].size();

    int ans = maxChoclate(grid, n, m);
    cout << "The max chocolate they both can pick is: " << ans;
    return 0;
}
