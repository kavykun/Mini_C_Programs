/**
 * Program the creates a zombie process of the child for 10 seconds.
 * Kavy Rattana
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
/**
 * Main method to fork the child and create the zombie proces
 */
int main() {
	pid_t pid; // Initiliaze the PID variable
	pid = fork(); // Fork the child
	if (pid < 0) { //Checks to see if the Fork has failed
		fprintf(stderr, "Fork Failed\n");
		return 1;
	} else if (pid == 0) { // Handles the child process
		printf("I am the child %d\n", pid);
	} else { // Handles the parent process
		printf("I am the parent %d\n", pid);
		sleep(10); //putting the child to sleep.
		//The zombie process will remain in the system for at least 10 seconds
		printf("Child Complete\n");
	}//end else
	return 0;
}//end main
