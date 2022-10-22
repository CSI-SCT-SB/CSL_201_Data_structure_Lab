import java.util.Scanner;
public class Main {
   public static void main(String args[]) {
        int m1,n1,m2,n2;
        Scanner reader = new Scanner(System.in);
        System.out.printf("Enter the number of rows of first matrix:");
        m1=reader.nextInt( );
        System.out.printf("Enter the number of coloumns of first matrix:");
        n1=reader.nextInt( );
        System.out.printf("Enter the number of rows of second matrix:");
        m2=reader.nextInt( );
       System.out.printf("Enter the number of coloumns of second matrix:");
       n2=reader.nextInt( );
       int a[ ] [ ] = new int [m1] [n1];
        int b[ ] [ ] = new int [m2] [n2];
        int c[ ] [ ] = new int [m1] [n2];
       if(n1!=m2) {
            System.out.printf("Matrix multiplication not possible");
        }
        else {
            System.out.println("Enter the elements of first matrix:");
            for(int i=0;i<m1;i++) {
               for(int j=0;j<n1;j++) {
                    a [ i ] [ j ] = reader.nextInt( );
                }
            }
            System.out.println("Enter the elements of second matrix:");
            for(int i=0;i<m2;i++) {
                for(int j=0;j<n2;j++) {
                    b [ i ] [ j ] = reader.nextInt( );
               }
            }
            for(int i=0;i<m1;i++) {
               for(int j=0;j<n2;j++) {
                    c [ i ] [ j ] = 0;
                   for(int k=0;k<n1;k++) {
                        c [ i ] [ j ] = c [ i ] [ j ] + ( a [ i ] [ k ] * b [ k ] [ j ] );
                   }
                }
            }
            System.out.println("The multiplied matrix is:");
            for(int i=0;i<m1;i++) {
                for(int j=0;j<n2;j++) {
                    System.out.printf(c [ i ] [ j ] + "\t");
               }
                System.out.println();
            }
        }
    }
}