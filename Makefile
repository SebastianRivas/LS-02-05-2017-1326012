run: compile
	mpirun -np 6 --hostfile machinefile ./mpiex
compile:
	mpicc Axb.c -o mpiex
clean:
	rm -rf mpiex
