/******************************************************************************
Lab Work #2
Experiement 1
Section 1.1, 1.2
Utku Halis
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int LIMIT = 150;

int main ()
{
    srand (time(NULL));
    int numbers[LIMIT], x, y, temp;

    for (int i = 0; i < LIMIT; i++) {
    numbers[i] = rand () % 600 + 1;
    }


    for (x = 0; x < LIMIT - 1; x++) {
        for (y = 0; y < LIMIT - x - 1; y++) {
          if (numbers[y] > numbers[y + 1]) {
              temp = numbers[y];
              numbers[y] = numbers[y + 1];
              numbers[y + 1] = temp;
            }
        }
    }
  
    printf("Array after implementing bubble sort: \n");

    for(x = 0; x < LIMIT; x++){
        printf("%d -> ", numbers[x]);
    }
  return 0;
}

