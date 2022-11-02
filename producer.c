/* Joshua Thompson
*  11/1/2022
*  Producer Consumer Problem */

/* This file acts as the producer in the producer consumer problem.
*  When the buffer is not full, the producer will "produce" an item in
*  an empty space.  When the buffer is full, the producer will be forced
*  to wait. */

#include "producerconsumer.h"
#include "producerconsumer.c"

int main(){

  struct item nextProduced;

  while(true){

    wait(counter); // Checks if other process is in crit section

    nextProduced.x = rand(); // Produce a random number

    buffer[in] = nextProduced; // Put the item in the buffer

    printf("Produced\n"); // Confirm the item was put in the buffer

    in = (in + 1) % BUFFER_SIZE; // Move in to next slot

    signal(counter); // Exits crit section

  }

}
