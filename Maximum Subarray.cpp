/**
*    Leetcode Problem: Maximum Subarray   Difficulty:Medium
*/

/**
*    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
*
*    For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
*    the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/


/**
*    Solution: 12ms with O(n) space
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n);
		dp[0] = nums[0];
		int res = nums[0];
		for (int i = 1; i < n; i++) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			res = max(res, dp[i]);
		}
		return res;
	}
};

/**
*    Solution: 12ms with O(1) space
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int arrayEnd = nums[0];
		int res = nums[0];
		for (int i = 1; i < n; i++) {
			arrayEnd = max(arrayEnd + nums[i], nums[i]);
			res = max(res, arrayEnd);
		}
		return res;
	}
};

/**
*    Solution: 12ms with O(1) space
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int sum = nums[0];
		int minSum = min(0, sum);
		int res = nums[0];
		for (int i = 1; i < n; i++) {
			sum += nums[i];
			res = max(res, sum - minSum);
			minSum = min(minSum, sum);
		}
		return res;
	}
};