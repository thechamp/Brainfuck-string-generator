/*
 * Author       :  Abhay Jain
 * File         :  bf_string_generator.c
 * Description  :  This program reads a string character by character from
                   a file which is provided as second argument to main function
                   and generates a Brainfuck program as output. This Brainfuck
                   program prints the same string as its output.
 * Created on   :  14 Nov 2012
 * Language     :  C
 */

#include <stdio.h>
#include "converter_helper.h"

int main(int argc, char *argv[])
{
    FILE *input;
    int n;      // ASCII value of letter to be printed
    int min;    // Largest power of 2 less than or equal to n
    int max;    // Smallest power of 2 greater than n
    int p;      // Current value of first pointer in BrainFuck
    int count;  // Number of divisions or multiplications required to be performed on p
                // such that it can be brought down to min
	char letter, type;
    
    input = fopen(argv[1], "r");
	min = max = p = 2;
	
	// Initialize p with 2
	printf ("++");
	
	while ((letter=fgetc(input)) != EOF)
	{
		n = letter;
		count = 0;
		
		/* If p is greater than n, we need to perform division to find min */
		if (p >= n)
		{
			while (p > n)
			{
				p /= 2;
				count++;
			}
			
			min = p;
			max = p * 2;
			type = 'd';
		}
		
		/* if p is less than n, we need to perform multiplication to find min */
		else
		{
			while(p < n)
			{
				p *= 2;
				count++;
			}
			
			max = p;
			min = p / 2;
			count--;
			type = 'm';
		}
		
		p = generate_bf_equivalent(min, n, max, count, type);
        printf ("\n");
	}
	return 0;
}
