#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int element;
    struct node* next;
}node;

node *head;
node *tail;
int top = -1;
int sum = 0;

void insert(int n);
int delete();
int main() {
    int K;
    int N;
    char buff[16];

    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));

    fgets(buff, sizeof(buff), stdin);
    K = (int) strtol(buff, NULL, 10);

    for (int i = 0; i < K; i++) {
        fgets(buff, sizeof(buff), stdin);
        N = (int) strtol(buff, NULL, 10);
        if (N == 0) {
            sum-=delete();
        }else {
            sum += N;
            insert(N);
        }
    }

    printf("%d\n", sum);
}

void insert(int n) {
    node* temp = (node*)malloc(sizeof(node));
    temp-> element = n;
    if (top == -1) {
        head -> next = temp;
        temp -> next = tail;
        top = 0;
    }else {
        temp -> next = head -> next;
        head -> next = temp;
        top ++;
    }
}

int delete() {
    node* temp = (node*)malloc(sizeof(node));
    if (top == -1) {
        return 0;
    }else if (top == 0) {
        temp = head -> next;
        head -> next = NULL;
        top = -1;
    }
    else {

        temp = head -> next;
        head -> next = temp -> next;
        top --;
    }

    return temp -> element;
    free(temp);
}