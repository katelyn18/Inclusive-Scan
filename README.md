# Inclusive-Scan
Using MPI, create an array with a size the same as the number of processors inputted. Initialize the array with random values. Using those random values, display the indexes of the array allocated to the processors (index starts at 1). <br />
To run in the terminal: (N is the number of processors less than 100) <br />
	mpicc [filename] <br />
	mpirun -n N ./a.out
