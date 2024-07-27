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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL|| k==0) return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next!=NULL){
            tail = tail->next;
            len++;
        }

        k = k % len;
        if(k==0) return head;
        ListNode* new_tail = head;
        for(int i =1;i<len-k;i++){
            new_tail = new_tail->next;
        }
        ListNode* newhead = new_tail->next;
        new_tail->next = nullptr;
        tail->next = head;
        return newhead;
    }
};