run: compile
	mpirun -np 8 --hostfile machinefile ./mpiex
compile:
	mpicc mpiEx2b.c -o mpiex
clean:
	rm -rf mpiex
