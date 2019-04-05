/*
Inclusive Scan
*/
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])   {    
    int n = 100;    
    int a[ 100 ];
	int temp[ 100 ];   
    int rank;    
    int size; 
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);    
    MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand( time( NULL ) );

	//get user input
	if( rank == 0 ){
		//initialize array with random numbers
		for( int i = 0; i < size; i ++ ){
			int num = rand() % 9;
			a[ i ] = num + 1;
			printf( "a[ %d ] = %d\n", i, a[ i ] );
		}	
		//inclusive scan
		temp[ 0 ] = a[ 0 ];  
		for( int i = 1; i <= size; i++ ){
			temp[ i ] = temp[ i - 1 ] + a[ i ];
		}
		
	}

	//send same array to all other processors
	MPI_Bcast( &temp, n, MPI_INT, 0, MPI_COMM_WORLD );

	if( rank != 0 ){
		printf( "Process %d range: %d - %d\n", rank, temp[ rank -1 ] + 1, temp[ rank ] );
	}
	else{	//if rank is 0, number needs to start at 1
		printf( "Process %d range: 1 - %d\n", rank, temp[ rank ] );
	}

     MPI_Finalize();    
     return 0;
}









