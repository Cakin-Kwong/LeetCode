/**   Leetcode problem: Intersection of Two Linked Lists   Difficulty:Easy
*     solution: 52ms with O(1) memory;
*/

/**For example, the following two linked lists :
*        A : a1 → a2
*	                 ↘
*	                  c1 → c2 → c3
*	                 ↗
*	B : b1 → b2 → b3
*   begin to intersect at node c1.
*
*	Notes :
*	•If the two linked lists have no intersection at all, return null.
*	•The linked lists must retain their original structure after the function returns.
*	•You may assume there are no cycles anywhere in the entire linked structure.
*	•Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) {
            return NULL;
        }
        int countA = 0, countB = 0;
        ListNode *tempA, *tempB;
        tempA = headA;
        tempB = headB;
        while(tempA) {
            countA++;
            tempA =tempA->next;
        }
        while(tempB){
            countB++;
            tempB =tempB->next;
        }
        if(countA < countB) {
            tempA = headB;
            tempB = headA;
        }
        else {
            tempA = headA;
            tempB = headB;
        }
        int extra_dis = abs(countA - countB);
        while(extra_dis--){
            tempA = tempA->next;
        }
        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};