#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr){}
};

ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next= nullptr;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
}
void printLL(ListNode* head){
    ListNode* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    //just adding values manually to check the function is working or not

    cout<<"ORIGNAL LIST: "<<endl;
    printLL(head);


    
    ListNode* answer= reverseList(head);
    cout<<"New LIST: "<<endl;
    printLL(answer);

    //memory clean up
    while(answer){
        ListNode* temp= answer;
        answer=answer->next;
        delete temp;
    }
    return 0;
}