#include <mpi.h>
#include <stdio.h>

#define MAXARRAY 20

int iniarray(int n, int *array) {
	int i;
	for (i = 0; i < n; i++) 
		array[i] = i;
	return i;
}

void printarray(int n, int *array) {
	int i = 0;
	printf("[ ");
	for (; i < n; i++) {
		if (i == n - 1) 
			printf("%d ", array[i]);
		else
			printf("%d, ", array[i]);
	}
	printf("]\n");
}

void myBcast(void *data, int numelem, MPI_Datatype datatype, int root, MPI_Comm communicator){
	int size, rank, tag=1;
	MPI_Status Stat;
	
	MPI_Comm_size(communicator, &size);
	MPI_Comm_rank(communicator, &rank);
	
	if(rank != root){
		MPI_Recv(data, numelem, datatype, root, tag, MPI_COMM_WORLD, &Stat);
	} else {
		for(int i = 0; i < size; i++) {
			if(i != root){
				MPI_Send(data, numelem, datatype, i, tag, MPI_COMM_WORLD);
			}
		}
	}
	
}

int main(int argc, char** argv) {
	int arreglo[MAXARRAY];
	int rank;
	
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if (rank == 0) {
		iniarray(MAXARRAY, arreglo);
		myBcast(arreglo, MAXARRAY, MPI_INT, 0, MPI_COMM_WORLD);
	} else {
		if (rank == 1) {
			printf("Imprimiendo arreglo desde [%d]\n", rank);
			printarray(MAXARRAY, arreglo);
		}
		myBcast(arreglo, MAXARRAY, MPI_INT, 0, MPI_COMM_WORLD);
		if (rank == 1) {
			printf("Imprimiendo arreglo desde [%d]\n", rank);
			printarray(MAXARRAY, arreglo);
		}
	}
	MPI_Finalize();
}
