#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *link;
};


struct node *insert(struct node *p,int newelement)
{
struct node *temp;

if(p==NULL)
{
p=(struct node *)malloc(sizeof(struct node));

if(p==NULL)
{
printf("Memory couldnt be allocated ");
exit(0);
}
p->data=newelement;
p->link=p;
}
else
{
temp=p;
while(temp->link!=p)
temp=temp->link;
temp->link=(struct node *)malloc(sizeof(struct node));
if(temp->link==NULL)
{
printf("Memory couldnt be allocated");
exit(0);
}
temp=temp->link;
temp->data=newelement;
temp->link=p;
}
return (p);
}


void display(struct node *p)
{
struct node *temp;
temp =p;
if(p!=NULL)
{
do
{
printf("%d -> ",temp->data);
temp=temp->link;
}while(temp!=p);
}
else
{
printf("The list is empty\n");
}
}


struct node *merge(struct node *p,struct node *q)
{
struct node *temp=NULL;
struct node *r=NULL;
r=p;
temp=p;
while(temp->link!=p)
{
temp=temp->link;
}
temp->link=q;
temp=q;
while(temp->link!=q)
temp=temp->link;
temp->link=r;
return (r);
}

void search(struct node *p,int key)
{
struct node *temp;
temp=p;
int count=2;
if(temp->data==key)
{
printf("Element found at position 1");
}
else
{
temp=p->link;
while(temp->data!=key&&temp!=p)
{
temp=temp->link;
count++;
}
if(temp->data==key)
printf("Element found at position %d",count);
else
printf("Element not in the list");
}

}

void main()
{
int n,x,select;
struct node *list1= NULL;
struct node *list2=NULL;
struct node *list3=NULL;
printf("1. Insert element to list 1\n2. Insert elements to list 2\n3. Merge lists\n4. Search element in list 1\n5. Search element in list 2\n6. Exit");
while(1)
{
printf("\nEnter your choice : ");
scanf("%d",&select);
switch(select)
{
case 1:
printf("Enter element to be inserted to list 1: ");
scanf("%d",&n);
list1=insert(list1, n);
display(list1);
break;

case 2:
printf("Enter element to be inserted to list 2: ");
scanf("%d",&n);
list2=insert(list2, n);
display(list2);
break;

case 3:
list3=merge(list1,list2);
display(list3);
break;

case 4:
printf("Enter element to be searched : ");
scanf("%d",&x);
search(list1, x);
break;

case 5:
printf("Enter element to be searched : ");
scanf("%d",&x);
search(list2, x);
break;

case 6:
exit(0);
}
}
}