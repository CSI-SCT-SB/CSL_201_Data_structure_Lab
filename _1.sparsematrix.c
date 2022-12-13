//program to depict sparse matrix representation
#include<stdio.h>
void main()
{
	int spmat[10][3],ar[10][10],m,n,k,i,j;
	printf("Enter number of rows and columns in matrix : ");
	scanf("%d%d",&m,&n);
	printf("Enter the matrix : ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&ar[i][j]);
		}
	k=0;
	spmat[0][0]=m;
	spmat[0][1]=n;
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
		if(ar[i][j]!=0)
		{
			k++;
			spmat[k][0]=i;
			spmat[k][1]=j;
			spmat[k][2]=ar[i][j];
			
		}
	}
	spmat[0][2]=k;
	printf("Sparse matrix representation is : \n");
	for(i=0;i<=k;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d    ",spmat[i][j]);
		}printf("\n");
	}
}