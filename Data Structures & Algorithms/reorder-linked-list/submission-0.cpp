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
    void reorderList(ListNode* head) {
        ListNode* head1=head;
        ListNode* head2=head;
        while(head2 && head2->next){
            head1=head1->next;
            head2=head2->next->next;
        }
        head2=head1->next;
        head1->next=NULL;
        head1=head;
        ListNode* node=NULL;
        while(head2){
            ListNode* temp=head2->next;
            head2->next=node;
            node=head2;
            head2=temp;
        }
        head2=node;
        ListNode* ans=new ListNode();
        node=ans;
        while(head1 && head2){
            node->next=head1;
            head1=head1->next;
            node=node->next;
            node->next=head2;
            head2=head2->next;
            node=node->next;
        }
        if(head1){
            node->next=head1;
        }
        head=ans->next;
    }
};
