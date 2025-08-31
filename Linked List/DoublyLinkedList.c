#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void createList();
void displayList();
void insertNode();
void deleteNode();
void searchNode();
void freeExit();

int main()
{
    int choice;
    printf("\n\t---Doubly Linked List---");
    while (1)
    {
        printf("\n1. Create \n2. Display \n3. Insert \n4. Delete\n5. Search\n6. Exit");
        printf("\n--------------------------------------\n Enter Your Choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createList();
            break;
        case 2:
            displayList();
            break;
        case 3:
            insertNode();
            break;
        case 4:
            deleteNode();
            break;
        case 5:
            searchNode();
            break;
        case 6:
            freeExit();
            break;
        default:
            printf("\nInvalid Input, Try Again!");
            break;
        }
        printf("\n--------------------------------------");
    }
    return 0;
}

void createList()
{
    struct node *temp = head, *newnode;

    while (head != NULL)
    {
        printf("\n\tPrevious List is Freed!");
        temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL;

    int length;
    printf("\n Enter Number of Nodes :");
    scanf("%d", &length);

    if (length <= 0)
    {
        printf("\n\tEnter a positive number\n");
        return;
    }
    for (int i = 1; i <= length; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("\nMemory Allocation Failed");
            return;
        }

        printf("\tEnter Data for Node %d: ", i);
        scanf("%d", &newnode->value);

        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    printf("\n\tLinked List created!\n");
}

void displayList()
{
    struct node *temp = head;
    int count = 0;

    if (head == NULL)
    {
        printf("\n\tList is Empty");
        return;
    }

    printf("\n List Elements: ");
    while (temp != NULL)
    {
        printf("[%d]<-> ", temp->value);
        count++;
        temp = temp->next;
    }
    printf("NULL\n Length of List : %d", count);
}

void insertNode()
{
    struct node *temp = head, *newnode;

    if (temp == NULL)
    {
        printf("\nList is Empty, Creating a new list!");
        createList();
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nMemory Allocation Failed");
        return;
    }

    printf("\nEnter Data for Node :");
    scanf("%d", &newnode->value);

    newnode->next = NULL;
    newnode->prev = NULL;

    int count = 0, pos;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    displayList();

    printf("\n\nEnter Position to insert node :");
    scanf("%d", &pos);

    if (pos <= 0 || pos > count + 1)
    {
        printf("\nEnter position within range!");
        return;
    }

    temp = head;
    if (pos == 1)
    {
        newnode->next = temp;
        temp->prev = newnode;
        head = newnode;
    }
    else if (pos == count + 1)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
    printf("\nValue %d inserted at postion %d successfully\n", newnode->value, pos);
    displayList();
}

void deleteNode()
{
    struct node *temp = head;

    if (temp == NULL)
    {
        printf("\nCan't Delete from an empty node!");
        return;
    }
    displayList();
    int pos, count = 0;
    printf("\nEnter Position to delete :");
    scanf("%d", &pos);

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (pos <= 0 || pos > count)
    {
        printf("\n Enter a valid position");
        return;
    }

    temp = head;
    if (pos == 1)
    {
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
    }
    else if (pos == count)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
    }
    printf("\nNode at position %d is deleted!\n", pos);
    displayList();
}

void searchNode()
{
    struct node *temp = head;
    int searchValue, count = 0;

    if (head == NULL)
    {
        printf("\nList is Empty!");
        return;
    }

    printf("\nEnter Value to Search :");
    scanf("%d", &searchValue);

    while (temp != NULL)
    {
        count++;
        if (temp->value == searchValue)
        {
            printf("\nValue %d found at position %d", searchValue, count);
            return;
        }
        temp = temp->next;
    }
    printf("\nValue not found inside the List");
}

void freeExit()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("\nProgram Executed!\n--------------------------------------");
        exit(0);
    }
    else
    {
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        printf("\nMemory Freed!");
        printf("\nProgram Executed!\n--------------------------------------");
        exit(0);
    }
}