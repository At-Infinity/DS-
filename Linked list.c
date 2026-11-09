Linked list 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;          // Step 1: head = NULL

void insert() {                    // Step b
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;                    // go back to menu
    }
    printf("Enter value: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;     // traverse to last node
        temp->next = newnode;
    }
}

void delete_node() {               // Step c
    struct node *temp;
    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        temp = head;
        head = head->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
}

void display() {                   // Step d
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice;
    do {                           // Step 2: repeat until Exit
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();       break;
            case 2: delete_node();  break;
            case 3: display();      break;
            case 4: printf("Exiting program...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;                      // Step 3: STOP
}
