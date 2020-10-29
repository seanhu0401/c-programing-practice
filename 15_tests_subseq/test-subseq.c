#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(){
  int arr1[] = {0};
  size_t ans1 = maxSeq(arr1, 1);
  if (ans1 != 1) exit(EXIT_FAILURE);
  
  int arr2[] = {};
  size_t ans2 = maxSeq(arr2, 0);
  if (ans2 != 0) exit(EXIT_FAILURE);
  
  int arr3[] = {0,1,1,5,6};
  size_t ans3 = maxSeq(arr3, 5);
  if (ans3 != 3) exit(EXIT_FAILURE);

  int arr4[] = {-3,-4,-2,0,3};
  size_t ans4 = maxSeq(arr4,5);
  if (ans4 != 4) exit(EXIT_FAILURE);
  
  int arr5[] = {-3,-42,-99,-100,-99,-88};
  size_t ans5 = maxSeq(arr5,6);
  if (ans5 != 3) exit(EXIT_FAILURE);
  
  return EXIT_SUCCESS;
}
