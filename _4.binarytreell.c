#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node{
       int data;
        struct Node * left;
         struct Node *right;
}*root;
struct Node *search(struct Node *r,int key)
{
  struct Node *x=NULL;
  if(r->data==key)
  {
    return(r);
  }
  else if(r->left!=NULL)
  {
    x=search(r->left,key);
  }
  if(x==NULL && r->right!=NULL)
  {
    x=search(r->right,key);
  }
  return(x);
}
struct Node *createnode()
{ int item;
 struct Node *temp;
 temp=(struct Node*)malloc(sizeof(struct Node));
 printf("Enter element to be inserted:-\n");//if no node insert -1
 scanf("%d",&item);
 if(item==-1)
 {return 0;
 }
 temp->data=item;
 printf("Enter left child of %d:-\n",item);
 temp->left=createnode();
  printf("Enter right child of %d:-\n",item);
 temp->right=createnode();
 return temp;
}

struct Node* parent(struct Node* r, struct Node* i)
{
  struct Node* x=NULL;
  if(r->left == i || r->right == i)
  {
    return(r);
  }
  else if(r->left != NULL)
  {
    x = parent(r->left,i);
  }
  if(x==NULL && r->right != NULL)
  {
    x=parent(r->right,i);
  }
  return(x);
}
void delete()
{
  int key,flag=0;
  printf("ENTER THE ELEMENT TO DELETE : ");
  scanf("%d",&key);
  struct Node* i = search(root,key);
  if(i!=NULL)
  {
    if((i->left==NULL)&&(i->right==NULL))
    {
      flag=1;
      struct Node *p = parent(root,i);
      if(p->left==i)
      {
        printf("%d DELETED \n",i->data);
        free(i);
        p->left=NULL;
      }
      else if(p->right==i)
      {
        printf("%d DELETED \n",i->data);
        free(i);
        p->right=NULL;
      }
    }
    else
    {
      printf("NODE CAN'T BE DELETED!!\n");
    }
  }
  else if((i==0)||(flag==0))
  {
    printf("NODE DOES NOT EXIST!\n");
  }
}

void preorder(struct Node *root)
{if(root==0)
  return;
  printf("%d\t",root->data);
  preorder(root->left);
  preorder(root->right);
}
void inorder(struct Node *root)
{if(root==0)
  return;
  inorder(root->left);
  printf("%d\t",root->data);
  inorder(root->right);
}
void postorder(struct Node *root)
{if(root==0)
  return;
  postorder(root->left);
  postorder(root->right);
  printf("%d\t",root->data);
}
void main()
{root=0;
int key,ch,c;
root=createnode();
 do
	{
		
		printf("\n\tMenu");
		printf("\n1.Insert a node");
		printf("\n2.Delete a node");
		printf("\n3. Preorder Traversal");
		printf("\n4. Inorder Traversal");
		printf("\n5. Postorder Traversal");
		printf("\n6. Exit");
		printf("\nEnter Your Choice : ");
		scanf("%d",&ch);
		

		switch(ch)
		{
			case 1:
		                root=createnode();
                                 
				break;
			case 2:
	        		 delete();
				break;
				case 3:  printf("Preorder traversal is:-\n");
				         preorder(root);
				         break;
                          
				case 4:  printf("Inorder traversal is:-\n");
				         inorder(root);
				         break;
			 case 5:  printf("Postorder traversal is:-\n");
				         postorder(root);
				         break;
				
			case 6:
			      
			      c=1;	
		}	
	}while(c!=1);
}
 

