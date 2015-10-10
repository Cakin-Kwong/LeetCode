/**
*    Leetcode Problem: Single Number II   Difficulty:Medium
*    Solution: 16ms with O(1) space
*/

/**
*    Given an array of integers, every element appears three times except for one. Find that single one. 
*
*    Note:
*    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		const int INTBIT_SIZE = sizeof(int) * 8;
		int bit_count[INTBIT_SIZE];
		for (int i = 0; i < INTBIT_SIZE; i++) {
			bit_count[i] = 0;
		}
		for (int i = 0; i < nums.size(); i++) {
			int bit_pos = 0;
			int temp = nums[i];
			while (bit_pos < INTBIT_SIZE) {
				bit_count[bit_pos++] += temp & 1;
				temp = temp >> 1;
			}
		}
		int single = 0;
		for (int i = INTBIT_SIZE - 1; i >= 0; i--) {
			single = (single << 1) + bit_count[i] % 3;
		}
		return single;
	}
};
