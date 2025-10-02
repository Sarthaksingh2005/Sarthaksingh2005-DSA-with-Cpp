#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}


struct node* addnode(struct node* head1, struct node* head2) {
    struct node dummy;              
    struct node* curr = &dummy;     
    dummy.next = NULL;

    int carry = 0;
    while (head1 != NULL || head2 != NULL || carry != 0) {
        int sum = carry;

        if (head1 != NULL) {
            sum += head1->data;
            head1 = head1->next;
        }

        if (head2 != NULL) {
            sum += head2->data;
            head2 = head2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        curr->next = createnode(digit);
        curr = curr->next;
    }

    return dummy.next; 
}


void printlist(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void freelist(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
   
    struct node* head1 = createnode(1);
    head1->next = createnode(2);
    head1->next->next = createnode(3);
    head1->next->next->next = createnode(4);

    struct node* head2 = createnode(1);
    head2->next = createnode(2);
    head2->next->next = createnode(3);
    head2->next->next->next = createnode(4);

    printf("Original List 1: ");
    printlist(head1);

    printf("Original List 2: ");
    printlist(head2);

    struct node* result = addnode(head1, head2);

    printf("Added Linked List: ");
    printlist(result);

    freelist(head1);
    freelist(head2);
    freelist(result);

    return 0;
}
