include<stdio.h>
#define MAX_DEGREE 100
void inputpoly(int poly[],int deg)
{
 printf("enter the coefficient\n");
 for(int i=0;i<=deg;i++)
{
 printf("coefficient of x^%d",i);
 scanf("%d",&poly[i]);
}
}
void addpoly(int a[], int b[],int c[], int deg)
{
 for(int i=0;i<=deg;i++)
 {
 c[i]=a[i]+b[i];
 }
}
void displaypoly(int poly[],int deg)
{
 for(int i=0;i<=deg;i++)
{
 if(poly[i]!=0)
 {
 if(i==0)
 printf("%d",poly[i]);
 else
 printf("%+dx^%d",poly[i],i);
}
}
printf("\n");
}
int main()
{
 int deg;
 printf("enter the degree of the poly\n");
 scanf("%d",&deg);
 int a[MAX_DEGREE+1]={0};
 int b[MAX_DEGREE+1]={0};
 int c[MAX_DEGREE+1]={0};
 int choice;
 do
 {
  printf("\nMENU\n");
  printf("1. enter the first poly (a)\n");
  printf("2. enter the second poly (b)\n");
  printf("3.  add poly a and b\n");
  printf("4. display poly c\n");
  printf("5. exit\n");
  printf("enter the choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
    inputpoly(a,deg);
    break;
   case 2:
    inputpoly(b,deg);
    break;
   case 3:
    addpoly(a,b,c,deg);
    break;
   case 4:
    displaypoly(c,deg);
    break;
   case 5:
     printf("exiting");
     break;
   default:
     printf("invalid choice");
}
}
while (choice != 5);
return 0;
}



#include <stdio.h>

// Structure to represent a sparse matrix element
struct SparseMatrixElement {
    int row;
    int col;
    int value;
};

// Function to input a sparse matrix
void inputSparseMatrix(struct SparseMatrixElement matrix[], int *rows, int *cols) {
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", rows, cols);

    printf("Enter the number of non-zero elements: ");
    int numNonZero;
    scanf("%d", &numNonZero);

    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < numNonZero; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
}

// Function to display a sparse matrix
void displaySparseMatrix(struct SparseMatrixElement matrix[], int rows, int cols) {
    int k = 0; // Index for accessing the non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[k].row == i && matrix[k].col == j) {
                printf("%d ", matrix[k].value);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to add two sparse matrices
void addSparseMatrices(struct SparseMatrixElement matrix1[], struct SparseMatrixElement matrix2[],
                       struct SparseMatrixElement result[], int rows, int cols) {
    int k = 0, l = 0, m = 0; // Indexes for accessing non-zero elements
    while (k < rows * cols) {
        if (matrix1[l].row == matrix2[m].row && matrix1[l].col == matrix2[m].col) {
            result[k].row = matrix1[l].row;
            result[k].col = matrix1[l].col;
            result[k].value = matrix1[l].value + matrix2[m].value;
            k++;
            l++;
            m++;
        } else if (matrix1[l].row < matrix2[m].row || (matrix1[l].row == matrix2[m].row && matrix1[l].col < matrix2[m].col)) {
            result[k].row = matrix1[l].row;
            result[k].col = matrix1[l].col;
            result[k].value = matrix1[l].value;
            k++;
            l++;
        } else {
            result[k].row = matrix2[m].row;
            result[k].col = matrix2[m].col;
            result[k].value = matrix2[m].value;
            k++;
            m++;
        }
    }
}

// Function to transpose a sparse matrix
void transposeSparseMatrix(struct SparseMatrixElement matrix[], struct SparseMatrixElement transpose[],
                           int rows, int cols) {
    int count[cols];
    int startPosition[cols];

    for (int i = 0; i < cols; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i * cols + j].value != 0) {
                count[j]++;
            }
        }
    }

    startPosition[0] = 0;
    for (int i = 1; i < cols; i++) {
        startPosition[i] = startPosition[i - 1] + count[i - 1];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i * cols + j].value != 0) {
                int index = startPosition[j]++;
                transpose[index].row = j;
                transpose[index].col = i;
                transpose[index].value = matrix[i * cols + j].value;
            }
        }
    }
}

int main() {
    struct SparseMatrixElement matrix1[100], matrix2[100], result[100], transpose[100];
    int rows1, cols1, rows2, cols2;

    int choice;
    do {
        printf("\nSparse Matrix Operations Menu:\n");
        printf("1. Input Sparse Matrix 1\n");
        printf("2. Input Sparse Matrix 2\n");
        printf("3. Display Sparse Matrix 1\n");
        printf("4. Display Sparse Matrix 2\n");
        printf("5. Add Sparse Matrices\n");
        printf("6. Transpose Sparse Matrix 1\n");
        printf("7. Transpose Sparse Matrix 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputSparseMatrix(matrix1, &rows1, &cols1);
                break;
            case 2:
                inputSparseMatrix(matrix2, &rows2, &cols2);
                break;
            case 3:
                printf("\nSparse Matrix 1:\n");
                displaySparseMatrix(matrix1, rows1, cols1);
                break;
            case 4:
                printf("\nSparse Matrix 2:\n");
                displaySparseMatrix(matrix2, rows2, cols2);
                break;
            case 5:
                if (rows1 == rows2 && cols1 == cols2) {
                    addSparseMatrices(matrix1, matrix2, result, rows1, cols1);
                    printf("\nResultant Sparse Matrix (Sum):\n");
                    displaySparseMatrix(result, rows1, cols1);
                } else {
                    printf("\nMatrix dimensions are not compatible for addition.\n");
                }
                break;
            case 6:
                transposeSparseMatrix(matrix1, transpose, rows1, cols1);
                printf("\nTranspose of Sparse Matrix 1:\n");
                displaySparseMatrix(transpose, cols1, rows1);
                break;
            case 7:
                transposeSparseMatrix(matrix2, transpose, rows2, cols2);
                printf("\nTranspose of Sparse Matrix 2:\n");
                displaySparseMatrix(transpose, cols2, rows2);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}
