#include "utils.h"

/* */
int perfect_square (int n) {

  int low = 1, high = n;
  int* result = (int*)malloc(sizeof(int) * (n + 1)); // Allocate memory for the result list 
  int result_size = 0; // Keep track of the number of perfect squares found

  while (low <= high) {
    int mid = (low + high) / 2;
    if (mid * mid == n) {
      result[result_size++] = mid; 
      // Handle the case where we might have multiple perfect squares
      low = mid + 1; // Continue searching for more perfect squares 
    } else if (mid * mid > n) {
      high = mid - 1; 
    } else {
      low = mid + 1;
    }
  }
} 

/* */
int main () {
  int i;
  int n = 100;
  for (i = 1; i < n; i++) {
    if (perfect_square(i)) {
      printf("Número %d é um quadrado perfeito.\n", i);
    }
  }  
  return 0;
}
