#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* top = NULL;

struct node* Push()
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element to be pushed into the stack:");
    scanf("%d",&new->data);
    new->next = top;
    top = new;
    return top;

}

struct node* Pop()
{
    if(top == NULL)
    {
        printf("\n*****STACK UNDERFLOW*****\n");
        return top; 
    }
    else
    {
        struct node* temp = top;
        printf("\nElement being popped is %d",temp->data);
        top = top->next;
        free(temp);
    }
    return top;
}

void Display()
{   
    if(top==NULL)
    {
        printf("\n*****EMPTY STACK*****\n");
    }
    else
    {
        printf("\nStack elements:\n");
        for(struct node* i = top; i != NULL; i=i->next)
        {
            printf("%d\t",i->data);
        }
    }
    
}

int main()
{   
    int flag = 0,choice;
    printf("\n*****IMPLEMENTATION OF STACK USING LINKED LISTS*****\n");
    
    while(flag==0)
    {
        printf("\n-----------------------------------------------------\n");
        printf("\nEnter your choice:\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Exit\nChoice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                top=Push(top);
                break;
            }
            case 2:
            {
                top=Pop(top);
                break;
            }
            case 3:
            {
                Display(top);
                break;
            }
            case 4:
            {
                flag=1;
                break;
            }
            default:
            {
                printf("\nINVALID CHOICE\n");
                break;
            }
        }
    }
    return 0;
}
