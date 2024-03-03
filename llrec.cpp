#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    if(head == nullptr)
        return;

    Node* newnode = new Node(head->val, nullptr);
    Node* next = head->next;
    delete head;

    if(newnode->val <= pivot){
        if(smaller == nullptr){
            smaller = newnode;
            llpivot(next, smaller, larger, pivot);
        } 
        else{
            smaller->next = newnode;
            llpivot(next, smaller->next, larger, pivot);
        } 
    } else{
        if(larger == nullptr){
            larger = newnode;
            llpivot(next, smaller, larger, pivot);
        }
        else{
            larger->next = newnode;
            llpivot(next, smaller, larger->next, pivot);
        }
    }
}