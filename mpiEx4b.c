#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int size, rank, tag=1, inmsg, outmsg, block, total=0, temTotal=0;
	MPI_Status Stat;
	
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	block = 10000/size;
	
	for(int i=block*rank+1; i<=block*(rank+1); i++){
		total += i;
	}
	
	MPI_Reduce(&total, &temTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if(rank==0) {
		printf("%d \n", temTotal);
	}
	
	MPI_Finalize();
}
