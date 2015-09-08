// Tariq Alturkestani
// Sept-8-2015
// A simple hello wold MPI application

#include <mpi.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 512

int main(int argc, char ** argv)
{
   int commWorldSize;                   // number of processor in MPI Comm World  
   int commWorldRank;                   // MPI rank of 'this' process
   char * msgToSend = "Hello World!";   // sender will send this msg
   char recvBuffer[strlen(msgToSend)];  // a buffer for the msg to be received from sender
   
   MPI_Init(NULL,NULL); // initializing MPI enviroment

   // get the size of MPI_COMM_WORLD 
   MPI_Comm_size(MPI_COMM_WORLD, &commWorldSize);

   // get the rank of 'this' process in MPI_COMM_WORLD
   MPI_Comm_rank(MPI_COMM_WORLD, &commWorldRank);

   if (commWorldRank == 0) // process with rank 0 will send a msg
   {
      printf("Rank 0 is about to send a msg to rank 1\n");

      MPI_Send((void *)msgToSend, strlen(msgToSend), MPI_CHAR, 1, 0, MPI_COMM_WORLD);


   }
   else // rank 1 will receive a msg from rank 0
   {
      MPI_Recv((void *) &recvBuffer, strlen(msgToSend), MPI_CHAR, 0, MPI_ANY_TAG, MPI_COMM_WORLD, NULL);
      
      printf("Rank 1 received [%s] from rank 0\n", recvBuffer);
   }
   
   MPI_Finalize(); // we are done. bye mpi!! clean up enviroment 

   return 0;
}
