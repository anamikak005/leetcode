class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *newHead = NULL, *tail = NULL;
        bool newZero = false;
        int sum = 0;
        while(head) {
            if(head->val == 0) {
                newZero = true;
                if(sum <= 0){

                } else if(!newHead) {
                    newHead = new ListNode(sum);
                    tail = newHead;
                } else {
                    tail-> next = new ListNode(sum);
                    tail = tail->next;
                }
                sum = 0;
            } else {
                if(newZero) {
                    sum+= head->val;
                }
            }
            head = head->next;
        }
        return newHead;
    }
};