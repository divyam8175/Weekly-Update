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
ListNode*merger(ListNode*temp1,ListNode*temp2) {
    ListNode*temp=new ListNode(-1);
    ListNode*temp3=temp;
    // if(temp1->val < temp2->val) {
    //     temp->next=temp1;
    // }else {
    //     temp->next=temp2;
    // }
    while(temp1 && temp2) {
        if(temp1->val < temp2->val) {
            temp3->next=temp1;
            temp1=temp1->next;
            temp3=temp3->next;
        }else {
            temp3->next=temp2;
            temp2=temp2->next;
            temp3=temp3->next;
        }
    }
    if(temp1) temp3->next=temp1;
    if(temp2) temp3->next=temp2;
    return temp->next;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode*temp=new ListNode(-1);
        ListNode*temp1=lists.back();
        lists.pop_back();
        while(lists.size()>0) {
            ListNode*temp2=lists.back();
            lists.pop_back();
            temp1=merger(temp1,temp2);
        }
        return temp1;
    }
};