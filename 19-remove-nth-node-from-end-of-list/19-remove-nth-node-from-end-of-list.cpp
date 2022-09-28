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
        ListNode* temp=head,*prev=NULL;
        if(temp->next==NULL) return NULL;
        int size=0;
        while(temp) {
            temp=temp->next;
            size++;
        }
        temp=head;
        int ind=size-n+1;
        for(int i=1; i<ind;i++) {
            prev=temp;
            temp=temp->next;
        }
        if(prev==NULL) prev=head;
        if(ind==1) {
            head=prev->next;
            return head;
        }
        else 
            prev->next=temp->next;
        temp->next=NULL;
        return head;
    }
};