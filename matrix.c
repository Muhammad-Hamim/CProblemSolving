#include <stdio.h>
void inputMatrix(int size, int matrix[size][size]);
void printMatrix(int size, int matrix[size][size]);
void rotateRight(int size, int matrix[size][size]);
void rotateLeft(int size, int matrix[size][size]);
void shiftUp(int size, int matrix[size][size]);
void shiftDown(int size, int matrix[size][size]);

int main()
{
    int size, choice;
    char continue_choice;
    printf("Enter the size of matrix: ");
    scanf("%d", &size);
    if(size<2){
        printf("Size should be greater than 1.\n");
        printf("Enter a valid size: ");
        scanf("%d", &size);
    }
    int matrix[size][size];
    inputMatrix(size, matrix);

do{
   do{
        printf("Choose an operation:\n");
        printf("1. Rotate the matrix to Right\n");
        printf("2. Rotate the matrix to Left\n");
        printf("3. Shit up the matrix\n");
        printf("4. Shit down the matrix\n");
        printf("Enter the matrix operation(Eg: 1): ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            rotateRight(size, matrix);
            break;
        case 2:
            rotateLeft(size, matrix);
            break;
        case 3:
            shiftUp(size, matrix);
            break;
        case 4:
            shiftDown(size, matrix);
            break;
        default:
            printf("Invalid choice. Please enter between 1 to 4.\n");
            break;
        }
    } while (choice <1 && choice >5);
        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &continue_choice);
    } while (continue_choice == 'y' || continue_choice == 'Y');
    

    return 0;
}

void rotateRight(int size, int matrix[size][size]){
    int temp[size][size];
    for (int i = 0; i < size; i++){ // rows
        for (int j = 0; j < size; j++){ // columns
            temp[j][i] = matrix[size - 1 - i][j];
            /*
            for a 3x3 matrix
            1. first column of the rotated matrix will be the last row
            (new matrix)[0][0]=>[2][0]
            (new matrix)[1][0]=>[2][1]
            (new matrix)[2][0]=>[2][2]
            2. 2nd column of the new rotated matrix will be the 2nd last row
            (new matrix)[0][1]=>[1][0]
            (new matrix)[1][1]=>[1][1]
            (new matrix)[2][1]=>[1][2]
            3. 3rd column of the new rotated matrix will be the 3rd last row
            (new matrix)[0][2]=>[0][0]
            (new matrix)[1][2]=>[0][1]
            (new matrix)[2][2]=>[0][2]
            */
        }
    }
    printf("Rotated matrix: \n");
    printMatrix(size, temp);
}

void rotateLeft(int size, int matrix[size][size]){
    int temp[size][size];

    for (int i = 0; i < size; i++){ // rows
        for (int j = 0; j < size; j++){ // columns
            temp[i][j] = matrix[j][size - 1 - i];
            /*
            for a 3x3 matrix
            1. first row of the rotated matrix will be the last column
            (new matrix)[0][0]=>[0][2]
            (new matrix)[0][1]=>[1][2]
            (new matrix)[0][2]=>[2][2]
            2. 2nd row of the new rotated matrix will be the 2nd last column
            (new matrix)[1][0]=>[0][1]
            (new matrix)[1][1]=>[1][1]
            (new matrix)[1][2]=>[2][1]
            3. 3rd row of the new rotated matrix will be the 3rd last column
            (new matrix)[2][0]=>[0][0]
            (new matrix)[2][1]=>[1][0]
            (new matrix)[2][2]=>[2][0]
            */
        }
    }
    printf("Rotated matrix: \n");
    printMatrix(size, temp);
}

void shiftUp(int size, int matrix[size][size])
{
    int temp[size][size];
    for (int i = 0; i < size; i++){ // rows
        for (int j = 0; j < size; j++){ // columns
            if (i + 1 >= size){
                temp[size - 1][j] = matrix[0][j]; // last row becomes first row of the new matrix
            }else{
                temp[i][j] = matrix[i + 1][j]; // the first row gradually shifted down one by one
            }
        }
    }
    printf("Up shifted matrix: \n");
    printMatrix(size, temp);
}

void shiftDown(int size, int matrix[size][size]){
    int temp[size][size];
    for (int i = 0; i < size; i++){ // rows
        for (int j = 0; j < size; j++){ // columns
            if (i+1 >= size){
                temp[0][j] = matrix[size-1][j]; // last row becomes first row of the new matrix
            }else{
                temp[i+1][j] = matrix[i][j]; // the last row will gradually shifted up one by one
            }
        }
    }
    printf("Down shifted matrix: \n");
    printMatrix(size, temp);
}

void inputMatrix(int size, int matrix[size][size]){
    printf("Enter elements of the %dx%d matrix row-wise: ", size,size);
    for (int i = 0; i < size; i++){ // rows
        for (int j = 0; j < size; j++){ // column
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original Matrix:\n");
    printMatrix(size, matrix);
}

void printMatrix(int size, int matrix[size][size]){
    for (int i = 0; i < size; i++){ // rows
        for (int j = 0; j < size; j++){ // columns
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); // after printing one row it'll start new line/row
    }
}