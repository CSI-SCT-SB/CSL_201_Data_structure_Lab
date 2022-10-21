#include<stdio.h>
#include<stdlib.h>
struct node 
  {int DATA;
   struct node *LC,*RC;
  };
void display(struct node *ptr)
  {if(ptr!=NULL)
     {display(ptr->LC);
      printf("%d\t",ptr->DATA);
      display(ptr->RC);
     }
  }
struct node *create(int ITEM)
  {struct node *newnode=(struct node *)malloc(sizeof(struct node *));
   newnode->DATA=ITEM;newnode->LC=NULL;newnode->RC=NULL;
   return newnode;
  }
struct node *insert(struct node *root,int ITEM)
  {if(root==NULL)
      return create(ITEM);
   if(ITEM<root->DATA)
      root->LC=insert(root->LC,ITEM);
   else
      root->RC=insert(root->RC,ITEM);
   return root;
  }
struct node *succ(struct node *ptr)
    {struct node *ptr1=ptr->RC;
     if(ptr1!=NULL)
         while(ptr1->LC!=NULL)
              ptr1=ptr1->LC;
     return(ptr1);
    }
struct node * delete(struct node *ptr,int KEY)
   {int flag=0,option;struct node *parent,*ptr1;
    while(ptr!=NULL && flag==0)
        {if(KEY<ptr->DATA)
             {parent=ptr;
              ptr=ptr->LC;
             }
         else
             if(KEY>ptr->DATA)
                {parent=ptr;ptr=ptr->RC;}
             else
                 if(ptr->DATA==KEY)
                      flag=1;
        }
     if(flag==0)
        {printf("\nItem does not exist");return NULL;}
     if(ptr->LC==NULL && ptr->RC==NULL)
         option=1;
     else
        if(ptr->LC!=NULL && ptr->RC!=NULL)
            option=2;
        else
            option=3;
     switch(option)
         {case 1:if(parent->LC==ptr)
                     parent->LC=NULL; 
                 else
                     parent->RC=NULL;
                 free(ptr);break;
          case 2:ptr1=succ(ptr);
                 ptr->DATA=ptr1->DATA;
                 free(ptr1);break;
          case 3:if(parent->LC==ptr)
                    { if(ptr->LC==NULL)
                          parent->LC=ptr->RC;
                     else
                          parent->LC=ptr->LC;
                    }
                 else
                    {if(parent->RC==ptr)
                         if(ptr->LC==NULL)
                          parent->RC=ptr->RC;
                         else
                          parent->RC=ptr->LC;
                    }
                 free(ptr);break;
         }
}

void search(struct node *ptr,int ITEM)
  {int flag=0;
   while(ptr!=NULL && flag==0)
      {if(ITEM<ptr->DATA)
          ptr=ptr->LC;
       else
          if(ptr->DATA==ITEM)
             flag=1;
          else
             if(ITEM>ptr->DATA)
                   ptr=ptr->RC;
       }
   if(flag==1)
         printf("\nItem found");
   else
        printf("\nItem not found");
  }                      
    
       
int main()
  {struct node *root=NULL,*temp;int op,ITEM;
   root = insert(root, 10);  
   root = insert(root, 20);  
   root = insert(root, 7);  
   root = insert(root, 25);  
   root = insert(root, 35);  
   root = insert(root, 40);  
   root = insert(root, 16);  
   root = insert(root, 4);  
   root=insert(root,8);
   display(root);
   do
    {printf("\nMENU\n");
     printf("1.INSERT\t2.DELETE\t3.SEARCH\n");
     printf("Enter your choice: ");
     scanf("%d",&op);
     switch(op)
       {case 1:printf("\nEnter item to be inserted: ");
               scanf("%d",&ITEM);
               insert(root,ITEM);printf("\n");display(root);break;
        case 2:printf("\nEnter element to be deleted: ");
               scanf("%d",&ITEM);
               temp=delete(root,ITEM);printf("\n");display(root);break;
        case 3:printf("\nEnter item to be searched: ");
               scanf("%d",&ITEM);
               search(root,ITEM);printf("\n");display(root);break;
      }
     printf("\nDo you want to continue? 1/2: ");
     scanf("%d",&op);
    }while(op==1);
  return 0;
 }
