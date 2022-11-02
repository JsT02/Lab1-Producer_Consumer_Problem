Name: Joshua Thompson
User: JsT02
Date: 11/1/2022

Overview: This program is a solution for the producer consumer problem.  It uses processor
synchronization and semaphores, and it is written in C.  The requirements for this 
program are as follows:

1) The producer and consumer can not be in the same file.  They must be in two separate files.
2) The producer and consumer must operate infinitly, or until stopped by ctrl C
3) The buffer must be placed in shared memory.
4) The size of the buffer must be equal to two.
5) All main files must be able to compile with the following options:

      gcc filename.c -pthread -lrt -o filename
6) The producer and consumer must run synchronously (./filename & ./filename)

The shared memory for this project is located in the header file "producerconsumer.h".
It contains the buffer, BUFFER_SIZE, any global variables used such as counter, and
the datatype item.  Item contains a single element x which will act as the "item" being
added.

The file "producerconsumer.c" contains all functions used throughout the project with
an exception for rand().  The function wait() will deincrement the semaphore if no other
process already has.  Otherwise the function fores the process to wait.  This protects
the shared memory from being altered by multiple processes at a time.  The function
signal() increments the semaphore. When a process invokes wait(), it enters its critical
section of code.  When signal() is invoked, the process exits its critical section.

The producer is located in "producer.c".  Unique to this process is the item nextProduced.
This will be added to the buffer when called for.  The process first invokes wait().
Then, a random number is generated using rand() and is put in the element X in nextProduced.
Once generated, nextProduced is added to the buffer.  It is added at location in, which
tracks where the producer is looking at using an integer value.  In then moves to the
next slot.  Once all of this is done, the process invokes signal() to exit the critical
section.  The producer then loops.

The consumer is located in "consumer.c".  Unique to this process is the item nextConsumed.
Its X element is set equal to zero.  This will represent the consumer "consuming" the
slot.  The process first invokes wait().  Then, nextConsumed is added to the buffer.  It
is added at location out, which is similar to in except it tracks where the consumer is
looking.  Out then moves to the next slot.  Once all of this is done, the process invokes
signal() to exit the critical section. The consumer then loops.

In both processes, successful production and consumption is marked by "Produced" and
"Consumed" respectively.  Here is an example of what the output should look like:

* Insert screenshot *

This is my first project using C, so getting used to C format was troublesome. However,
since I have been coding in mainly C++, it was not that difficult.  One of my issues
was trying to figure out why the compiler was not accepting <iostream>.  The reason for
this is simply because <iostream> does not exist in C. The equivalent header file for
this is <stdio.h>.
