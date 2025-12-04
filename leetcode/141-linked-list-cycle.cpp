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
    bool hasCycle(ListNode *head) {
        ListNode* front = head;
        ListNode* back = head;

        if(head == nullptr)
            return false;
        
        while( front != nullptr && back != nullptr)
        {
            back = back->next;

            if(front->next == nullptr)
                return false;
            front = front->next->next;

            if(front == back)
                return true;
        }
        return false;
    }
};