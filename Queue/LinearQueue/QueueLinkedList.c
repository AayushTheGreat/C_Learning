#include <stdio.h>
#include <stdlib.h>

typedef struct qNode
{
    int data;
    struct qNode *next;
} node;

typedef node *nodeptr;

nodeptr front = NULL, rear = NULL;

void enqueue();
void dequeue();
void peek();
void display();
void freeQueue();
void pauseScreen();

int main()
{
    int choice;
    while (1)
    {
        system("cls");
        printf("\t---QUEUE USING SINGLY LINKED LIST---");
        printf("\n----------------------------------------------");
        printf("\n 1. Enqueue\n 2. Dequeue\n 3. Peek\n 4. Display\n 5. Exit");
        printf("\n----------------------------------------------\nEnter your Choice :");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            freeQueue();
            break;
        default:
            printf("Invalid Choice! try again.");
            pauseScreen();
            break;
        }
    }
    return 0;
}

void pauseScreen()
{
    printf("\n----------------------------------------------");
    printf("\nPress enter to continue...");
    getchar();
    getchar();
}

void enqueue()
{
    nodeptr newnode = malloc(sizeof *newnode);
    if (newnode == NULL)
    {
        printf("\nMemory Allocation failed!");
        pauseScreen();
        return;
    }
    printf(" Value to enqueue :");
    scanf("%d",&newnode->data);

    newnode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("\nValue %d enqueued to queue.\n\n", newnode->data);
    pauseScreen();
}

void dequeue()
{
    nodeptr temp = front;

    if (front == NULL)
    {
        printf("\nQueue Undeflow! Cannot deqeue element.");
        pauseScreen();
        return;
    }

    printf("\nDequeued Element : %d", front->data);
    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
    pauseScreen();
}

void peek()
{
    if (front == NULL)
    {
        printf("\nQueue Undeflow! Cannot dequeue element.");
        pauseScreen();
        return;
    }
    else
    {
        printf("\nElement at front : %d\n", front->data);
    }
    pauseScreen();
}

void display()
{
    if (front == NULL)
    {
        printf("\nQueue Undeflow! Cannot deqeue element.");
        pauseScreen();
        return;
    }
    int count = 0;
    printf("\n---Queue Elements (front -> rear)---\n\n\t");
    nodeptr temp = front;
    while (temp != NULL)
    {
        count++;
        printf("[%d]",temp->data);
        if (temp->next != NULL)
        {
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n\nSize of Queue :%d\n",count);
    pauseScreen();
}

void freeQueue()
{
    nodeptr temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        free(temp);
    }
    rear = NULL;
    printf("\nResources Freed! Program Terminated.");
    printf("\n----------------------------------------------\n");
    exit(0);
}