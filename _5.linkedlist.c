#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//singly linked list with head of type slnode holding no data, whose link holds first actual slnode
typedef struct slnode{
  int data;
  struct slnode *link;
}slnode;

slnode *getslnode();
void sladdfront(slnode *, int);
void sladdrear(slnode *, int);
void sladdat(slnode *, int, int);
int slremfront(slnode *);
int slremrear(slnode *);
int slremat(slnode *, int);
void sldisplay(slnode *);
int slrem(slnode *, int);
void sladdafter(slnode *, int, int);

int main(){
  slnode *head = getslnode();
  int inp = 1, n, pos;
  while (inp != 0){
    printf("1: Display list \t2: Insert at front\n3: Insert at rear\t4: Insert at position\n");
    printf("5: Remove from front\t6: Remove from rear\n7: Remove from position\t8: Remove\n9: Insert after\t\t0: Exit\nInput: ");
    scanf ("%d", &inp);
    switch (inp){
      case 1:
        printf("List: ");
        sldisplay(head);
        break;
      case 2:
        printf("Insert at front: ");
        scanf("%d", &n);
        sladdfront(head, n);
        break;
      case 3:
        printf("Insert at rear: ");
        scanf("%d", &n);
        sladdrear(head, n);
        break;
      case 4:
        printf("Insert: ");
        scanf("%d", &n);
        printf("At position: ");
        scanf("%d", &pos);
        sladdat(head, n, pos);
        break;
      case 5:
        printf("Removed %d from start\n", slremfront(head));
        break;
      case 6:
        printf("Removed %d from end\n", slremrear(head));
        break;
      case 7:
        printf("Position: ");
        scanf("%d", &pos);
        if (pos > 0)
          printf("Removed %d\n", slremat(head, pos));
        else
          printf("Invalid position\n");
        break;
      case 9:
         printf("Insert: ");
         scanf("%d", &n);
         printf("After: ");
         scanf("%d", &pos);
         sladdafter(head, n, pos);
         break;
      case 8:
         printf("Remove: ");
         scanf("%d", &n);
         slrem(head, n);
         break;
      case 0:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid input\n");
    }
    printf("---------------------------------------------\n");
  }
}

slnode *getslnode(){ //creates a node for the linked list
  slnode *node = (slnode *) malloc(sizeof(slnode));
  if (node){
    node->link = NULL;
    return node;
  }
  else{
    printf("\nInsufficient memory, Exiting...");
    exit(-1);
  }
}

void sladdfront(slnode *head, int n){ //inserts at front of linked list
  slnode *ptr;
  ptr = getslnode();
  ptr->data = n;
  ptr->link = head->link;
  head->link = ptr;
}

void sladdrear(slnode *head, int n){ //inserts at rear of linked list
  slnode *ptr, *new;
  ptr = head;
  while (ptr->link){
    ptr = ptr->link;
  }
  new = getslnode();
  new->data = n;
  ptr->link = new;
}

//pos == 1 => node right after head i.e. at start
void sladdat(slnode *head, int n, int pos){ //inserts at position pos of linked list
  slnode *ptr, *new;
  int i;
  ptr = head;
  if (!ptr){
    printf("Invalid position\n");
    return;
  }
  for (i = 1; i < pos; i++){
    if (!ptr){
      printf("Invalid position\n");
      return;
    }
    ptr = ptr->link;
  }
  new = getslnode();
  new->data = n;
  new->link = ptr->link;
  ptr->link = new;
}

int slremfront(slnode *head){ //deletes from front of linked list
  if (head->link){
    slnode *ptr;
    int n = (head->link)->data;
    ptr = head->link;
    head->link = (head->link)->link;
    free(ptr);
    return n;
  }
  else{
    printf("List empty; deletion not possible. \n");
    return 0;
  }
}

int slremrear(slnode *head){ //deletes from rear of linked list
  if (head->link){
    slnode *ptr, *ptr1;
    int n;
    ptr = head;
    while (ptr->link){
      ptr1 = ptr;
      ptr = ptr->link;
    }
    n = ptr->data;
    ptr1->link = NULL;
    free(ptr);
    return n;
  }
  else{
    printf("List empty; deletion not possible. \n");
    return 0;
  }
}

//note: position 0 and lower deletes the head
int slremat(slnode *head, int pos){ //deletes from position pos of linked list
  slnode *ptr, *ptr1;
  int n, i;
  ptr = head;
  ptr1 = head;
  for(i = 0; i < pos; i++){
    if (!ptr){
      printf("Invalid position; deletion not possible.\n");
      return 0;
    }
    ptr1 = ptr;
    ptr = ptr->link;
  }
  n = ptr->data;
  if (ptr->link){
    ptr1->link = ptr->link;
    free(ptr);
    return n;
  }
  else{
    ptr1->link = NULL;
    free(ptr);
    return n;
  }
}

void sldisplay(slnode *head){ //displays all the nodes of the linked list
  slnode *ptr = head->link;
  if (!ptr){
    printf("Empty\n");
  }
  while (ptr){
    printf("%d ", ptr->data);
    ptr = ptr->link;
  }
  printf("\n");
}

int slrem(slnode *head, int n){//removes node with data 'n' from linked list
   slnode *ptr, *ptr1;
   ptr = head->link;
   ptr1 = head;
   if (!ptr){
    printf("Number not found; deletion not possible.\n");
    return 0;
   }
   while(ptr->data != n){
     ptr1 = ptr;
     ptr = ptr->link;
     if (!ptr){
      printf("Number not found; deletion not possible.\n");
      return 0;
     }
   }
   ptr1->link = ptr->link;
   free(ptr);
   return n;
}

void sladdafter(slnode *head, int n, int key){//inserts 'n' after node with data 'key' in linked list
   slnode *ptr, *new;
   ptr = head->link;
   if (!ptr){
     printf("Number not found; No insertion\n");
     return;
   }
   while (ptr->data != key){
     ptr = ptr->link;
     if (!ptr){
       printf("Number not found; No insertion\n");
       return;
     }
   }
   new = getslnode();
   new->data = n;
   new->link = ptr->link;
   ptr->link = new;
}
