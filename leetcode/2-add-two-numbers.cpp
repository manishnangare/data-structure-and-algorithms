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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum = 0, carry = 0;
        ListNode *result = new ListNode(0);
        ListNode *nextNode;
        nextNode = result;

        while( l1 != nullptr && l2 != nullptr)
        {
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;

            ListNode *temp = new ListNode(sum);
            nextNode->next = temp;
            nextNode = nextNode->next;

            l1 = l1->next;
            l2 = l2->next;
            
        }

        while(l1 != nullptr)
        {
            sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;

            ListNode *temp = new ListNode(sum);
            nextNode->next = temp;
            nextNode = nextNode->next;
            l1 = l1->next;
        }

        while(l2 != nullptr)
        {
            sum = l2->val + carry;
            carry = sum/10;
            sum = sum%10;

            ListNode *temp = new ListNode(sum);
            nextNode->next = temp;
            nextNode = nextNode->next;
            l2 = l2->next;
        }

        if(carry != 0)
        {
            ListNode *temp = new ListNode(carry);
            nextNode->next = temp;            
        }

        return result->next;;
    }
};