#include<stdio.h>
void enqueue(int* front, int* rear, int size, int* arr)
{
    int element,  begin, end;
    
    if((*rear+1)%size==*front)
    {
        printf("\nQUEUE FULL!\n");
    }
    else
    {
        printf("\nEnter the element to be inserted:");
        scanf("%d",&element);
        if(*rear==-1 && *front==-1)
        {
            *front=*front+1;
        }
        *rear=(*rear+1)%size;
        *(arr+*rear)=element;
    }
}
void dequeue(int* front, int* rear, int size, int* arr)
{
    if((*front==-1 && *rear==-1))
    {
        printf("\nQUEUE EMPTY!\n");
    }
    else
    {
        if(*front==*rear)
        {
            *front=-1;
            *rear=-1;
        }
        else
        {
            *front=(*front+1)%size;
        }
    }
}
void view(int* front, int* rear, int size, int* arr)
{
    int begin, end;
    begin=*front;
    end=*rear;
    if((*front==-1 && *rear==-1))
    {
        printf("\nQUEUE EMPTY!\n");
    }
    else
    {
        while ((begin)%size!=end)
        {
            begin=(begin)%size;
            printf("%d\t",*(arr+begin));
            begin++;
        }
        begin=(begin)%size;
        printf("%d\t",*(arr+begin));
        printf("\n");
    }
}
int main()
{
    printf("\nIMPLEMENTATION OF CIRCULAR QUEUE USING ARRAYS\n");
    int n, option, front=-1, rear=-1, flag=0;
    printf("\nEnter the size of the queue:");
    scanf("%d",&n);
    int arr[n];
    while(flag==0)
    {
        printf("---------------------------------------------------------------------");
        printf("\nChoose an option:\n1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\nCHOICE :");
        scanf("%d",&option);
        //printf("rear=%d\n",rear);
        switch (option)
        {
        case 1:
            enqueue(&front, &rear, n, arr);
            break;
        case 2:
            dequeue(&front, &rear, n, arr);
            break;
        case 3:
            view(&front, &rear, n, arr);
            break;
        case 4:
            flag=1;
            break;
        }
    }
}
