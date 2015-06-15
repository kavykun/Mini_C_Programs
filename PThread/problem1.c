/**
 * The program takes a list of integers as arguments and returns the average, maximum, and the minimum
 * @Author: Kavy Rattana
 * @Date: 02/26/2014
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

//size of the list
int *list;
int num_of_args;

//the variables
double average;
double minimum;
double maximum;

//initializing the methods.
void *calculate_average(void *param);
void *calculate_maximum(void *param);
void *calculate_minimum(void *param);

/**
 *calculates the average of a set of arguments
 *@argv the array of arguments
 */
void *calculate_average(void * argv) {

	char **arguments = (char**)argv;

	int i = 0;
	double total = 0;
	double average = 0.0;

	for(i = 1 ; i <= num_of_args; i++){
		total += atoi(arguments[i]);
	}

	average = total / num_of_args;

	printf("The average is: %f\n", average);

	pthread_exit(NULL);
}//end average
/**
 *calculates the maximum of a set of arguments
 *@argv the array of arguments
 */
void *calculate_maximum(void * argv) {

	char **arguments = (char**)argv;

	maximum = atoi(arguments[1]);

	int i = 0;

	for(i = 1 ; i <= num_of_args; i++){
		if(atoi(arguments[i]) > maximum){
			maximum = atoi(arguments[i]);
		}//end if
	}//end for

	printf("The maximum number is: %f\n", maximum);

	pthread_exit(NULL);
}//end maximum
/**
 * calculates the minimum of a set of arguments
 * @argv the array of arguments
 */
void *calculate_minimum(void * argv) {

	char **arguments = (char**)argv;

	minimum = atoi(arguments[1]);

	int i = 0;

	for(i = 1 ; i <= num_of_args; i++){
		if(atoi(arguments[i]) < minimum){
			minimum = atoi(arguments[i]);
		}//end if

	}//end for

	printf("The minimum number is: %f\n", minimum);

	pthread_exit(NULL);
}//end minimum
/**
 *main method for the program.
 *@argc the number of arguments passed in
 *@argv the array of arguments in string
 */
int main(int argc, char *argv[]) {

	pthread_t tid_1;
	pthread_t tid_2;
	pthread_t tid_3;

	num_of_args = argc - 1;

	list = malloc(sizeof(int) * num_of_args);

	if (list == NULL) {
		fprintf(stderr, "could not allocate memory.\n");
		exit(EXIT_FAILURE);
	}

	pthread_create(&tid_1, NULL, calculate_average, (void *) argv);
	pthread_create(&tid_2, NULL, calculate_maximum, (void *) argv);
	pthread_create(&tid_3, NULL, calculate_minimum, (void *) argv);

	pthread_join(tid_1, NULL);
	pthread_join(tid_2, NULL);
	pthread_join(tid_3, NULL);

	return 0;
}//end main
