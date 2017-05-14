#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int size, rank, tag=1, inmsg, outmsg, block, total=0, temTotal=0;
	MPI_Status Stat;
	
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	block = 100000/size;
	
	for(int i = block*rank+1; i <= block*(rank+1); i++){
		total += i;
	}
	
	if(rank==0) {
		for(int i = 1; i < size; i++){
			MPI_Recv(&temTotal, 1, MPI_INT, i, tag, MPI_COMM_WORLD, &Stat);
			total += temTotal;
		}
		
		printf("%d \n", total);
	}
	
	else {
		MPI_Send(&total, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
	}
	
	MPI_Finalize();
}
