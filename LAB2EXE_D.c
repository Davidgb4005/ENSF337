/*
 *  lab2exe_D.c
 *  ENSF 337, lab2 Exercise D
 *
 *  In this program the implementatiom of function pascal_trangle is missing.
 *  Studtent must complete this function.
 */

#include <stdio.h>
#include <stdlib.h>

void pascal_triangle(int n);
/*
Requires
    a pass variable as an int > 0
Promises
    Print the values of the binomeal coefcients of the formula (a+b)^n
*/

int main() {
    int nrow;
    // These are ALL of the variables you need!
    printf("Enter the number of rows (Max 20): ");
    scanf("%d", &nrow);
    if(nrow <= 0 || nrow > 20) {
        printf("Error: the maximum number of rows can be 20.\n");
        exit(1);
    }
    
    pascal_triangle(nrow);
    return 0;
}

void pascal_triangle(int n) {
    // Arrays to hold the values of Pascal's triangle
    int pascal_upper_array[20] = {0, 1};
    int pascal_lower_array[20] = {0, 1};
    n = n+2;
    // Loop through each row of Pascal's triangle
    for (int i = 2; i < n; i++) {
        printf("\nRow %i:",i-2);  // Print a newline for the new row along with row number

        // Copy the current lower array to the upper array for the new row calculation
        pascal_upper_array[i] = pascal_lower_array[i];

        // Compute the values of the new row based on the previous row
        for (int j = 1; j < i; j++) {
            pascal_lower_array[j] = pascal_upper_array[j-1] + pascal_upper_array[j];
        }
#if 0
        // Print spaces to align the triangle
        for (int k1 = 1; k1 < 10 + n - i; k1++) {
            printf(" ");
        }
#endif
        // Print the values of the current row
        for (int k = 1; k < i; k++) {
            pascal_upper_array[k] = pascal_lower_array[k];
            printf("%i ", pascal_upper_array[k]);
        }
    }
    printf("\n");
    return;
}





