#include <stdio.h>
#include <stdlib.h>

#define size 10

int stack[size];
int top = -1;

void push();
void pop();
void peek();
void display();
void exitProgram();
void pauseScreen(){
    printf("\n----------------------------------------\n");
    printf("Press Enter to Continue...");
    getchar();
    getchar();
}

int main()
{
    int choice;
    while (1)
    {
        system("cls");
        printf("\t---STACK USING ARRAY---");
        printf("\n----------------------------------------\n");
        printf(" 1. Push\n 2. Pop\n 3. Peek\n 4. Display\n 5. Exit");
        printf("\n----------------------------------------\nEnter Choice :");
        scanf("%d", &choice);

        if ((choice <= 0) || (choice > 5))
        {
            printf("\nInvaild Choice! Try Again.");
            return 0;
        }

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exitProgram();
            break;

        default:
            printf("\nInvalid Choice!Try Again...");
            break;
        }
        pauseScreen();
    }
    return 0;
}

void push()
{
    int value;
    if (top == size - 1)
    {
        printf("\nStack Overflow! Cannot push elements.");
        return;
    }
    printf("Value to push :");
    scanf("%d", &value);
    stack[++top] = value;
    printf("\n%d pushed into stack.\n", value);
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow! Cannot pop elements.");
        return;
    }
    printf("\nPopped Value :%d", stack[top--]);
}

void peek()
{
    if (top == -1)
    {
        printf("\nStack Underflow! Cannot display element.");
        return;
    }
    printf("\nTop of Stack :%d", stack[top]);
}

void display(void)
{
    if (top == -1)
    {
        printf("\nStack Underflow! No elements to display.\n");
        return;
    }
    printf("\nStack elements (top to bottom):\n\n");
    for (int i = top; i >= 0; --i)
    {
        printf("\t\t[%d]\n", stack[i]);
        if (i > 0)
            printf("\t\t |\n");
    }
    printf("\nSize of Stack: %d\n", top + 1);
}

void exitProgram()
{
    printf("\nProgram Terminated!\n");
    printf("\n-----------------------------------------\n");
    exit(0);
}