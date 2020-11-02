#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(){
  printf("hello\n");
  printf("testing case1\n");
  int arr1[] = {0};
  size_t ans1 = maxSeq(arr1, 1);
  if (ans1 != 1){
    printf("fail case1\n");
    exit(EXIT_FAILURE);
  }
  
  printf("testing case2\n");
  int arr2[0];
  size_t ans2 = maxSeq(arr2, 0);
  if (ans2 != 0){
    printf("fail case2\n");
    exit(EXIT_FAILURE);
  }

  printf("testing case3\n");
  int arr3[] = {0,1,1,5,6};
  size_t ans3 = maxSeq(arr3, 5);
  if (ans3 != 3){
    printf("fail case3\n");
    exit(EXIT_FAILURE);
  }
  
  printf("testing case4\n");  
  int arr4[] = {-3,-4,-2,0,3};
  size_t ans4 = maxSeq(arr4,5);
  if (ans4 != 4){
    printf("fail case4\n");
    exit(EXIT_FAILURE);
  }

  printf("testing case5\n");
  int arr5[] = {-3,-42,-99,-100,-99,-88};
  size_t ans5 = maxSeq(arr5,6);
  if (ans5 != 3){
    printf("fail case5\n");
    exit(EXIT_FAILURE);
  }

  printf("testing case6\n");
  int arr6[] = {-4,2,4,3,5,6,7,3,4,2};
  size_t ans6 = maxSeq(arr6,10);
  if (ans6 != 4){
    printf("fail case6\n");
    exit(EXIT_FAILURE);
  }
    
  return EXIT_SUCCESS;
}
