/**
*    Leetcode Problem: Find the Duplicate Number   Difficulty:Hard
*    Solution: 12ms with O(1) space
*/

/**
*    Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive)
*    Prove that at least one duplicate number must exist.
*    Assume that there is only one duplicate number, find the duplicate one. 
*
*    Note:
*    1.You must not modify the array (assume the array is read only).
*    2.You must use only constant, O(1) extra space.
*    3.Your runtime complexity should be less than O(n2).
*    4.There is only one duplicate number in the array, but it could be repeated more than once.
*/

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = nums[nums[0]];
		int fast = nums[slow];
		while (fast != slow) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		int temp = nums[0];
		while (temp != slow) {
			temp = nums[temp];
			slow = nums[slow];
		}
		return temp;
	}
};