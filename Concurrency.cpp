/*
 * Concurrency.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: raghav
 */




#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"

#define BUFFER_SIZE 64



#if 0
//Adding one item at a time
void IKSolution::producer()
{
    if(itemCount == BUFFER_SIZE)
        sleep();

    lock();
    itemCount += 1;
    unlock();

    if(itemCount == 1)
        wakeup(consumer);

}


int IKSolution::consumer()
{
    if(itemCount == 0)
       sleep();

    lock()
    itemCount -= 1;
    unlock()

    if(itemCount == (BUFFER_size - 1))
        wakeup(producer)

    return item;

}
#endif


int itemCount = 0;
mutex m;
condition_variable cv;

static void producerR();
static int consumerR();

#define ONE_SEC       1000000
#define HUNDRED_MSEC (1000000/10)
#define TEN_MSEC      (HUNDRED_MSEC/10)


void IKSolution::producerConsumerMain()
{
#if 1
    thread th(&producerR);

    thread th1(&consumerR);

    cout << "Sleeping for 5 seconds";
    usleep(TEN_MSEC);
    cout << "Done sleeping for 5 seconds";
#endif
}

void producerR()
{
    while(1)
    {
        unique_lock<mutex> lk(m);
        if(itemCount == BUFFER_SIZE)
        {
            cout << "Producer about to sleep \n";
            cv.wait(lk);
        }
        itemCount += 1;
        cout << "Producer produced one..count  " << itemCount <<" \n";
        //usleep(TEN_MSEC);

        //lk.unlock();
        if(itemCount == 1)
        {
            cout << "Consumer can consume \n";
            cv.notify_one();
        }

        //lk.unlock();
    }
}


int consumerR()
{
    while(1)
    {
        unique_lock<mutex> lk(m);
        if(itemCount == 0)
        {
            cout << "Consumer about to sleep \n";
            cv.wait(lk);
        }

        itemCount -= 1;
        cout << "Consumer consumed one..count  " << itemCount <<" \n";
        //usleep(TEN_MSEC);
        lk.unlock();
        if(itemCount == (BUFFER_SIZE - 1))
        {
            cout << "Producer can produce \n";
            cv.notify_one();
        }

        //lk.unlock();
    }

    return 1;
}
