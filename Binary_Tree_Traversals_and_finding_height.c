/* Program Name : Binary Tree Height.
   Author  Name : Aryan Sajan Kulathinal.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//structure for binary tree.

typedef struct tree{
    struct tree*lc;
    struct tree*rc;
    int data;
}tree;

tree*root= NULL;
int n=0;

void create_tree();
void traversal();
void inorder();
void preorder();
void postorder();

void main(){

    int op=0;
    while(op!=3){
        printf("\nThe keys for the operarions are : \n");
        printf("Create a binary tree       : 1\n");
        printf("Traverse the binary tree   : 2\n");
        printf("EXIT                       : 3\n");
        printf("\nEnter the operation to be performed : ");
        scanf("%d",&op);
        switch(op){
            case 1 : create_tree(root,0);break;
            case 2 : traversal();break;
            case 3 : exit(0);
            default: printf("\nERROR!!!\n");
        }
    }
}

void create_tree(tree*ptr,int item){
    if(root==NULL){
        printf("\nEnter data to root of the tree : ");
        scanf("%d",&item);
        root=(tree*)malloc(sizeof(tree));
        root->data=item;
        ptr=root;
    }
    if(ptr!=NULL){
        char op,c;
        ptr->data=item;
        printf("Does the node %d have a left child(Y/N) : ",ptr->data);
        scanf("%c",&c);
        scanf("%c",&op);
        if(op=='y'){
            tree*lcptr=(tree*)malloc(sizeof(tree));
            ptr->lc=lcptr;
            printf("Enter the data to be entered into the left child : ");
            scanf("%d",&item);
            create_tree(lcptr,item);
        }
        else{
            ptr->lc=NULL;
        }
        printf("Does the node %d have a right child(Y/N) : ",ptr->data);
        scanf("%c",&c);
        scanf("%c",&op);
        if(op=='y'){
            tree*rcptr=(tree*)malloc(sizeof(tree));
            ptr->rc=rcptr;
            printf("Enter the data to be entered into the right child : ");
            scanf("%d",&item);
            create_tree(rcptr,item);

        }
        else{
            ptr->rc=NULL;
        }
    }
}

void traversal(){
    int key=0;
    printf("\nThe keys for the traversals are : \n");
    printf("Inorder   Traversal : 1\n");
    printf("Preorder  Traversal : 2\n");
    printf("Postorder Traversal : 3\n");
    printf("\nEnter the required key : ");
    scanf("%d",&key);
    switch(key){
        case 1 : printf("\nThe Inorder traversal is : \n");inorder(root);printf("\nThe no:of nodes in the tree = %d.",n);int h= log(n)/log(2);
                 printf("\nThe height of the tree = %d.",h);break;
        case 2 : printf("\nThe Preorder traversal is : \n");preorder(root);printf("\n");break;
        case 3 : printf("\nThe Postorder traversal is : \n");postorder(root);printf("\n");break;
        default: printf("\nERROR!!!\n");
    }
}

void inorder(tree*ptr){
    if(ptr==NULL){
        return;
    }
    inorder(ptr->lc);
    printf("%d",ptr->data);
    n=n+1;
    inorder(ptr->rc);
}

void preorder(tree*ptr){
    if(ptr==NULL){
        return;
    }
    printf("%d",ptr->data);
    preorder(ptr->lc);
    preorder(ptr->rc);
    
}

void postorder(tree*ptr){
    if(ptr==NULL){
        return;
    }
    postorder(ptr->lc);
    postorder(ptr->rc);
    printf("%d",ptr->data);
}

