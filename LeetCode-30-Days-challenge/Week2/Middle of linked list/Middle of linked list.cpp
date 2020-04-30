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
    ListNode* middleNode( ListNode* head ) {
        int sizee = 0 , C = 0 ;
        ListNode *f = head ;
        ListNode *temp = head ;
        while( true )
        {
            ++ sizee ;
            if(temp-> next == NULL) break ;
            else temp = temp->next ;
        }
        sizee = floor( sizee / 2 ) ;
        while( true )
        {
            if( C == sizee ) {  f = head ; }
            if(head->next == NULL) break ;
            else head = head->next ;
            ++C ;
        }
        return f ;
    }
};
