/**
 * Takes in a positive integer as an argument and applies the Collatz conjecture
 * Kavy Rattana
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
	pid_t pid;
	int n;
	if (argc == 1) {//the program requires a positive integer to be entered after running the program.
		fprintf(stderr, "Usage: ./a.out <starting value>\n");
		return -1;
	}
	n = atoi(argv[1]); //get the value from the user
	if (n <= 0) { // checks to see if the number entered is positive
		printf("Please enter a positive number after ./a.out\n");
		return -1;
	} else {
		//if a positive number then continue
		pid = fork(); //fork a child
		if (pid < 0) {
			fprintf(stderr, "Fork Failed\n");
			return 1;
		} else if (pid == 0) {
			printf("I am the child %d\n", pid);
			printf("%d\n", n);
			while (n != 1) {
				//handles even numbers
				if (n % 2 == 0) {
					n = n / 2;
					printf("%d\n", n);
					//handles odd numbers
				} else {
					n = 3 * n + 1;
					printf("%d\n", n);
				}//end else
			}//end while
		} else {
			printf("I am the parent %d\n", pid);
			wait(NULL);
			printf("Child Complete\n");
		}//end else
		return 0;
	}//end else
}//end main
