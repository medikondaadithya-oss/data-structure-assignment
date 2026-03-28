#include <stdio.h>
#include <string.h>
#define MAX 100
char queue[MAX][50];  
int front = -1, rear = -1;
void addDocument(char *doc) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot add more documents.\n");
        return;
    }
    if (front == -1) front = 0;
    strcpy(queue[++rear], doc);
    printf("Document \"%s\" added to queue.\n", doc);
}

void printDocument() {
    if (front == -1 || front > rear) {
        printf("No documents to print.\n");
        return;
    }
    printf("Printing document: %s\n", queue[front]);
    front++;
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("No pending documents.\n");
        return;
    }
    printf("Pending documents:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s\n", i - front + 1, queue[i]);
    }
}

int main() {
    int choice;
    char doc[50];

    while (1) {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add Document\n");
        printf("2. Print Document\n");
        printf("3. Display Pending Documents\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter document name: ");
                scanf("%s", doc);
                addDocument(doc);
                break;
            case 2:
                printDocument();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}