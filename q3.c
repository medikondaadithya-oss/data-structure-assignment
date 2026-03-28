#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}
int pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}
int peek() {
    if (top == -1) return -1;
    return stack[top];
}
void nextGreaterElement(int arr[], int n) {
    int result[n];
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[i] > arr[peek()]) {
            int index = pop();
            result[index] = arr[i];
        }
        push(i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d → %d\n", arr[i], result[i]);
    }
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElement(arr, n);

    return 0;
}