#include <stdio.h>
#include <stdlib.h>

#define capacity 10

int queue[capacity];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void peek();
void display();
void exitProgram();
void pauseScreen(){
    printf("\n--------------------------------------");
    printf("\nPress Enter to Continue...");
    getchar();
    getchar();
}

int main()
{   
    int choice;
    while(1){
        system("cls");
        printf("\t---QUEUE USING ARRAYS---");
        printf("\n--------------------------------------");
        printf("\n 1. Enqueue\n 2. Dequeue\n 3. Peek\n 4. Display\n 5. Exit");
        printf("\n--------------------------------------");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        if((choice > 5) || (choice <= 0)){
            printf("\nInvalid Choice! Try Again.");
            return 0;
        }

        switch(choice){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exitProgram(); break;

            default: printf("\nInvalid Choice! try again."); break;
        }

        pauseScreen();
    }
    return 0;
}

void enqueue(){
    int value;
    if ((front == 0 && rear == capacity - 1) || (rear + 1 == front)){
        printf("\nQueue Overflow! Cannot enqeue elements.");
        return;
    }

    printf("\n Value to enqueue :");
    scanf("%d",&value);

    if (front == -1){ //queue is empty
        front = rear = 0;
    }else {
        rear = (rear + 1) % capacity;
    }

    queue[rear] = value;
    printf("\nEnqueued %d into Queue.",value);
}

void dequeue() {
    if (front == -1) {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }
    printf("\nDequeued value: %d\n", queue[front]);

    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
}

void peek() {
    if (front == -1) {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\nFront of Queue: %d\n", queue[front]);
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is Empty! Nothing to display.\n");
        return;
    }

    printf("\n--- QUEUE (Front <- Rear) ---\n\n");
    for (int i = front; i <= rear; i++)
    {
        printf("[%d]", queue[i]);
        if (i < rear)
            printf(" <- ");  // Arrow shows order
    }
    printf("\n\nSize of Queue: %d", rear - front + 1);
}

void exitProgram() {
    printf("\nProgram Terminated!\n");
    printf("\n--------------------------------------");
    exit(0);
}