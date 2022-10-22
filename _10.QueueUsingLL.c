#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;

struct node* enqueue()
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted:");
    scanf("%d",&new->data);
    if(rear == NULL)                    //insertion to an empty queue
    {
        front = new;
        rear = new;
        return 0 ;
    }
    rear->next = new;
    rear = new;
    return 0;
    //return rear;
}

struct node* dequeue()
{
    if(front == NULL)                             // empty queue
        printf("\n**EMPTY QUEUE**\n");
    else
    {
        struct node* ptr = front;
        if(front->next == NULL)                   //single element in queue
        {
            front = NULL;
            rear = NULL;
            free(ptr);
        }
        else
        {
            front = front->next;
            free(ptr);
        }
    }
    return 0;
    //return front;
}

void Display ()
{
    if(front == NULL)
    {
        printf("\n**EMPTY QUEUE**\n");
        return ;
    }    
    printf("\nQUEUE ELEMENTS:\n");
    for(struct node* i=front; i!=NULL;i=i->next)
    {
        printf("%d\t",i->data);
    }
}

int main()
{   
    int flag = 0,choice;
    printf("\n**IMPLEMENTATION OF QUEUE USING LINKED LISTS**\n");
    
    while(flag==0)
    {
        printf("\n-----------------------------------------------------\n");
        printf("\nEnter your choice:\n\t1.ENQUEUE\n\t2.DEQUEUE\n\t3.Display\n\t4.Exit\nChoice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                enqueue();
                //rear=enqueue();
                break;
            }
            case 2:
            {
                dequeue();
                //front=dequeue();
                break;
            }
            case 3:
            {
                Display();
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
