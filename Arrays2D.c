//  Arrays1DDemo.c
//  Nina Perone, 9/22/22, CIS2107 sec 002, tul44843
//  Lab 5 "Processing 2D Arrays": Write a C Program to design and implement functions to process 2D Arrays

#include <stdio.h>
#include <stdlib.h>

// prototypes
int max(int rows, int columns, int array[rows][columns]);
int rowSum(int rowNum, int columns, int array[][columns]);
int columnSum(int columnNum, int rows, int columns, int array[][columns]);
void isSquare(int rows, int columns);
void displayOutputs(int rows, int columns, int array[][columns]);

int main() {
    
    printf("Let's create a 2Dim array!\n");
    int rows;
    int columns;
    
    // gets user input for array size
    printf("\n\tHow many rows? ");
    scanf("%d", &rows);
    printf("\tHow many columns? ");
    scanf("\t%d", &columns);
    printf("\n");
    
    // user inputes each array item
    int nums[rows][columns];
    int value;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("\tenter [%d][%d]: ", i, j);
            scanf("%d", &value);
            nums[i][j] = value;
        }
        
    }

    // calls + prints max function
    printf("\nMax value = %d\n", max(rows, columns, nums));
    
    // calls + prints rowSum function for each row
    for(int i = 0; i < rows; i++) {
        printf("\nSum of row %d = %d", i+1, rowSum(i, columns, nums));
    }
    printf("\n");
    
    // calls + prints columnSum function for each column
    for(int i = 0; i < columns; i++) {
        printf("\nSum of column %d = %d", i+1, columnSum(i, rows, columns, nums));
    }
    printf("\n");
    
    // calls isSquare function
    isSquare(rows, columns);
    
    // calls displayOutput function
    displayOutputs(rows, columns, nums);
    
    printf("\n");
    exit(0);

}

// returns max value in array
int max(int rows, int columns, int array[rows][columns]) {
    int max = array[0][0];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    return max;
}

// returns sum of values in particular row
int rowSum(int rowNum, int columns, int array[][columns]) {
    int sum = 0;
    for(int i = 0; i < columns; i++) {
        sum += array[rowNum][i];
    }
    return sum;
}

// returns sum of values in particular row
int columnSum(int columnNum, int rows, int columns, int array[][columns]) {
    int sum = 0;
    for(int i = 0; i < rows; i++) {
        sum += array[i][columnNum];
    }
    return sum;
}

// prints if array row and column size are equal
void isSquare(int rows, int columns) {
    if(rows == columns) {
        printf("\nThis is a square array.\n");
    } else {
        printf("\nThis is not a square array.\n");
    }
}

// prints entire array
void displayOutputs(int rows, int columns, int array[][columns]) {
    printf("\nHere is your 2Dim array:\n");
    for(int i = 0; i < rows; i++) {
        printf("[");
        for(int j = 0; j < columns; j++) {
            printf("%d", array[i][j]);
            if(j != columns-1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}


