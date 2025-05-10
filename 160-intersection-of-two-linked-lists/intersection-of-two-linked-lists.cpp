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
        int lenA = 1, lenB=1;
        ListNode *tailA = headA, *tailB = headB;
        ListNode *pointerA = headA, *pointerB = headB;
        while(tailA->next){
            tailA= tailA->next;
            lenA++;
        }
        while(tailB->next){
            tailB= tailB->next;
            lenB++;
        }

        int diff;
        if(lenA>lenB){
            diff = lenA-lenB;
            while(diff--){
                pointerA=pointerA->next;
            }
        }
        if(lenA<lenB){
            diff = lenB-lenA;
            while(diff--){
                pointerB=pointerB->next;
            }
        }

        while(pointerA!=pointerB){
            pointerA=pointerA->next;
            pointerB=pointerB->next;
        }
        return pointerA;
    }
};