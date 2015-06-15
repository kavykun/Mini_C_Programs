#include <stdio.h>
#include <stdlib.h>

// You should experiment with various values of "TOTAL_TIME"
#define TOTAL_TIME 3000

// The tip of the soldering iron is at location (33,40)
#define TIP_X 4 
#define TIP_Y 8

#define TIP_TEMP 100 
#define ROOM_TEMP 22

// Used to access the final values.
int __guin_current = 1;
int i, j, N, T, iteration, current, next;

int main(int argc, char *argv[])
{
i = 0;
j = 0;
N = 0;
T = 0;
iteration = 0;
    // TODO: Declare the array hotplate to be 2xNxN of doubles

    // TODO: Initialize the plate to room temperature.

    // TODO: Set the soldering iron on the plate at (33,40)

printf("N Value:");
scanf("%d", &N);
printf("You enter: %d\n", N);
 
printf("T Value:");
scanf("%d", &T);
printf("You enter: %d\n", T);

double h[2][N][N]; 

current = 0; 
next = 1; 

for (iteration = 0; iteration < T; iteration++) {
 for (i = 1; i < N-1; i++){
 	for (j = 1; j < N-1; j++){
	 if (i == TIP_X && j == TIP_Y){
 
        	h[next][i][j] = TIP_TEMP;
	
	}else {
 
	h[next][i][j] = 0.25 * (h[current][i-1][j] + h[current][i+1][j] + h[current][i][j-1] + h[current][i][j+1]);

	}
}
 current = next;
 next = (current + 1)% 2; 
}
}
    // use preprocessor constants within a preprocessor directive.
    // TODO: Use the stencil pragma to compute the heat dstribution
    // Produce the output
    for (i = 0; i < N; i++) { 
        for (j = 0; j < N; j++) { 
            printf ("[%f]", h[1][i][j]);
        }
        printf ("\n");
    }
    printf ("\n\n");

}

