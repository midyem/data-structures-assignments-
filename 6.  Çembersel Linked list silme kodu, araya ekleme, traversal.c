#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// إنشاء عقدة
Node* create(int d) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = d;
    n->next = n;
    return n;
}

// إضافة في الوسط (بعد عقدة معينة)
void insertMid(Node* prev, int d) {
    if (!prev) return;
    Node* n = create(d);
    n->next = prev->next;
    prev->next = n;
}

// حذف عقدة
void delete(Node** head, Node* del) {
    if (!*head || !del) return;
    
    if (*head == del && del->next == del) { // عقدة واحدة فقط
        free(del);
        *head = NULL;
        return;
    }
    
    Node* prev = *head;
    while (prev->next != del) prev = prev->next;
    
    prev->next = del->next;
    if (*head == del) *head = del->next;
    free(del);
}

// اجتياز وعرض
void traverse(Node* head) {
    if (!head) return;
    Node* curr = head;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

// إضافة في النهاية
void append(Node** head, int d) {
    Node* n = create(d);
    if (!*head) {
        *head = n;
        return;
    }
    Node* curr = *head;
    while (curr->next != *head) curr = curr->next;
    curr->next = n;
    n->next = *head;
}

// اختبار
int main() {
    Node* head = NULL;
    
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    printf("الأصل: ");
    traverse(head); // 10 20 30
    
    // إضافة 15 بعد 10
    Node* temp = head;
    insertMid(temp, 15);
    printf("بعد الإضافة: ");
    traverse(head); // 10 15 20 30
    
    // حذف 20
    temp = head->next->next; // عقدة 20
    delete(&head, temp);
    printf("بعد الحذف: ");
    traverse(head); // 10 15 30
    
    return 0;
}