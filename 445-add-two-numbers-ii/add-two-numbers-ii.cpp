class Solution {
public:
void print(stack<int>s){
    while(!s.empty()) {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
}
ListNode*solve(ListNode* l1, ListNode* l2,stack<int>&s1,stack<int>&s2) {
    if(l1==NULL && l2==NULL) {
        return NULL;
    }
    if(l1 != NULL) {
        s1.push(l1->val);
        l1=l1->next;
    }
    if(l2 != NULL) {
        s2.push(l2->val);
        l2=l2->next;
    }
    ListNode*temp=solve(l1,l2,s1,s2);
    int a=0;
    if(!s1.empty()) {
    a=s1.top();
    s1.pop();
    }
    int b=0;
    if(!s2.empty()){
    b=s2.top();
    s2.pop();
    }
    int c=a+b;
    int rem=0;
    if(c>9) {
        rem=c/10;
        c=c%10;
    }
    if(rem>0 && !s1.empty()) {
        int z=s1.top();
        s1.pop();
        s1.push(z+rem);
    }
    else if(rem>0 && !s2.empty()) {
        int z=s2.top();
        s2.pop();
        s2.push(z+rem);
    }
    if(s1.empty() && s2.empty() && rem >0) {
        s1.push(rem);
    }
    ListNode*temp1=new ListNode(c);
    temp1->next=temp;
    return temp1;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1;
        stack<int>s2;
        ListNode*temp=solve(l1,l2,s1,s2);
        if(!s1.empty()){
        ListNode*head=new ListNode(s1.top());
        head->next=temp;
        return head;
        }
        return temp;
    }
};