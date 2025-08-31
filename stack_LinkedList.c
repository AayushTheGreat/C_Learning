#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode{
    int data;
    struct stackNode *next;
} node;

typedef node *nodeptr;

nodeptr head = NULL;

void createStack();
void displayStack();
void push();
void popItem();
void peek();
void freeNexit();

int main()
{   
    int choice;
    printf("\n\t---STACK USING SINGLY LINKED LIST---");
    while(1){
        printf("\n-------------------------------------");
        printf("\n 1. Create Stack\n 2. Push\n 3. Pop\n 4. Peek\n 5. Exit");
        printf("\n-------------------------------------\nEnter your Choice :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: createStack(); break;
        case 2: push(); break;
        case 3: popItem(); break;
        case 4: peek(); break;
        case 5: freeNexit(); break;
        
        default: printf("\nInvalid input! Try Again.");
            break;
        }

    }
    return 0;
}

void createStack(){
    nodeptr temp;

    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL;

    int num;
    printf("\nNumber of node to push into Stack :");
    if ((scanf("%d",&num) != 1) || num < 1 ){
        int ch; while ((ch = getchar()) != '\n' && ch != EOF){}
        printf("\nInvalid Input! Try Again.");
        return;
    }

    for (int i = 1; i <= num; i++){
        nodeptr newnode = malloc(sizeof *newnode);
        if (newnode == NULL){
            printf("\nMemory Allocation Failed!");
            return;
        }

        printf(" Value for Node %d :",i);
        scanf("%d",&newnode->data);

        newnode->next = head;
        head = newnode;
    }
    printf("\n\tStack created!\n\n");
    displayStack();
}

void displayStack(){
    nodeptr temp = head;
    int count = 0;

    if(head == NULL){
        printf("\nStack is Empty, Nothing to display.");
        return;
    }
    printf("\n\tHEAD\n\t |\n");
    while(temp != NULL){
        count++;
        printf("\t[%d]\n\t |\n",temp->data);
        temp = temp->next;
    }
    printf("\tNULL\n\nSize of Stack : %d\n\n",count);
}

void push(){
    nodeptr newnode = malloc(sizeof *newnode);
    if (newnode == NULL){
        printf("\nMemory Allocation Failed.");
        return;
    }
    printf("\nValue to Push :");
    scanf("%d",&newnode->data);

    newnode->next = head;
    head = newnode;

    printf("\n\tPushed %d onto stack.\n", newnode->data);
    printf("--------------------------------------\n");
    displayStack();
}

void popItem(){
    nodeptr temp = head;
    
    if (head == NULL){
        printf("\nStack is Empty!");
        return;
    }
    int poppedValue = temp->data;
    head = head->next;
    free(temp);
    printf("\nPopped value: %d\n", poppedValue);
    printf("--------------------------------------\n");
    displayStack();
}

void peek(){
    if (head == NULL){
        printf("\nStack is Empty!");
        return;
    }else{
        printf("\nTop of Stack :%d\n", head->data);
    }
}

void freeNexit(){
    nodeptr temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL;

    printf("\nAllocated Memory released!\nExited program with No Errors.");
    printf("\n-------------------------------------");
    exit(0);
}