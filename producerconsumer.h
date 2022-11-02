/* Joshua Thompson
*  11/1/2022
*  Producer Consumer Problem */

*/ This file contains all global variables, the buffer, and the structure item in use
*  across all project files */

#ifndef PRODUCERCONSUMER_H
#define PRODUCERCONSUMER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define BUFFER_SIZE 2

struct item { int x; }; // X will be the value added

struct item buffer[BUFFER_SIZE]; // "Table"

int in = 0; // Tracks where the producer is looking

int out = 0; // Tracks where the consumer is looking

int counter = 1; // Semaphore

#endif
