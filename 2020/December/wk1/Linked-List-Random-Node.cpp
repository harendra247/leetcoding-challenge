class Solution {
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : head(head){
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *node = head, *buffer[100], *pick;
        for (int before=0; node; before+=100) {
            int now = 0;
            while (node && now < 100) {
                buffer[now++] = node;
                node = node->next;
            }
            int r = rand() % (now + before);
            if (r < now)
                pick = buffer[r];
        }
        return pick->val;
    }
};
