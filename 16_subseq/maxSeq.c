#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int * array, size_t n){
  int max_length = 1;
  int current_max = 1;
  if (n == 0){
    max_length = 0;
    return max_length;
  }
  for (int i=0; i<(n-1); i++){
    if (array[i]<array[i+1]){
      max_length++;
    }
    else{
      if (current_max < max_length){
      current_max = max_length;
      }
      max_length = 1;
    }
    if(current_max < max_length) current_max = max_length;
  }
  return current_max;
}
