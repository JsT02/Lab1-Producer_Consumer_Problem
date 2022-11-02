/* Joshua Thompson
*  11/1/2022
*  Lab 1
*  Professor */

/* This program contains all functions used in both producer.c and
*  consumer.c.  They function as semaphores. */

wait(counter){

   while(counter <= 0);

   counter--;

}

signal(counter){

   counter++;

}
