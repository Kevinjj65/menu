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
//Read two inputs representing two points in the Euclidean space, store these values in structure variables.
          //i) Compute the Euclidean distance between two pair of points.
          //ii) Find the sum of those two distance values.
#include <stdio.h>
#include <math.h>
typedef struct space{
	float x;
	float y;
	float z;
} space;
	
void main(){
	float d1, d2;
	space p[4];
	printf("\nEnter 4 Euclidean points ");
	for(int i=0; i<4;i++){
		printf("\nEnter value of point %d",i+1);
		printf("\nEnter X: ");
		scanf("%f",&p[i].x);
		printf("\nEnter Y: ");
		scanf("%f",&p[i].y);
		printf("\nEnter Z: ");
		scanf("%f",&p[i].z);
	}
	d1=sqrt(pow((p[0].x-p[1].x),2)+pow((p[0].y-p[1].y),2)+pow((p[0].z-p[1].z),2));
	printf("\n1. Distance between point 1 and point 2 is: %f",d1);
	d2=sqrt(pow((p[2].x-p[3].x),2)+pow((p[2].y-p[3].y),2)+pow((p[2].z-p[3].z),2));
	printf("\n2. Distance between point 3 and point 4 is: %f",d2);
	printf("\nTotal distance i.e distance 1 + distance 2 is: %f\n",d1+d2);
}
// Using  structure, read and print data of n employees (Name, Employee Id and Salary)
#include  <stdio.h>

typedef struct employe{
	char name[50];
	int id;
	int salary; 
}employe;

void main(){
	int n;
	printf("\nEnter number of employee data to br entered: ");
	scanf("%d",&n);
	employe emp[n];
	printf("\n....Enter Employe Data: ....");
	for(int i=0; i<n; i++){
		printf("\nEnter employee name: ");
		scanf("%s",emp[i].name);
		printf("Enter employee ID: ");
		scanf("%d",&emp[i].id);
		printf("Enter employee salary: ");
		scanf("%d",&emp[i].salary);
		printf("------------------\n");
	}
	printf("\n....The data you entered are: ....");
	for(int i=0; i<n; i++){
		printf("\n\tEnter employee name: %s",emp[i].name);
		printf("\n\tEnter employee ID: %d",emp[i].id);
		printf("\n\tEnter employee salary: %d",emp[i].salary);
		printf("\n------------------\n");
	}
//Declare a union containing 5 string variables (Name, House Name, City Name, State and  Pin code) each with a length of C_SIZE (user defined constant). Then, read and display the address of a person using a variable of the union.
#include <stdio.h>
#define C_SIZE 50
union  person{
	char name[C_SIZE];
	char house_name[C_SIZE];
	char city_name[C_SIZE];
	char state[C_SIZE];
	char pin_code[C_SIZE];
}pr;
void main(){
	printf("\nEnter name: ");
	scanf("%s",pr.name);
	printf("\tName:%s ",pr.name);
	printf("\n\nEnter house name: ");
	scanf("%s",pr.house_name);
	printf("\tHouse name:%s",pr.house_name);
	printf("\n\nEnter city name: ");
	scanf("%s",pr.city_name);
	printf("\tcity name:%s",pr.city_name);
	printf("\n\nEnter state: ");
	scanf("%s",pr.state);
	printf("\tState:%s",pr.state);
	printf("\n\nEnter pin code: ");
	scanf("%s",pr.pin_code);
	printf("\tpincode:%s\n",pr.pin_code);
}
