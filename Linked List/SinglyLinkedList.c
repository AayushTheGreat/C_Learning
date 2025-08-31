#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *nxt;
};

struct node *head = NULL;

void createList();
void displayList();
void insert();
void deleteNode();
void freeExit();
void searchNode();

int main()
{
    int choice;
    printf("\n\t---SINGLY LINKED LIST---");
    while(1){
        printf("\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Search\n6. Exit\n\n Enter your Choice :");
        scanf("%d",&choice);
        printf("--------------------------------------");

        switch (choice)
        {
        case 1: createList(); break;
        case 2: displayList(); break;
        case 3: insert(); break;
        case 4: deleteNode(); break;
        case 5: searchNode(); break;
        case 6: freeExit(); break;
        default: printf("\nINVALID INPUT!\n"); break;
        }
    }
    return 0;
}

void searchNode(){
    struct node *temp = head;
    int searchValue, pos = 0;

    if(head == NULL){
        printf("\n\tList is empty!");
        printf("\n--------------------------------------");
        return;
    }
    
    printf("\nEnter value to search :");
    scanf("%d",&searchValue);

    while (temp != NULL){
        pos++;
        if (temp->value == searchValue){
            printf("\n\tValue %d found at postion :%d",searchValue, pos);
            printf("\n--------------------------------------");
            return;
        }
        temp = temp->nxt;
        
    }
    printf("\n\tValue %d not found inside List",searchValue);
    printf("\n--------------------------------------");
    return;
}

void createList(){
    struct node *temp = head, *newnode;
    
    while(head != NULL){
        temp = head;
        head = head->nxt;
        free(temp);
    }
    head = NULL;

    int num, i;
    printf("\nEnter Number of Nodes :");
    scanf("%d",&num);
    if(num < 1){
        printf("\nInvalid input!\n");
        return;
    }
    for (i = 1; i <= num; i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL){
            printf("Memory Allocation Failed!\n");
            return;
        }

        printf(" Data for Node %d: ", i);
        scanf("%d",&newnode->value);

        newnode->nxt = NULL;

        if(head == NULL){
            head = temp = newnode;
        }else{
            temp->nxt = newnode;
            temp = newnode;
        }
    }
    printf("\n\tLinked List created!\n");
    printf("--------------------------------------");
}

void insert(){
    struct node *temp, *newnode;
    int pos, value, count = 0;

    if (head == NULL){
        printf("\n\tNo list is created, Please create a list first\n");
        createList();
        return;
    }
    temp = head;
    while (temp != NULL){
        count++;
        temp = temp->nxt;
    }
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL){
            printf("\n\tMemory Allocation Failed!");
            return;
        }  
    printf("\n Data for Node : ");
    scanf("%d",&newnode->value);

    newnode->nxt = NULL;

    printf("\n Enter position to insert :");
    scanf("%d",&pos);
    if (pos < 1 || pos > count + 1){
        printf("\nEnter position within range!\n");
        return;        
    }
    if ( pos == 1){
        newnode->nxt = head;
        head = newnode;
    } else {
        for ( int i = 1; i < pos - 1; i++){
            temp = temp->nxt;
        }
        newnode->nxt = temp->nxt;
        temp->nxt = newnode;
    }
    printf("\n\tInserted at postion %d with value %d successfully!\n",pos,newnode->value);
    printf("\n--------------------------------------");
    displayList();
}

void deleteNode(){
    struct node *temp;
    int count = 0, pos;
    temp = head;
    if (temp == NULL){
        printf("\n\tList is Empty\n");
        return;
    }
    while (temp != NULL){
        count++;
        temp = temp->nxt;
    }
    displayList();
    temp = head;
    printf("\n Enter Position to Delete node :");
    scanf("%d",&pos);
    if (pos < 1 || pos > count){
        printf("\n\tEnter value within range.\n");
        return;
    }
    if (pos == 1){
        head = head->nxt;
        printf("\n Value deleted : %d",temp->value);
        free(temp);
    } else if ( pos == count )
    {
        for ( int i = 1; i < pos - 1; i++){
            temp = temp->nxt;
        }
        printf("\n Value deleted : %d",temp->nxt->value);
        free(temp->nxt);
        temp->nxt = NULL;
    }
    else
    {   
        struct node *remove = NULL;
        for ( int i = 1; i < pos - 1; i++){
            temp = temp->nxt;
        }
        remove = temp->nxt;
        temp->nxt = temp->nxt->nxt;
        printf("\n Value deleted : %d", remove->value);
        free(remove);
    }
    printf("\n--------------------------------------");
    displayList();
}

void displayList(){
    struct node *temp;
    int count = 0;

    temp = head;

    if (temp == NULL){
        printf("\n\tList is Empty\n");
        return;
    }
    
    printf("\n\t");
    while (temp != NULL)
    {
        count++;
        printf("[%d]-> ",temp->value);
        temp = temp->nxt;
    }
    printf("[NULL]\n\n\tLength of list : %d",count);
    printf("\n--------------------------------------");
}

void freeExit(){
    struct node *temp;
    if(head == NULL){
        printf("\n--------------------------------------");
        exit(0);
    } else{
        while (head != NULL){
            temp = head;
            head = head->nxt;
            free(temp);
        }
        printf("\n\tMemory Freed!");
        printf("\n--------------------------------------");
        exit(0);
    }
}