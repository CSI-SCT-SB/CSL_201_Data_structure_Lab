#include<stdio.h>

int main(){
    int i,n,x,A[10];
    printf(" Enter the no. of elements ");
    scanf("%d",&n);
    printf(" Enter the elements in ascending order ");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf(" Enter the element to be searched ");
    scanf("%d",&x);

    int l=0,h=n-1,mid =(l+h)/2,c=0;

    while(l<=h){
        mid = (l+h)/2;

        if(A[mid] == x){
            int p = mid;
            printf(" Search success. Element '%d' found at '%d'",A[mid],p+1);
            c++;
            break;

        }
        else
            if(A[mid]>x){
            h = mid - 1;
        }
        else
            l= mid + 1;

    }
      if(c==0){
        printf("Search Failed. Element NOT found ");
      }

 return 0;
}