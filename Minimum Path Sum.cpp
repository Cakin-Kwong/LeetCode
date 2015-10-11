/**
*    Leetcode Problem: Minimum Path Sum   Difficulty:Medium
*/

/**
*    Given a m x n grid filled with non-negative numbers.
*    Find a path from top left to bottom right which minimizes the sum of all numbers along its path.
*
*    Note:
*    You can only move either down or right at any point in time.
*/


/**
*    Solution: 28ms with O(m * n) space
*/

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0) {
					if (j == 0) {
						dp[i][j] = grid[i][j];
					}
					else {
						dp[i][j] = dp[i][j - 1] + grid[i][j];
					}
				}
				else if (j == 0) {
					dp[i][j] = dp[i - 1][j] + grid[i][j];
				}
				else {
					dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

/**
*    Solution: 24ms with O(n) space
*/

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<int> dp(n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0) {
					if (j == 0) {
						dp[j] = grid[i][j];
					}
					else {
						dp[j] = dp[j - 1] + grid[i][j];
					}
				}
				else if (j == 0) {
					dp[j] = dp[j] + grid[i][j];
				}
				else {
					dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
				}
			}
		}
		return dp[n - 1];
	}
};