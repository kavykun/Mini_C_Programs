/**
 * Program that implements the monte carlo algorithm to estimate values of PI
 * Author: Kavy Rattana
 * Date: 03/24/2015
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
void *worker(void *param); //function prototype
#define NUMBER_OF_TRIALS 10000000
#define NUMBER_OF_THREADS 2
int circle_count = 0;
double random_double() {
	return random() / ((double) RAND_MAX + 1);
}
/**
 * Creates an array of pthreads
 * Passes each one the method workers.
 */
int main(int argc, const char * argv[]) {
	pthread_t workers[NUMBER_OF_THREADS];
	int i = 0;
	int number_of_trials = NUMBER_OF_TRIALS;
	double pi = 0.0;
	srandom((unsigned) time(NULL));
	for (i = 0; i < NUMBER_OF_THREADS; i++) {
		pthread_t tid;
		workers[i] = tid;
	}
	//assign each pthread with a job
	for (i = 0; i < NUMBER_OF_THREADS; i++) {
		pthread_create(&workers[i], NULL, worker, &number_of_trials);
	}
	//jojn back the data from the pthreads
	for (i = 0; i < NUMBER_OF_THREADS; i++) {
		pthread_join(workers[i], NULL);
	}
	//calculate and show final result pi
	pi = 4 * ((double) circle_count)
			/ (double) (number_of_trials * NUMBER_OF_THREADS);
	printf("PI Estimation: %f\n", pi);
	return 0;
} //end main()
/**
 * Method to generate random points between -1 and 1
 * Counts the number of points that fall within the circle
 * @ *param the number of trials
 */
void *worker(void *param) {
	int number_of_trials;
	number_of_trials = *((int *) param);
	int i;
	double x, y, z;
	for (i = 0; i < number_of_trials; i++) {
		/* generate random numbers between -1.0 and +1.0 (exclusive) */
		x = -1 + 2 * random_double();
		y = -1 + 2 * random_double();
		z = x * x + y * y;
		if (z <= 1) {
			circle_count++;
		}//end if
	}//end for it
	pthread_exit(NULL);
}//end
