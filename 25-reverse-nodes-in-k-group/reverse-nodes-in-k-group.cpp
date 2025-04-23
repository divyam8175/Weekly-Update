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
pair<ListNode*,ListNode*> reverse(ListNode*temp1,ListNode*temp2) {
    cout<<"andar a agaya"<<endl;
    if(temp2==NULL) return {NULL,temp1};
    ListNode*prev=NULL;
    ListNode*curr=temp1;
    ListNode*forw=curr->next;
    while(curr) {
        curr->next=prev;
        prev=curr;
        curr=forw;
        if(forw)
        forw=forw->next;
    }
    cout<<temp1->val<<" "<<temp2->val<<endl;
    return {temp2,temp1};
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*newhead=new ListNode(-1);
        newhead->next=head;
        ListNode*temp1=newhead;
        ListNode*temp2=temp1->next;
        int count=0;
        while(temp2) {
            count++;
            if(count==k) {
                ListNode*forw=temp2->next;
                ListNode*curr1=temp1->next;
                temp2->next=NULL;
                temp1->next=NULL;
                auto curr=reverse(curr1,temp2);
                temp1->next=curr.first;
                curr.second->next=forw;
                temp1=curr.second;
                temp2=forw;
                count=0;
            }else {
                temp2=temp2->next;
            }
        }
        return newhead->next;
    }
};