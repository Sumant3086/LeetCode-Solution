// 1171. Remove Zero Sum Consecutive Nodes from Linked List
// Medium
// Topics
// Companies
// Hint
// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

// After doing so, return the head of the final linked list.  You may return any such answer.

 

// (Note that in the examples below, all sequences are serializations of ListNode objects.)

// Example 1:

// Input: head = [1,2,-3,3,1]
// Output: [3,1]
// Note: The answer [1,2,1] would also be accepted.
// Example 2:

// Input: head = [1,2,3,-3,4]
// Output: [1,2,4]
// Example 3:

// Input: head = [1,2,3,-3,-2]
// Output: [1]
 

// Constraints:

// The given linked list will contain between 1 and 1000 nodes.
// Each node in the linked list has -1000 <= node.val <= 1000.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
//  */
// class Solution {
// public:
//     ListNode* removeZeroSumSublists(ListNode* head) {
//         ListNode* temp=new ListNode(0);
//         temp->next=head;
//         int prefix=0;
//         unordered_map<int, ListNode*>mp;
//         mp[0]=temp;
//         while(head!=NULL){
//             prefix+=head->val;
//             mp[prefix]=head;
//             head=head->next;
//         }
//         head=temp;
//         prefix=0;
//         while(head!=NULL){
//             prefix+=head->val;
//             head->next=mp[prefix]->next;
//             head=head->next;
//         }
//         return temp->next;
//     }
// };

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        int prefix=0;
        mp[0]=dummy;
        while(head!=NULL){
            prefix+=head->val;
            if (mp.find(prefix)!=mp.end()){
                ListNode* prev=mp[prefix]->next;
                int sum=prefix+prev->val;
                while(sum!=prefix) {
                    mp.erase(sum);
                    prev=prev->next;
                    sum+=prev->val;
                }
                mp[prefix]->next=head->next;
            } else {
                mp[prefix]=head;
            }
            head=head->next;
        }
        
        return dummy->next;
    }
};