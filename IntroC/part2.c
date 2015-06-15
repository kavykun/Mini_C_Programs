#include <stdio.h>
// Name: Kavy Rattana
// Date: 12/3/2013
// Assignment: C Language Intro Lab
//
// Description: Gets the total cost from the user and calculates the shipping cost. Then, prints out the total plus the shipping cost.
int main()
{
		/*Initialize variables */
        float  shippingCost = 0;
        float  totalCost = 0;
		float  discountCost = 0;
		
		printf("Welcome to Walmart. Today is the Black Friday Sale. You get 10 percent off of your total!\n");

		/*Prompts the user for a integer for the total cost */
        printf("Enter cost of the order: \n");
		totalCost = 56.0;
		/*Takes the input using scanner and puts the number into totalCost */
        scanf("%f",&totalCost);
		/*Prints out the user's input */
		printf("You entered: %d\n", totalCost);
		/*Checks to see if the number is negative */
			if(totalCost < 0) {
			
				printf("Invalid cost\n");
		
		}
		/*Calculates the discount from the total cost */
		printf("Black Friday Discount: 10%\n");
		discountCost = totalCost * 0.10f;
		/*Subtracts the discounted amount from the total cost */
		totalCost = totalCost - discountCost;
		/*Prints out the amount saved with the discount */
		printf("You saved: $%.2f\n", discountCost);
		/*Calculates the shipping cost based on the total cost */
        shippingCost = totalCost <= 100 ? totalCost * 0.05f : 0;
	
		
		/*Prints out the calculate shipping cost */
        printf("Shipping Cost: $%.2f\n", shippingCost);
		/*Prints out the total cost after adding the shipping cost to the total cost */
        printf("Total Cost: $%.2f\n", totalCost + shippingCost);

} /*end of main */
