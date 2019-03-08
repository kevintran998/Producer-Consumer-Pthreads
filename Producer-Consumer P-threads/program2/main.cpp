// File: main.cpp
// Author: Kevin Tran
//
// Producer: produces values and places them into a buffer to be consumed
// Consumer: takes values out of the buffer and adds them to a subtotal
// main: initialize the buffer and creates pthreads (producer and consumers)
// produce: takes the sum of 1000 values in [0,1), divides the sum by 500, then returns the sum
// consume: adds a value to the total
// uniform: returns a value in [0,1)
// append: loops through the buffer and adds a value into the next available spot
// take: loops through the buffer and takes a value from the next available spot, and it resets the array
//          element to -1

#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;

//prototypes
double produce();
double consume(double, double);
double uniform();
void append(double);
double take();

//global variables
#define THREAD_COUNT 10 // number of consumer threads
static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; // mutual exclusion
double buffer[1000]; // buffer
int bufferCount = 0; // indicates the number of values in the buffer at current time
bool doneProducing = false; // indicates when all 1 million values have been produced

// produces 1 million values and places them into a buffer
void *Producer(void *arg)
{
    int counter = 0;
    double value = 0;
    
    // produce 1 million values
    while (counter < 1000000)
    {
        // get value (sum)
        value = produce();
        
        // if buffer is full, wait
        while(bufferCount >= 1000)
        {
            
        }
        
        // lock the buffer, add the value to the buffer, unlock the buffer
        pthread_mutex_lock(&m);
        append(value);
        pthread_mutex_unlock(&m);
        
        // increment bufferCount and counter
        bufferCount++;
        counter++;
    }
    
    // tell consumer threads that Producer is finished producing
    doneProducing = true;
    
    return NULL;
}

// takes values out of the buffer and adds them to a subtotal
void *Consumer(void *arg)
{
    double total = 0;
    double value = 0;

    // execute until the Producer is done
    while(doneProducing == false)
    {
        // if the buffer is empty and the producer is not finished, wait
        while (bufferCount == 0 && doneProducing == false)
        {

        }
        
        // lock the buffer, take a value from the buffer, unlock the buffer
        pthread_mutex_lock(&m);
        value = take();
        pthread_mutex_unlock(&m);
        
        // decrement bufferCount and add the value to the total
        bufferCount--;
        total = consume(value, total);
    }
    
    // mutual exclusion so threads print subtotals one at a time
    pthread_mutex_lock(&m);
    cout << "SubTotal: " << total << endl;
    pthread_mutex_unlock(&m);
    
    return NULL;
}

// main initializes the buffer and pthreads
int main()
{
    // initialize buffer
    for(int x = 0; x < 1000; x++)
    {
        buffer[x] = -1;
    }
    
    pthread_t produce;
    pthread_t consumers[THREAD_COUNT];
    
    // create produce thread
    pthread_create(&produce, NULL, Producer, NULL);
    
    // create consume threads
    for (int x = 0; x < 10; x++)
    {
        pthread_create(&consumers[x], NULL, Consumer, NULL);
    }
    
    // join threads
    pthread_join(produce, NULL);
    
    for (int x = 0; x < 10; x++)
    {
        pthread_join(consumers[x], NULL);
    }

    return 0;
}

// sums up 1000 values in [0,1), divides the sum by 500, and returns the sum
double produce()
{
    double sum = 0;
    for (int x = 0; x < 1000; x++)
    {
        sum += uniform();
    }
    sum /= 500;
    
    return sum;
}

// takes in a value and the subtotal of the pthread; adds the value to the total
double consume(double value, double total)
{
    return total += value;
}

// returns a value in [0,1)
double uniform()
{
    return rand()/(double)(RAND_MAX);
}

// takes in a value and adds it to the buffer
void append(double value)
{
    bool insert = false;
    int counter = 0;
    
    // loop through buffer until an empty spot is found (with a value of -1) and store value
    while(insert == false)
    {
        if(buffer[counter] == -1)
        {
            buffer[counter] = value;
            insert = true;
        }
        /*if(counter >= 999)
        {
            return;
        }
        counter++;*/
    }
}

// takes a value out of the buffer and returns it
double take()
{
    bool take = false;
    int counter = 0;
    double value = 0;
    
    while(take == false)
    {
        
        // loop through buffer until a value in the buffer is found (excluding -1) or until
        // the entire buffer has been looped through
        if(buffer[counter] != -1)
        {
            value = buffer[counter];
            buffer[counter] = -1;
            
            return value;
        }
        if(counter >= 999)
        {
            return 0;
        }
        
        counter++;
    }
    
    return 0;
}




