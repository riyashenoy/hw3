#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {

    // base case: lists should be empty if thees no nodes
    if (head == nullptr) {

        // empty smaller list
        smaller = nullptr;

        // empty larget list
        larger = nullptr;

        return;
    }
    
    //saves current head in temp
    Node* currentNode = head;

    // movwe the head to next node in list
    head = head->next;

    // set current node to nullptr
    currentNode->next = nullptr; 
    
    // recursioN!
    llpivot(head, smaller, larger, pivot);
    
    if (currentNode->val <= pivot) {
        currentNode->next = smaller;

        // insert the current at front for the smaller list
        smaller = currentNode;
    } 
    else
    {
        currentNode->next = larger;
                // insert the current at front for the alrger list
        larger = currentNode;
    }
}