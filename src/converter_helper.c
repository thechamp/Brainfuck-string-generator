/*
 * Author       :  Abhay Jain
 * File         :  converter_helper.c
 * Description  :  This helper module contains the definition of
                   all functions used in project.
 * Created on   :  14 Nov 2012
 * Language     :  C
 */
 
#include <stdio.h>
#include "converter_helper.h"

/* Function to divide the value stored in current pointer by 2 */
void print_division_by_2(int count)
{
    // Perform division 'count' number of times
	while (count--)
		printf("[-->+<]>[-<+>]<");
}

/* Function to multiply the value stored in current pointer by 2 */
void print_multiplication_by_2(int count)
{
    // Perform multiplication 'count' number of times
	while (count--)
		printf("[->++<]>[-<+>]<");
}

/* Number of additions or subtractions required to the power of 2
   to make make it equal to ASCII of alphabet */
void print_remainder_steps(int count, char op)
{
	int q = count / 10;
	int r = count % 10;
	int i;
	char opx;
	
	if (op == '+')
		opx = '-';
	else
		opx = '+';
	
	// When number of steps required are more than 10, do them in a loop
	// This will reduce number of characters in BrainFuck output
	if (q)
	{
		printf (">++++++++++[->");
		
		while (q--)
			printf ("+");
	
		printf ("<]>");
	
		while (r--)
			printf ("+");
		
		printf ("[-<+<%c>>]<<.>[-<%c>]<", op, opx);
	}
	
	// Remaining steps should be done using simple + or - sign of BF
	else
	{
		for (i=0; i<r; i++)
			printf ("%c", op);
		printf (".");
		
		while (r--)
			printf ("%c", opx);
	}
}

int generate_bf_equivalent(int min, int n, int max, int count, char type)
{
	int additions_needed, subtractions_needed;
	additions_needed = n - min;
	subtractions_needed = max - n;
	
	// ASCII of alphabet is closer to min (defined in bf_string_generator.c)
	// Perform addition to bring 'min' up to ASCII of alphabet
	if (additions_needed <= subtractions_needed)
	{
		if (type == 'd')
			print_division_by_2(count);
		else
			print_multiplication_by_2(count);
		print_remainder_steps(additions_needed, '+');
		return min;
	}
	
	// ASCII of alphabet is closer to max (defined in bf_string_generator.c)
	// Perform subtraction to bring 'max' down to ASCII of alphabet
	else
	{
		if (type == 'd')
			print_division_by_2(count-1);
		else
			print_multiplication_by_2(count+1);
		print_remainder_steps(subtractions_needed, '-');
		return max;
	}
}
