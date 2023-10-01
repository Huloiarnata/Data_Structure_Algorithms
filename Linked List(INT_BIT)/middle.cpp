/*
How will you find the middle element of a singly linked list
without iterating the list more than once?

ans. Two pointer method fast and slow pointer
fast pointer: moves two nodes at a time
slow pointer: moves one node at a time
by the time fast pointer reaches the end slow pointer is in the midle
 */

#include <iostream>
using namespace std;
typedef struct Node{
    int val;
    Node *next;
};
Node *NewNode(Node *start, int data){
    Node *ptr = start;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->val = data;
    temp->next = NULL;
    ptr->next = temp;
    return start;
}
void ShowList(Node *start){
    Node *ptr = start;
    while(ptr!=NULL){
        cout<<"->"<<ptr->val;
        ptr = ptr->next;
    }
}
Node *MiddleNode(Node *start){
    // To find middle node in single itteration.
    Node *fast_ptr = start;
    Node *slow_ptr = start;
    while(fast_ptr!=NULL && fast_ptr->next!=NULL){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr;
}
int main(){
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    int num_elements;cout<<"Enter num of elements:";cin>>num_elements;
    int head_data;
    cout<<"Enter head data:";cin>>head_data; head->val = head_data;
    while(num_elements>1){
        int data;cout<<"Enter value of node: ";cin>>data;
        head = NewNode(head, data);
        num_elements--;
    }
    ShowList(head);
    Node *middle = MiddleNode(head);
    cout<<"Middle element is : "<<middle->val;
    
}