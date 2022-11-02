/* Joshua Thompson
*  11/1/2022
*  Producer Consumer Problem */

/* This file contains all functions used in both producer.c and
*  consumer.c.  They function as semaphores. */

wait(counter){

   while(counter <= 0); // If another process is in crit, force wait

   counter--; // Process enters crit section

}

signal(counter){

   counter++; // Process exits crit section

}
