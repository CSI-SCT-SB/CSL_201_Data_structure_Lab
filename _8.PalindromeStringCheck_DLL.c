#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structure definition
struct node
{
    char ch;
    struct node* next;
    struct node* prev;
};

//declaring a header and end pointer
struct node* header = NULL;
struct node* end = NULL;

//inserting character in the first position(if header is NULL)
void first_insert(char c)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->ch = c;
    new->prev = NULL;
    new->next=NULL;
    header = new;
    end = new;
}

//function to insert character after the first character
void insert_after_first(char c)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->ch = c;
    new->prev = end;
    new->next=NULL;
    end->next = new;
    end = new;
}


//function to check whether the input string is a palindrome
void check_palindrome()
{
    struct node* ptr1 = end;
    struct node* ptr=header;
    int flag=0;
    //iterating from the front and the back
    while(ptr!=NULL)
    {
        if(strcmp(&ptr->ch,&ptr1->ch)!=0)
        {
            flag=1;
            break;
        }
        ptr=ptr->next;
        ptr1=ptr1->prev;
    }
    if(flag==0)
    {
        printf("The entered string is palindrome!\n");
    }
    else
    {
        printf("The entered string is not a palindrome!\n");
    }
}

int main()
{
    char character;
    printf("Enter any string: ");
    while((character=getchar())!='\n')
    {
        if(header==NULL)
        {
            first_insert(character);
        }
        else
        {
            insert_after_first(character);
        }
    }
    check_palindrome();
    return 0;
}
