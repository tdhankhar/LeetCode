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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* head = NULL;
        ListNode* temp = NULL;
        int carry = 0;
        int curr_sum = 0;
        while(t1 && t2){
            int sum = t1->val + t2->val + carry;
            curr_sum = sum%10;
            carry = sum/10;
            if(head==NULL){
                head = new ListNode(curr_sum);
                temp = head;
            }else{
                ListNode* t3 = new ListNode(curr_sum);
                temp->next = t3;
                temp = temp->next;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1){
            int sum = t1->val + carry;
            curr_sum = sum%10;
            carry = sum/10;
            if(head==NULL){
                head = new ListNode(curr_sum);
                temp = head;
            }else{
                ListNode* t3 = new ListNode(curr_sum);
                temp->next = t3;
                temp = temp->next;
            }
            t1 = t1->next;
        }
        while(t2){
            int sum = t2->val + carry;
            curr_sum = sum%10;
            carry = sum/10;
            if(head==NULL){
                head = new ListNode(curr_sum);
                temp = head;
            }else{
                ListNode* t3 = new ListNode(curr_sum);
                temp->next = t3;
                temp = temp->next;
            }
            t2 = t2->next;
        }
        while(carry){
            int sum = carry;
            curr_sum = sum%10;
            carry = sum/10;
            if(head==NULL){
                head = new ListNode(curr_sum);
                temp = head;
            }else{
                ListNode* t3 = new ListNode(curr_sum);
                temp->next = t3;
                temp = temp->next;
            }
        }
        return head;
    }
};