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
        ListNode* temp=head;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
        if(n==len) return head->next;
        temp=head; 
        while(len-1){
            if(len-1==n){
                ListNode* node=temp->next;
                temp->next=node->next;
                delete node;
                break;
            }
            temp=temp->next;
            len--;
        }
        return head;
    }
};
