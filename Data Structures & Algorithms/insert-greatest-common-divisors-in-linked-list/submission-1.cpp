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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp->next){
            int gc=gcd(temp->val, temp->next->val);
            ListNode* nxt=temp->next;
            ListNode* node=new ListNode(gc);
            temp->next=node;
            node->next=nxt;
            temp=temp->next->next;
        }
        return head;
    }
};