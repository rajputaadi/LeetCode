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
 #include<bits/stdc++.h>
class Solution {
public:
int length(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL ||head->next == NULL) return NULL;
        ListNode* temp = head;
        int len = length(head);
        int mid = len/2;
            for(int i=0;i<mid;i++){
                if(i==mid-1){
                    ListNode* todelete = temp->next;
                    temp->next = temp->next->next;
                    delete todelete;
                }
                temp = temp->next;
            }
        return head;

    }
};