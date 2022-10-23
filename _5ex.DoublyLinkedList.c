#include <stdio.h>
#include <malloc.h>

//double linked list with head of type dlnode holding no data, whose Llink holds first actual dlnode
typedef struct dlnode{
  int data;
  struct dlnode *Llink;
  struct dlnode *Rlink;
}dlnode;

dlnode *getdlnode();
void dladdfront(dlnode *, int);
void dladdrear(dlnode *, int);
void dladdat(dlnode *, int, int);
int dlremfront(dlnode *);
int dlremrear(dlnode *);
int dlremat(dlnode *, int);
void dldisplay(dlnode *);

int main(){
  dlnode *head = getdlnode();
  int inp = 1, n, pos;
  while (inp != 0){
    printf("1: Display list \t2:Insert at front\n3: Insert at rear\t4: Insert at position\n");
    printf("5: Remove from front\t6: Remove from rear\n7: Remove from position\t0: Exit\nInput: ");
    scanf ("%d", &inp);
    switch (inp){
      case 1:
        printf("List: ");
        dldisplay(head);
        break;
      case 2:
        printf("Insert at front: ");
        scanf("%d", &n);
        dladdfront(head, n);
        break;
      case 3:
        printf("Insert at rear: ");
        scanf("%d", &n);
        dladdrear(head, n);
        break;
      case 4:
        printf("Insert: ");
        scanf("%d", &n);
        printf("At position: ");
        scanf("%d", &pos);
        dladdat(head, n, pos);
        break;
      case 5:
        printf("Removed %d from start\n", dlremfront(head));
        break;
      case 6:
        printf("Removed %d from end\n", dlremrear(head));
        break;
      case 7:
        printf("Position: ");
        scanf("%d", &pos);
        if (pos > 0)
          printf("Removed %d\n", dlremat(head, pos));
        else
          printf("Invalid position\n");
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

dlnode *getdlnode(){ //create a new node and return its address
  dlnode *node = (dlnode *) malloc(sizeof(dlnode));
  node->Rlink = NULL;
  node->Llink = NULL;
  return node;
}

void dladdfront(dlnode *head, int n){ //insert 'n' at the front of list
  dlnode *ptr;
  ptr = getdlnode();
  ptr->data = n;
  ptr->Llink = head->Llink;
  ptr->Rlink = head;
  if (head->Llink)  //check if this is first element
    (head->Llink)->Rlink = ptr;
  head->Llink = ptr;
}

void dladdrear(dlnode *head, int n){ //insert 'n' at the end of list
  dlnode *ptr, *new;
  ptr = head;
  while (ptr->Llink){
    ptr = ptr->Llink;
  }
  new = getdlnode();
  new->data = n;
  new->Rlink = ptr;
  ptr->Llink = new;
}

//pos == 1 => node right after head i.e. at start
void dladdat(dlnode *head, int n, int pos){ //insert 'n' at position 'pos' of list
  dlnode *ptr, *new;
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
    ptr = ptr->Llink;
  }
  new = getdlnode();
  new->data = n;
  new->Llink = ptr->Llink;
  new->Rlink = ptr;
  if (ptr->Llink)
    (ptr->Llink)->Rlink = new;
  ptr->Llink = new;
}

int dlremfront(dlnode *head){ //removes item from front of list
  if (head->Llink){
    dlnode *ptr;
    int n = (head->Llink)->data;
    ptr = head->Llink;
    if ((head->Llink)->Llink)
      head->Llink = (head->Llink)->Llink;
    (head->Llink)->Rlink = head;
    free(ptr);
    return n;
  }
  else{
    printf("List empty; deletion not possible. \n");
    return 0;
  }
}

int dlremrear(dlnode *head){ //removes item from rear of list
  if (head->Llink){
    dlnode *ptr;
    int n;
    ptr = head;
    while (ptr->Llink){
      ptr = ptr->Llink;
    }
    n = ptr->data;
    (ptr->Rlink)->Llink = NULL;
    free(ptr);
    return n;
  }
  else{
    printf("List empty; deletion not possible. \n");
    return 0;
  }
}

//note: position 0 and lower deletes the head
int dlremat(dlnode *head, int pos){ //removes item at position 'pos' of list
  dlnode *ptr;
  int n, i;
  ptr = head;
  for(i = 0; i < pos; i++){
    if (!ptr){
      printf("Invalid position; deletion not possible.\n");
      return 0;
    }
    ptr = ptr->Llink;
  }
  n = ptr->data;
  if (ptr->Llink){
    (ptr->Rlink)->Llink = ptr->Llink;
    (ptr->Llink)->Rlink = ptr->Rlink;
    free(ptr);
    return n;
  }
  else{
    (ptr->Rlink)->Llink = NULL;
    free(ptr);
    return n;
  }
}

void dldisplay(dlnode *head){ //displays the linked list
  dlnode *ptr = head->Llink;
  if (!ptr){
    printf("Empty\n");
  }
  while (ptr){
    printf("%d\t", ptr->data);
    ptr = ptr->Llink;
  }
  printf("\n");
}
