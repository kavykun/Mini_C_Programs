#include <omp.h>
#include <stdio.h>
#define N 256 
int main(int argc, char *argv) {
int i, j, k, x, t;
double sum;
double start, end; // used for timing
double A[N][N], B[N][N], C[N][N], D[N][N];
// set some initial values for A and B
for (i = 0; i < N; i++) {
for (j = 0; j < N; j++) {
A[i][j] = j*1;
B[i][j] = i*j+2;
}
}

double totalTimePara = 0.0;

for(t = 0 ; t < 10; t++){
omp_set_num_threads(1);//set number of threads here
// sequential matrix multiplication
start = omp_get_wtime(); //start time measurement
for (i = 0; i < N; i++) {
for (j = 0; j < N; j++) {
sum = 0;
for (k=0; k < N; k++) {
sum += A[i][k]*B[k][j];
}
C[i][j] = sum;
}
}
end = omp_get_wtime(); //end time measurement

// Add OpenMP matrix multiplication here, result in array D[N][N]

// parallel matrix multiplication
start = omp_get_wtime(); //start time measurement
for (i = 0; i < N; i++) {
#pragma omp parallel for private (k,j,sum)
for (j = 0; j < N; j++) {
sum = 0;
for (k=0; k < N; k++) {
sum += A[i][k]*B[k][j];
}
D[i][j] = sum;
}
}

end = omp_get_wtime(); //end time measurement
printf("%f\n", end-
start); 

totalTimePara += end-start;
}

double averageTimePara = totalTimePara / 10;

printf("AVGTIME: %f\n", averageTimePara);

// check sequential and parallel versions give same answers
int error = 0;
for (i = 0; i < N; i++) {
for (j = 0; j < N; j++) {
if (C[i][j] != D[i][j]) error = -1;
}
}
if (error == -1) printf("ERROR, sequential and parallel versions give different answers\n"); 
return(0);
}
