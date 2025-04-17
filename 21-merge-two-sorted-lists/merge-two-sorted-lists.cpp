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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

         if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* mergedHead = nullptr;

        // Set mergedHead to the smaller starting node
        if (head1->val < head2->val) {
            mergedHead = head1;
            head1 = head1->next;
        } else {
            mergedHead = head2;
            head2 = head2->next;
        }

        ListNode* current = mergedHead;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                current->next = head1;
                head1 = head1->next;
            } else {
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }

        // Attach the remaining part of the non-empty list
        if (head1 != nullptr) {
            current->next = head1;
        } else {
            current->next = head2;
        }

        return mergedHead;
       
     
    }
};