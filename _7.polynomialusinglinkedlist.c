#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,expo;
    struct node *link;
};

struct node *Phead,*Qhead,*Rhead;

struct node *ReadPoly()
{
    struct node *new,*ptr,*head=NULL;
    int n,i;
    
    printf("enter no of terms o polynomial");
    scanf("%d",&n);
    
    printf("enter the coefficients and exponents of the polynomial");
    for(i=1;i<=n;i++)
    {
        printf("enter (coef%d,expo%d)",i,i);
        new=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&new->coef);
        scanf("%d",&new->expo);
        new->link=NULL;
        if(head==NULL)
        {
            head=new;
            ptr=head;
        }
        else
        {
            ptr->link=new;
            ptr=new;
        }
    }
     return(head);
}
    
    void DisplayPoly(struct node *head)
    {
        struct node *ptr;
        if(head==NULL)
        printf("polynomial is empty");
        else
        {
            ptr=head;
            while(ptr->link !=NULL)
            {
                printf("%d x^%d +",ptr->coef,ptr->expo);
                ptr=ptr->link;
            }
            printf("%dx^%d \t",ptr->coef,ptr->expo);
        }
    }
    struct node *AddPoly()
    {
        struct node *new,*P,*Q,*R,*head=NULL;
        P=Phead;
        Q=Qhead;
        while(P!=NULL && Q!=NULL)
        {
            if(P->expo==Q->expo)
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coef=P->coef+Q->coef;
                new->expo=P->expo;
                new->link=NULL;
                P=P->link;
                Q=Q->link;
            }
            else if(P->expo>Q->expo)
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coef=P->coef;
                new->expo=P->expo;
                new->link=NULL;
                P=P->link;
            }
            else
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coef=Q->coef;
                new->expo=Q->expo;
                new->link=NULL;
                Q=Q->link;
            }
             if(head==NULL)
                {
                    head=new;
                    R=head;
                }
                else
                 {
                    R->link=new;
                    R=new;
                }
        }
        while(P!=NULL)
        {
            new=(struct node *)malloc(sizeof(struct node));
            new->coef=P->coef;
            new->expo=P->expo;
            new->link=NULL;
            if(head==NULL)
            {
                head=new;
                R=head;
            }
            else
            {
                R->link=new;
                R=new;
            }
            P=P->link;
        }
        while(Q!=NULL)
        {
            new=(struct node *)malloc(sizeof(struct node));
            new->coef=Q->coef;
            new->expo=Q->expo;
            new->link=NULL;
            if(head==NULL)
            {
                head=new;
                R=head;
            }
            else
            {
                R->link=new;
                R=new;
            }
            Q=Q->link;
        }
        return(head);
    }
    struct node *MulPoly()
    {
        struct node *new,*P,*Q,*R,*prev,*head=NULL;
        P=Phead;
        Q=Qhead;
        while(P!=NULL)
        {
            while(Q!=NULL)
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coef=P->coef*Q->coef;
                new->expo=P->expo+Q->expo;
                new->link=NULL;
                if(head==NULL)
                {
                    head=new;
                    R=head;
                }
                else
                {
                    R->link=new;
                    R=new;
                }
                Q=Q->link;
            }
            P=P->link;
            Q=Qhead;
        }
        
        P=head;
        
        while(P!=NULL)
        {
            prev=P;
            Q=P->link;
            while(Q!=NULL)
            {
                if(P->expo==Q->expo)
                {
                    P->coef=P->coef+Q->coef;
                    prev->link=Q->link;
                    free(Q);
                    Q=prev->link;
                }
                else
                {
                    prev=Q;
                    Q=Q->link;
                }
            }
            P=P->link;
        }
        return(head);
    }
    
    
    void main()
{
    //
    printf("enter details of first polynomaial \n");
    Phead=ReadPoly();
    
    //
     printf("enter details of second polynomaial \n");
     Qhead=ReadPoly();
     
     printf("\n First Polynomial: \n");
     DisplayPoly(Phead);
     printf("\n second Polynomial: \n");
     DisplayPoly(Qhead);
     
     //
     Rhead=AddPoly();
     printf("\n res poly (sum) : \n");
     DisplayPoly(Rhead);
     Rhead=MulPoly();
     printf("\n res poly (pro) : \n");
     DisplayPoly(Rhead);
}
    
        
    

