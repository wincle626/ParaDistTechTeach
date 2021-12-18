#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <omp.h>

int main(int argc, char** argv){

   int i, j, nPrivate=4, nSave[4];
   omp_set_num_threads(4);

   #pragma omp parallel private(nPrivate)
   {
      #pragma omp for 
      for(i=0;i<4;i++){
         int tid = omp_get_thread_num();
         nPrivate --;
         nSave[tid] = nPrivate;
      }
   }

   for(i=0;i<4;i++){
      printf("data on %d thread is %d\n", i, nSave[i]);
   }
   return 0;
}