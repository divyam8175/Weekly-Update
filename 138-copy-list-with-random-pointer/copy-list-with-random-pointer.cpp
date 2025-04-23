/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*temp=head;
        Node*curr=new Node(-1);
        Node*newhead=curr;
        unordered_map<Node*,Node*>mpp;
        while(temp) {
            if(temp && mpp.find(temp) == mpp.end()) {
                Node*prev=new Node(temp->val);
                curr->next=prev;
                mpp[temp]=prev;
                curr=curr->next;
            } else {
                curr->next=mpp[temp];
                curr=curr->next;
            }
            temp=temp->next;
        }
        temp=head;
        Node*temp1=newhead->next;
        while(temp) {
            if(temp->random) {
                temp1->random=mpp[temp->random];
            }
            temp=temp->next;
            temp1=temp1->next;
        }
        return newhead->next;
    }
};