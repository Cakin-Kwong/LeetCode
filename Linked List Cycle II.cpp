/**
*    Leetcode Problem: Linked List Cycle II   Difficulty:Medium
*    Solution: 12ms with O(1) space
*/

/**
*    Given a linked list, return the node where the cycle begins. If there is no cycle, return null. 
*
*    Note: Do not modify the linked list.
*
*    Follow up :
*    Can you solve it without using extra space? 
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
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return NULL;
		}
		ListNode *slow = head->next;
		ListNode *fast = head->next->next;
		while (true) {
			if (fast == slow) {
				break;
			}
			if (fast == NULL || fast->next == NULL) {
				return NULL;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *temp = head;
		while (temp != slow) {
			slow = slow->next;
			temp = temp->next;
		}
		return temp;
	}
};