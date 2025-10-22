#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if (head == nullptr) {
        // On entry smaller/larger may be garbage; make them valid.
        smaller = nullptr;
        larger  = nullptr;
        return;
    }

    Node* curr = head;        // take the first node
    Node* rest = head->next;  // remainder of the list

    // Recursively split the remainder; this will set smaller/larger properly.
    llpivot(rest, smaller, larger, pivot);

    // Now attach curr to the front of the appropriate output list.
    if (curr->val <= pivot) {
        curr->next = smaller;
        smaller = curr;
    } else {
        curr->next = larger;
        larger = curr;
    }

    // The original list should be empty when we’re done.
    head = nullptr;
}

