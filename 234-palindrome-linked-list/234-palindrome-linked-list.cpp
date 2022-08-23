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
    bool isPalindrome(ListNode* head) {
        stack<int>s;                //LIFO 
        ListNode* temp = head;
        while(temp){                // Fill the stack such that the values are stored in reverse order
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            if (s.top() != temp->val)           // If top of stack(in rev) isnt equal then not palindrome
                return false;
            s.pop();
            temp=temp->next;
        }
        return true;
    }
};