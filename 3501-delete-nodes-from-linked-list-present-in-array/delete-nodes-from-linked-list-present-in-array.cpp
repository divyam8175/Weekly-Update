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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++) {
            mpp[nums[i]]++;
        }
        ListNode*temp=head;
        while(temp!=NULL) {
            if(mpp[temp->val] != 0) {
                temp=temp->next;
            }else {
                break;
            }
        }
        head=temp;
        temp=head;
        ListNode*temp1=temp->next;
        while(temp!=NULL && temp1 != NULL) {
            if(mpp[temp1->val] != 0) {
                
            }else {
                temp->next=temp1;
                temp=temp->next;
            }
            temp1=temp1->next; 
        }
        temp->next=temp1;
        return head;
    }
};