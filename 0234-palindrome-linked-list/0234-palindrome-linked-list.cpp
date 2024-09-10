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
    ListNode* revrseSecondHalf(ListNode* head){
        ListNode* temp =head;
        ListNode* prev= NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;

        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast ->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* first = head;
        ListNode* newhead = revrseSecondHalf(slow->next);
        ListNode* second = newhead;
        while(second!=NULL){
            if(first->val != second->val){
                    revrseSecondHalf(newhead);
                    return false;
            }
            first = first->next;
            second = second->next;
            
        }
        revrseSecondHalf(newhead);
        return true;

    }
};