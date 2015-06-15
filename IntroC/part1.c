#include <stdio.h>
// Name: Kavy Rattana
// Date: 12/3/2013
// Assignment: C Language Intro Lab
//
// Description: Gets an integer from the user and checks to see if the number is evenly divisible by 5. If it is, then print true; if not then print false.
int main()
{
		/*Initialize variables */
		int anumber;
		/*Prompts the user to input a number */ 
		printf("Enter an integer ");
		/*Takes the input and puts it into anumber */
        scanf("%d",&anumber);
		/*Prints out the number */
		printf("You entered %d", anumber);
		/*Checks to see if the number is evenly divisible by 5 */
        printf("%s\n", (anumber % 5 == 0) ? "true" : "false");
		/*Statements to print out the number */
		if(anumber % 5 == 0) {
			printf("%d is divisible by 5", anumber);
		}
		else {
			printf("%d is not divisible by 5", anumber);
		}
} /*end main *?
