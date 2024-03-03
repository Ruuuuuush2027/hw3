#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    if(head == nullptr){
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node* next = head->next;

    if(head->val <= pivot){
        smaller = head;
        head = nullptr;
        llpivot(next, smaller->next, larger, pivot);
    } else{
        larger = head;
        head = nullptr;
        llpivot(next, smaller, larger->next, pivot);
    }
}