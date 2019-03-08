# Producer-Consumer-Pthreads

***** DESCRIPTION *****
This program solves the producer-consumer problem and uses synchronization and mutual exclusion 
techniques to show how a producer and consumers work together. Knowing how threads run at the 
same time is important because multithreading is far more efficient than single-threading as long 
as the threads work in sync and avoid road blocks. The output of the program is used to see if the 
operating system provides an equal allotment of sums to each consumer thread.

***** PROGRAM SPECIFICATIONS *****
- uses a single producer pthread and ten consumer pthreads
- producer pthread generates random data and places data into a buffer
- consumer pthreads consume the data by taking values out of the buffer and adding them to their 
individual sum totals
- outputs subtotal for each consumer pthread

***** PROGRAMING LANGUAGE AND TOOLS *****
- Written in C++
- Xcode

***** WHAT I LEARNED *****
I learned how pthreads are used and how to implement pthreads by solving the producer-consumer problem.
I also learned how important synchronization and mutual exclusion is in order to avoid errors in data.
