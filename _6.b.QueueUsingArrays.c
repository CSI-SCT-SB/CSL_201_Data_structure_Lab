#include<stdio.h>
void enqueue(int* front, int* rear, int size, int* arr)
{
    int element,  begin, end;
    
    if(*rear==size-1)
    {
        printf("\nQUEUE FULL!\n");
    }
    else
    {
        printf("Enter the element to be inserted:");
        scanf("%d",&element);
        if(*rear==-1 && *front==-1)
        {
            *front=*front+1;
        }
        *rear=*rear+1;
        *(arr+*rear)=element;
    }
}
void dequeue(int* front, int* rear, int size, int* arr)
{
    if((*front==-1 && *rear==-1) || *front>*rear)
    {
        printf("\nQUEUE EMPTY!\n");
    }
    else
    {
        *front=*front+1;
    }
}
void view(int* front, int* rear, int size, int* arr)
{
    int begin, end;
    begin=*front;
    end=*rear;
    if((*front==-1 && *rear==-1) || *front>*rear)
    {
        printf("\nQUEUE EMPTY!\n");
    }
    else
    {
        while (begin<=end)
        {
            printf("%d\t",*(arr+begin));
            begin++;
        }
        printf("\n");
    }
}
int main()
{
    printf("\n*****IMPLEMENTATION OF QUEUE USING ARRAYS*****\n");
    int n, option, front=-1, rear=-1, flag=0;
    printf("Enter the size of the queue:");
    scanf("%d",&n);
    int arr[n];
    while(flag==0)
    {
        printf("-----------------------------------------------------------");
        printf("\nChoose an option:\n1.Enqueue\t2.Dequeue\t3.Display.\t4.Exit\nCHOICE :");
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
