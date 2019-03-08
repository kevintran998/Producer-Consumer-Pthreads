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
- The producer pthread generates one million values in which each value is the sum of 1000 float
numbers within the range 0-1 including 0 and the sum is divided by 500
- consumer pthreads consume the data by taking values out of the buffer and adding them to their 
individual sum totals
- mutual exclusion = only one pthread can consume data at a single point in time
- outputs subtotal for each consumer pthread

***** PROGRAMING LANGUAGE AND TOOLS *****
- Written in C++
- Xcode

***** WHAT I LEARNED *****
I learned how pthreads are used and how to implement pthreads by solving the producer-consumer problem.
I also learned how important synchronization and mutual exclusion is in order to avoid errors in data.

***** STEP BY STEP DESCRIPTION *****
The first step in creating this program is to create the producer pthread and the 10 consumer pthreads. The producer and consumers will execute simultaneously so that the consumers can take values as they are created by the producer. The producer pthread generates one million values in which each value is the sum of 1000 float numbers within the range 0-1 including 0 and the sum is divided by 500. These values are then placed into a buffer one by one as they are generated. As the producer thread executes, the consumer threads will take values out of the buffer and add each value to their individual subtotal. In order to prevent the producer and each consumer thread from colliding, I implemented a mutual exclusion system where only one thread is allowed to access the buffer at a time. Once all one million values have been produced and consumed, the consumer threads will display their individual subtotals to the screen. By running multiple executions of the program, I have concluded that the operating system does provide equal allotment of sums to each consumer thread. While the sums are not exactly equal, the sums are within a fair margin to confidently say that the consumers consumed around the same number of values and the sums are varied because of the random data. The equal allotment indicates that there is a fair-sharing system when the mutual exclusion lock decides which consumer thread is allowed to take a value from the buffer. The consumer threads take turns accessing the buffer where not one thread is allowed take more than the others.
