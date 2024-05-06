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
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         ListNode* curr=head;
//         stack<ListNode*>stack;
//         while(curr!=nullptr){
//             while(!stack.empty() && stack.top()->val<curr->val){
//                 stack.pop();
//             }
//             stack.push(curr);
//             curr=curr->next;
//         }
//         ListNode* next=nullptr;
//         while(!stack.empty()){
//             curr=stack.top();
//             stack.pop();
//             curr->next=next;
//             next=curr;
//         }
//         return curr;
//     }
// };
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(0);
        if(head==NULL)return head;
        head->next = removeNodes(head->next);
        if(head->next==NULL)return head;
        if(head->next->val>head->val)return head->next;
        return head;
    }
};