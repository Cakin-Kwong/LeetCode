/**
*    Leetcode Problem: Linked List Cycle   Difficulty:Medium
*    Solution: 12ms with O(1) space
*/

/**
*    Given a linked list, determine if it has a cycle in it.
*
*    Follow up :
*    Can you solve it without using extra space ?
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return false;
		}
		ListNode *slow = head->next;
		ListNode *fast = slow->next;
		while (fast) {
			if (slow == fast) {
				return true;
			}
			if (fast->next == NULL) {
				return false;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
	}
};
