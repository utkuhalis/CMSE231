/******************************************************************************
Lab Work #2
Experiement 2
Section 1, 2
Utku Halis
*******************************************************************************/

#include <stdio.h>

int main()
{
    int i, j, k=0, l=0;
    float y[12], c[12];
    float x[3][4] = {
        {13.5, 24.88, 66.28, 30.0},
        {2.84, 412.15, 13.2, 9.9},
        {15.5, 38.89, 12.5, 16.18}
    };
    
    for (i=0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            y[k] = x[i][j];
            k++;
        }
    }
    
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 3; i++) {
            c[l] = x[i][j];
            l++;
            
        }
    }
    
    printf("Given matrix: \n");
    
    for (i=0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %f \n", x[i][j]);
        }
        printf("\n");
    }
    
    printf("Row Wise: \n");
    
    for (i = 0; i < 12; i++) {
        printf(" %f ", y[i]);
    }
    
    printf("\nColumn Wise: \n");
    
    for (i = 0; i < 12; i++) {
        printf(" %f ", c[i]);
    }
    
    return 0;
}

