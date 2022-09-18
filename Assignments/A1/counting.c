/*
Here, I implement a brute force solution to compute the number of non-negative
integers that satisfy the requirement in some given value range. The
non-negative integer we are interested in contains a specific digit that is
repeated a specific number of times in the non-negative integer. This program
will check each integer in the specified range to see if it qualifies.
*/

#include <math.h>
#include <stdio.h>

int Counting(int min_range, int max_range, int digit, int repetition);

int main() {
  /*
  min_range: minimum of considered range;
  max_range: maximum of considered range;
  digit: specific digit of interest;
  repetition: number of digit repetitions;
  count: the number of valus in the given range satisfying the requirement.
  */
  int min_range, max_range, digit, repetition, count;

  // read values in order and exam if they are valid
  printf("Enter the minimum of considered range: ");
  scanf("%d", &min_range);

  printf("Enter the maximum of considered range: ");
  scanf("%d", &max_range);

  printf("Enter the digit of interst: ");
  scanf("%d", &digit);

  printf("Enter the number of repetitions: ");
  scanf("%d", &repetition);

  count = Counting(min_range, max_range, digit, repetition);
  printf("The number of integers from %d to %d that include "
         "exactly %d %d's is %d. \n",
         min_range, max_range, digit, repetition, count);

  return 0;
}

// define a helper function to return the larger number;
int max(int a, int b) { return (a > b) ? a : b; }

int Counting(int min_range, int max_range, int digit, int repetition) {
  int temp_max = max_range, TEMP_REP = 0;
  int count = 0;

  // If the maximum number's digits in the given range is less than the
  // repetitions, then there will not be a value in the given range that
  // satisfies the requirement
  if (max_range < (repetition - 1) * 10) {
    return count;
  }

  // Counting the number of values satisfying the requirement
  for (int num = max(min_range, 0); num <= max_range; num++) {
    int tmp_num = num;
    int real_repetition = 0;

    // extract digits one by one using integer arithmetic, and check if each
    // digit is our interested digits.
    while (tmp_num > 0) {
      int real_digit = tmp_num % 10;
      if (real_digit == digit) {
        real_repetition++;
      }
      // Once the actual repetion exceeds the interested repetition, we can
      // determine this valus is not what we want.
      if (real_repetition > repetition) {
        break;
      }
      tmp_num /= 10;
    }
    if (real_repetition == repetition) {
      count++;
    }
  }
  return count;
}
