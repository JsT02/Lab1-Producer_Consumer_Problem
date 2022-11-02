/* Joshua Thompson
*  11/1/2022
*  Producer Consumer Problem
*  Professor */

/* This program acts as the consumer in the producer consumer problem.
*  When the buffer is not empty, the consumer will "consume" an item on
*  the buffer.  When the buffer is empty, the consumer is forced to
*  wait. */

#include "producerconsumer.h"
#include "producerconsumer.c"

int main(){

  struct item nextConsumed;

  nextConsumed.x = 0; // "Consumes" an item

  while(true){

    wait(counter); // Checks if other process is in crit section

    buffer[out] = nextConsumed; // Consume item

    printf("Consumed\n"); // Confirm consumption

    out = (out+1) % BUFFER_SIZE; // Move to next slot

    signal(counter); // Exit crit section

  }

}
