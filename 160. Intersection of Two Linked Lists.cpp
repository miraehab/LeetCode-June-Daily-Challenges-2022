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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> num_previous;
        map<ListNode*, int> ::iterator it;
        while(headA != nullptr || headB != nullptr){
            if(headA != nullptr){
                num_previous[headA]++;
                headA = headA->next;
            }
            if(headB != nullptr){
                num_previous[headB]++;
                headB = headB->next;
            }
        }
        for(it = num_previous.begin(); it != num_previous.end(); it++){
            if(it->second == 2) return it->first;
        }
        return nullptr;
    }
};