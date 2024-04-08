// 19. Remove Nth Node From End of List
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
 

// Follow up: Could you do this in one pass?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        ListNode* firstPtr=dummy; 
        ListNode* secondPtr=dummy;

        for(int i=0;i<n;i++){
            secondPtr=secondPtr->next;
        } 
        while (secondPtr->next!=nullptr){
            firstPtr=firstPtr->next;
            secondPtr=secondPtr->next;
        }

        firstPtr->next=firstPtr->next->next;
        return dummy->next;
    }
};

//Method 2
// class Solution {
//  public:
//   ListNode* removeNthFromEnd(ListNode* head, int n) {
//     ListNode* slow=head;
//     ListNode* fast=head;

//     while(n--)
//       fast=fast->next;
//     if(fast==nullptr)
//       return head->next;

//     while(fast->next){
//       slow=slow->next;
//       fast=fast->next;
//     }
//     slow->next=slow->next->next;

//     return head;
//   }
// };