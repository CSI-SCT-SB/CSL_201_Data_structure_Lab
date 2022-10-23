#include<stdio.h>

int main(){
    int i,n,x,A[10];
    printf(" Enter the no. of elements: ");
    scanf(" %d", &n);
    printf(" Enter the elements: ");
    for (i = 0; i < n; i++){
      scanf(" %d", &A[i]);
    }
    printf(" Enter the element to be searched: ");
      scanf(" %d",&x);
      int c=0;
      for (i = 0; i <= n ; i++){
        if(A[i]==x){
          printf(" Element '%d' is found at position '%d' ", x, i+1);
          c++;

        }


      }

     if(c==0) printf(" Element '%d' NOT found",x);
     return 0;
}