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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* temp = head;  
        ListNode* prev = nullptr;  

        while (temp != nullptr) {  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front; 
        }

        return prev;  
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;

    
        while (temp != nullptr && k > 0) {
            k--; 
            temp = temp->next; 
        }

        return temp; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* next_node = nullptr;

    
        while (temp != nullptr) {
        
            ListNode* kth_node = getKthNode(temp, k);

            if (kth_node == nullptr) {
                if (prev) {
                    prev->next = temp;
                }
                break;
            }

            next_node = kth_node->next;

            kth_node->next = nullptr;


            ListNode* reversedHead = reverseLinkedList(temp);

    
            if (head == temp) {
                head = reversedHead;
            } else {
                prev->next = reversedHead;
            }

            prev = temp;
            temp = next_node;
        } 

        return head;
    }
};
