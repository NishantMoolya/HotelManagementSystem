#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to add a new node at the end of the linked list
void addNode(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove a node from the linked list by value
void removeNode(Node **head, int data) {
    Node *temp = *head;
    Node *prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Function to display the elements of the linked list
void displayList(Node *head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node* traverseDish(Node *head){
    if (head == NULL)
    {
        printf("\nNo dish available in menu");
        return NULL;
    }else{
        return head;
    }
}

void topdish(Node *menu_head){
    Node *temp,*top;
    int count = 0;
    if (menu_head == NULL)
    {
       printf("\nNo dish available in menu");
    }else{
        temp = menu_head;
        while (temp != NULL)
        {
            if(top->data < temp->data){
                top = temp;
            }
            temp = temp->next;
        }
        printf("\nTop selling dish is: and %d plates were sold",top->data);
    }
}

int add(){
    int a,b;
    printf("\nEnter two numbers:");
    scanf("%d%d",&a,&b);
    return a+b;
}
int main() {
    Node *head = NULL;

    // Add nodes to the linked list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Display the initial list
    displayList(head);
    Node *temp = traverseDish(head);
    while (temp != NULL)
    {
        printf("%d->\t",temp->data);
        temp = traverseDish(temp->next);
    }
    
    //topdish(head);
    // Remove a node from the list
    removeNode(&head, 3);
    topdish(head);
    // Display the list after removal
    displayList(head);
    int res = 0;
    res += add();
    printf("\nresult = %d",res);
    // Free memory
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
