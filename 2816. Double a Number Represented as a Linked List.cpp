// 2816. Double a Number Represented as a Linked List
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

// Return the head of the linked list after doubling it.

 

// Example 1:


// Input: head = [1,8,9]
// Output: [3,7,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
// Example 2:


// Input: head = [9,9,9]
// Output: [1,9,9,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
 

// Constraints:

// The number of nodes in the list is in the range [1, 104]
// 0 <= Node.val <= 9
// The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev=nullptr;
//     ListNode* curr=head;
//     ListNode* next=nullptr;
//     while(curr!=nullptr) {
//         next=curr->next;
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//     }
//     return prev;
//     }
//     ListNode* doubleIt(ListNode* head) {
//         head=reverseList(head);

//         ListNode* curr=head;
//         ListNode* prev=NULL;
//         int carry=0;
//         while(curr!=NULL){
//             int newValue=curr->val*2+carry;
//             curr->val=newValue%10;
//             if(newValue>=10){
//                 carry=1;
//             }else{
//                 carry=0;
//             }
//             prev=curr;
//             curr=curr->next;
//         }
//         if(carry!=0){
//             ListNode* newHead=new ListNode(carry);
//             prev->next=newHead;
//         }
//         return reverseList(head);
//     }
// };

class Solution {

   int doubledLinkedList(ListNode* head){
    ListNode* temp = head;
    if(head == nullptr){
        return 0;
    }
    int carry = doubledLinkedList(head->next);
    int doubleVal = (temp->val)*2 + carry;
    int remainder = doubleVal%10;
    carry = doubleVal/10;
    temp->val = remainder;
    return carry;
   }


public:
    ListNode* doubleIt(ListNode* head) {
        int final = doubledLinkedList(head);
        if(final>0){
            ListNode * newNode = new ListNode(final, nullptr);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};