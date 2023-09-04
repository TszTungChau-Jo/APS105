/*
Completion Date: 2022/01/19
Lab 2: Part 2——Deciphering a code
Task: Decipher a 4-digit code by the given combination of the form abcd is encoded as d(9-b)(9-c)a.
    Example: 8021 => 1978, 0428 => 8570
*/

/*
Procedure:
    1. Collect the 4 digits code from the user.
    2. Decipher the <entered> code.
    3. Prints out the result.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    /* S1. Declare variables.  */
    int password, result;


    /* S2. Collect the 4-digit code from the user.  */
    printf("Enter an encrypted 4-digit combination: ");
        scanf("%d", &password);


    /* S3. Deciphering the code~  */    
    
    /* .0 Analyse each of the 4 (entered) numbers. */
    // to get the thousand-th number 
    int thousand = (int) rint(password * 0.001);

    // to get the hundred-th number 
    int hundred = (int) rint((password - thousand * 1000) * 0.01);

    // to get the ten-th number 
    int ten = (int) rint((password - thousand * 1000 - hundred * 100) * 0.1);

    // To get the digit number 
    int digit = (int) rint(password - thousand * 1000 - hundred * 100 - ten * 10);

    /* .1 Rearrange the numbers according to the given scheme.  */
    // the thousand-th place
    result = 0 + digit * 1000;

    // the hundred-th place
    result = result + (9 - hundred) * 100;

    // the second-th plaec
    result = result + (9 - ten) * 10;

    // the first-th place
    result = result + thousand;


    /* S4. Print out the result of the deciphered code*/
    printf("The real combination is: %04d", result);  // using a %04d flag here,  
                                                      // 0 indicates a padding when the 4-th digit is zero, so that the reverse begins with zero
                                                      // 4 indicates the length of printing a 4 digits value


    /* Testing~ */
    //printf("\n\n%d  %d  %d  %d  %d", password, thousand, hundred, ten, digit);
    //printf("\n\n%d", result);

    return 0;
}