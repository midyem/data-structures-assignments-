#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

//
Node* create(int d) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = d;
    n->next = n->prev = NULL;
    return n;
}

void insertMid(Node* prevNode, int d) {
    if (!prevNode) return;
    Node* n = create(d);
    n->next = prevNode->next;
    n->prev = prevNode;
    if (prevNode->next) 
        prevNode->next->prev = n;
    prevNode->next = n;
}


void delete(Node** head, Node* del) {
    if (!*head || !del) return;
    if (*head == del) *head = del->next;
    if (del->next) del->next->prev = del->prev;
    if (del->prev) del->prev->next = del->next;
    free(del);
}


void traverse(Node* head) {
    Node* curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


void append(Node** head, int d) {
    Node* n = create(d);
    if (!*head) {
        *head = n;
        return;
    }
    Node* curr = *head;
    while (curr->next) curr = curr->next;
    curr->next = n;
    n->prev = curr;
}


int main() {
    Node* head = NULL;
    
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    printf("الأصل: ");
    traverse(head); 
    
    Node* temp = head;
    insertMid(temp, 15);
    printf("بعد الإضافة: ");
    traverse(head); 
    temp = head->next->next; 
    printf("بعد الحذف: ");
    traverse(head); 
    
    return 0;
}