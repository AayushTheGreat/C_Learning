#include <stdio.h>

#define max 5

//Encapsulation of Data Structures
typedef struct {
    int array[max];
    int front;
    int rear;
}CircularQueue;

void initCircularQueue(CircularQueue* queue){
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty( CircularQueue *queue){
    return queue->front == -1;
    
}

int isFull( CircularQueue *queue){
    return (queue->rear + 1) % max == queue->front;
}



void enqueue(CircularQueue *queue){
    if (isFull(queue)){
        printf("\nOverFlow! cannot enqueue elements.");
        return;
    }
    if (isEmpty(queue)){
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % max;
    int value;
    printf("\nEnter Value :");
    scanf("%d",&value);
    queue->array[queue->rear] = value;
    printf("\nValue %d Enqueued!", value);
}

int dequeue(CircularQueue *queue){
    if (isEmpty(queue)){
        printf("\nUnderFlow Case! cannot display empty queue.");
        return -1; //return value for error
    }
    int value = queue->array[queue->front];
    if (queue->front == queue->rear){
        //for last element
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % max;
    }
    printf("\nDequeued Element : %d", value);
    return value;
}

void display(CircularQueue *queue){
    if (isEmpty(queue)){
        printf("\nUnderFlow Case! cannot display empty queue.");
        return;
    }
    printf("\nQueue Elements (FRONT -> REAR) :\n\n\t");
    int i = queue->front;
    do{
        printf("[%d] ", queue->array[i]);
        i = (i + 1) % max;
    }while ( i != ((queue->rear + 1) % max));
    printf("\n");
}

void peek(CircularQueue *queue){
    if (isEmpty(queue)){
        printf("\nUnderFlow Case! cannot display empty queue.");
        return;
    }
    printf("\n\tValue at Front : %d \n", queue->array[queue->front]);
    printf("\tValue at Rear : %d \n", queue->array[queue->rear]);
}

void pauseScreen(){
    printf("\n--------------------------------------");
    printf("\nPress Enter to Continue...");
    getchar();
    getchar();
}

int main()
{
    CircularQueue myQueue;
    initCircularQueue(&myQueue);
    int choice;
    while(1){
        system("cls");
        printf("\t---Circular Queue Using Array---");
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
            case 1: enqueue(&myQueue); break;
            case 2: dequeue(&myQueue); break;
            case 3: peek(&myQueue); break;
            case 4: display(&myQueue); break;
            case 5: exitProgram(); break;

            default: printf("\nInvalid Choice! try again."); break;
        }

        pauseScreen();
    }
    return 0;
}

void exitProgram() {
    printf("\nProgram Terminated!\n");
    printf("\n--------------------------------------");
    exit(0);
}