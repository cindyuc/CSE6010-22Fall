#include <stdio.h>
#include <math.h>

int Counting(int min_r, int max_r, int digit, int rep);

int main() 
{
    /*
    min_r: minimum of considered range;
    max_r: maximum of considered range;
    digit: digit of interest;
    rep: number of repetitions;
    */
    int min_r, max_r, digit, rep, count;


    // read valid values in order
    printf("Enter the minimum of considered range: ");
    scanf("%d", &min_r);
    printf("Enter the maximum of considered range: ");
    scanf("%d", &max_r);
    if (max_r < min_r)
    {
        printf("INPUT ERROR: The maximum of range must be"
                "larger or equal than the minimum of range");
    }


    printf("Enter the digit of interst: ");
    scanf("%d", &digit);
    if (digit == 0)
    {
        printf("INPUT ERROR: The digit must between 1 to 9."
                "It cannot be 0.");
    }


    printf("Enter the number of repetitions: ");
    scanf("%d", &rep);


    Counting(min_r, max_r, digit, rep);

    return 0;

}


int Counting(int min_r, int max_r, int digit, int rep)
{
    /*
    Counting the number of nonnegative integers in the range that include
    exactly n interested numbers.
    */

    int temp_max = max_r, TEMP_REP = 0;
    int count = 0;
    /*
    Check the maximum number of repetitions we can have in the 
    range we are interested in. Then check if the input for the 
    number of repetitions is valid.
    */
    while (temp_max > 0) 
    {
        TEMP_REP++;
        temp_max = temp_max / 10;
    }
    if (rep > TEMP_REP)
    {
        printf("INPUT ERROR: The maximum number of repetitions is impossible");
    }



    if (max_r > 0)
    {
        int num = min_r;
        int j = pow(10, TEMP_REP-1);

        // We don't need to exam the negative integers and positive integers 
        // with valid digits less than the desired repeated value.
        while (num <= (rep-1)*10) 
        {
            num++;
        }

        // Examing the possible integer in the range one by one;
        while (num <= max_r) 
        {
            // Using integer arithmetic to extract each digit separately. 
            // Then, check if the extracted digit equal the desired digit.
            int d = num;
            int power = j;
            while(d > 0)
            {
                int extract = d / power;
                if (extract == digit) {
                    count++;
                }
                if (extract != 0) {
                    d -= extract * power;
                }
                if (power != 1) {
                    power /= 10;
                }
            }
            num++;
        }

    }

    printf("The number of integers from %d to %d that include"
            "exactly %d %d's is %d. \n", min_r, max_r, digit, rep, count);

    return 0;
}
