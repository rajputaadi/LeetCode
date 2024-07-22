class Solution {
public:

    ListNode* FindMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL&& fast->next!=NULL){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }

    ListNode* MergeLists(ListNode* list1,ListNode* list2){
        ListNode* DummyNode = new ListNode(-1);
        ListNode* temp = DummyNode;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                temp->next = list1;
                temp = list1;
                list1=list1->next;
            }
            else{
                temp->next = list2;          
                temp = list2;
                list2=list2->next;
            }
        }
        if(list1) temp->next = list1;
        else temp->next = list2;
        return DummyNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL|| head->next==NULL) return head;
        ListNode* middle = FindMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);
        return MergeLists(left,right);
    }

};
