#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  int rows, cols, **arr;
scanf("%d %d", &rows, &cols);
  arr = (int**)malloc(sizeof(int*) * rows);
  for(int i=0; i<rows; i++) {
    arr[i] = (int*)malloc(sizeof(int)*cols);
  }

  srand(time(NULL));
  
  for(int i=0; i<rows; i++) {
    for(int j=0; j<cols; j++) {
      arr[i][j]=rand() %90 +10 ;
    }
  }
  int *Scol;
  Scol = (int*)malloc(sizeof(int)*cols);
  for(int i=0; i<cols; i++) {
    Scol[i] = 0;
  }
  
  for(int i=0; i<rows; i++) {
    int total = 0;
    for(int j=0; j<cols; j++) {
      Scol[j]+= arr[i][j];
      printf("%d  ", arr[i][j]);
      total+=arr[i][j];
    }
    printf("%d\n", total);
    
  }

  for(int i=0; i<cols; i++) {
    printf("%d  ", Scol[i]);
  }
  
}