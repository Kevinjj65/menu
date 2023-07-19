#include<stdio.h>
void read(int x[5][5], int y[5][5], int r, int c, char abc);
void transpose(int x[5][5], int y[5][5], int r, int c, int *r3, int *c3, char abc);
void display(int x[5][5], int r3, int c3);
void sum(int z[5][5], int x[5][5], int r1, int c1, int y[5][5], int r2, int c2, int *r3, int *c3);
void product(int z[5][5], int x[5][5], int r1, int c1, int y[5][5], int r2, int c2, int *r3, int *c3);
void main()
{
    int a[5][5], b[5][5], res[5][5], r1, c1, r2, c2, r3, c3, menu, n=1, m=1;
    char cont, rst, name;
    while(n==1)
    {
        if(m==1)
        {
            printf("Enter the dimensions of the Matrix A:\n");
            scanf("%d%d", &r1, &c1);
            read(a,res,r1,c1,'A');
            printf("Enter the dimensions of the second Matrix B:\n");
            scanf("%d%d", &r2, &c2);
            read(b,res,r2,c2,'B');
        }
        printf("MATRIX OPERATIONS:\n");
        printf("Menu: Transpose(1), Sum(2), Product(3), Display(4)\nEnter the function required\n");
        scanf("%d", &menu);
        if((menu>0)&&menu<4)
        {
            if(menu==1)
            {
                transpose(a,res,r1,c1,&r3,&c3,'A');
                display(res,r3,c3);
                transpose(b,res,r2,c2,&r3,&c3,'B');
                display(res,r3,c3);
            }
            else if(menu==2)
            {
                if((r1==r2)&&(c1==c2))
                {
                    sum(res,a,r1,c1,b,r2,c2,&r3,&c3);
                    display(res,r3,c3);
                }
                else
                    printf("ERROR: Dimensions not same!\nMatrices cannot be added\n");
            }
            else
            {
                if(c1==r2)
                {
                    product(res,a,r1,c1,b,r2,c2,&r3,&c3);
                    display(res,r3,c3);
                }
                else
                    printf("ERROR: No. of Columns of first matrix not equal to No. of Rows of second matrix!\nMatrices cannot be multiplied\n");
            }

        }
        else if(menu==4)
        {
                printf("Matrix A\n");
                display(a,r1,c1);
                printf("Matrix B\n");
                display(b,r2,c2);
        }
        else
            printf("ERROR: Not defined\n");

            printf("Do you want to continue?(Y/N)");
            scanf("\n%c", &cont);
            if(cont == 'Y'||cont == 'y')
            {
                printf("Do you want to reset data?(Y/N)");
                scanf("\n%c", &rst);
                if(rst=='Y'||rst=='y')
                    m=1;
                else
                    m=2;
            }
            else
                n++;

    }

}
void read(int x[5][5], int y[5][5], int r, int c, char abc)
{
    int i, j;
    printf("Enter the matrix %c:\n", abc);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("(%d,%d)=", i+1, j+1);
            scanf("%d", &x[i][j]);
            y[i][j]=x[i][j];
        }
    }
}
void display(int x[5][5], int r3, int c3)
{
    int i, j;
    printf("Displaying Resultant Matrix:\n");
    for(i=0;i<r3;i++)
    {
        for(j=0;j<c3;j++)
        {
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void transpose(int x[5][5], int y[5][5], int r, int c, int *r3, int *c3, char abc)
{
    int i, j;
    printf("Transpose of %c\n", abc);
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            y[i][j]=x[j][i];
        }
    }
    *r3=i;
    *c3=j;
}
void sum(int z[5][5], int x[5][5], int r1, int c1, int y[5][5], int r2, int c2, int *r3, int *c3)
{
    int i,j;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                z[i][j]=x[i][j]+y[i][j];
            }
        }
        *r3=i;
        *c3=j;
}
void product(int z[5][5], int x[5][5], int r1, int c1, int y[5][5], int r2, int c2, int *r3, int *c3)
{
    int i, j, k;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                z[i][j]=0;
                for(k=0;k<c1;k++)
                    z[i][j]+=x[i][k]*y[k][j];
            }
        }
        *r3=i;
        *c3=c2;
}
