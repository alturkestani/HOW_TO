// Tariq Alturkestani
// Sept - 8 - 2015
// PMPI_Xxx wrappers 

#include "mpi.h"
#include <stdio.h>

// Overriding MPI_Send
int MPI_Send(const void *buf, int count, MPI_Datatype datatype,
        int dest, int tag, MPI_Comm comm)
{
   int ret;                         // MPI_Send return
   int local_rank;                  // 'this' process rank

   // get the rank of this process 
   PMPI_Comm_rank(comm, &local_rank);
   
   printf("[%d] sending to [%d] a msg of length [%4d] tag [%2d]\n",
        local_rank, dest, count, tag);
   
   fflush(stdout);   // need to flush if you want to read what you printed in order

   // making the actual send using MPI's profiling library
   ret = PMPI_Send(buf, count, datatype, dest, tag, comm);  // actual SEND!!

   return ret; 
}


// Overriding MPI_Recv
int MPI_Recv(void *buf, int count, MPI_Datatype datatype,
        int source, int tag, MPI_Comm comm, MPI_Status *status)
{
   int ret;                         // MPI_Send return
   int local_rank;                  // 'this' process rank

   // get the rank of this process 
   PMPI_Comm_rank(comm, &local_rank);
   
   printf("[%d] is receiving a msg of max length [%d]\n",
           local_rank,count);

   fflush(stdout);
   
   // here we do the actual receive using MPI's profiling calls      
   ret = PMPI_Recv(buf, count, datatype,
                         source, tag, comm, status); // actual receive 
   return ret;
}

// overriding MPI_Comm_rank
int MPI_Comm_rank( MPI_Comm comm, int *rank )
{
   int ret;                         // MPI_Send return
   int local_rank;                  // 'this' process rank

   // get the rank of this process 
   ret = PMPI_Comm_rank(comm, &local_rank);

   // we can do anything we want here.
   // for example, for any rank that is not 0 or 1
   //   i'll make it think that it's rank 100 because I can :)

   if (local_rank >= 2)
   {
      *rank = 100;
   }
   else
   {
      *rank = local_rank;
   }

   return ret;
}

