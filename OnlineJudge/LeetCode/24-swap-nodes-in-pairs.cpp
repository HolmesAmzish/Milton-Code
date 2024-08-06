/**
 * @problem: Swap nodes in pairs
 * @date: 2024-08-06
 * @author: Nulla
 * @definition: for singly-linked list.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ptr = head;
        while (ptr->next != nullptr) {
            swap(ptr, ptr->next);
            if (ptr->next->next != nullptr) {
                ptr = ptr->next->next;
            }
        }
        return head;
    }
};