#include<iostream>
using namespace std;


ListNode* merge(ListNode* left,ListNode*right){
    if(!left){
        return right;
    }
    if(!right){
        return left;
    }

    if(left->val<=right->val){
        left->next=merge(left->next,right);
        return left;
    }else {
        right->next=merge(right->next,left);
        return right;
    }
}
 ListNode* sortList(ListNode* head) {

   //split them
   //sort them
   //merge them
   //    4->2->1->3->null
   if(head==NULL || head->next==NULL) return head;

   ListNode* fast=head,slow=head;
   while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
   }
   //now slow is mid
   ListNode* mid=slow;
   ListNode* secondPortion=mid->next;
   mid->next=NULL;
   ListNode* l=sortList(head);
   ListNode* r=sortList(secondPortion);

   //Now merge them
   head=merge(l,r);
   return head;
}
int main ()




{

    return 0;
}