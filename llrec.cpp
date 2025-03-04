#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
//
//
//


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  
  // if the head is null we are done
  if (head == nullptr) {
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  Node* rest = head->next;

  head->next = nullptr;
  
  if (head->val <= pivot) {
    smaller = head;

    llpivot(rest, smaller->next, larger, pivot);
  } else {

    larger = head;
    llpivot(rest, smaller, larger->next, pivot);
  }

  head = nullptr;

}

