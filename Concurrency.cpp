/*
 * Concurrency.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: raghav
 */




#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"


#define HUNDRED_MSEC (1000000/10)
#define TEN_MSEC      (HUNDRED_MSEC/10)

#define ONE_SEC       1000000
#define ONE_MINUTE    (ONE_SEC * 60)
#define ONE_HOUR      (ONE_MINUTE * 60)


/*
 * Basic Basic producer consumer..
 * When the producer is full and calls wait(), it gives up the mutex. When the consumer consumes, there is some space and it notifies the
 * producer. The producer, wakes up, get the mutex(locks),
 *
 * Point to note here: I am not holding the lock when notifying why?:
 * 1. The lock is only for waiting part of condition variables
 * 2. If I hold the lock also there is no use. The moment I notify the other entity, it will grab the mutex and come out of waiting state.
 * */

int itemCount = 0;
mutex m;
condition_variable cv;
#define BUFFER_SIZE 64
void producerR()
{
    while(1)
    {
        unique_lock<mutex> lk(m);
        if(itemCount == BUFFER_SIZE)
        {
            cv.wait(lk);
        }
        itemCount += 1;if(itemCount > BUFFER_SIZE) assert(0);
        usleep(TEN_MSEC/10);
        lk.unlock();

        DEBUG_DEBUG(cout << "Producer produced one..count  " << itemCount <<" \n");
        usleep(TEN_MSEC/2);

        if(itemCount == 1)
        {
            cv.notify_one();
        }
    }
}

int consumerR()
{
    while(1)
    {
        unique_lock<mutex> lk(m);
        if(itemCount == 0)
        {
            cv.wait(lk);
        }
        itemCount -= 1; if(itemCount < 0) assert(0);
        usleep(TEN_MSEC/10);
        lk.unlock();

        DEBUG_DEBUG(cout << "Consumer consumed one..count  " << itemCount <<" \n");
        usleep(TEN_MSEC);

        if(itemCount == (BUFFER_SIZE - 1))
        {
            cv.notify_one();
        }

    }

    return 1;
}


void IKSolution::producerConsumerMain()
{

    thread th(producerR);
    thread th1(consumerR);
    usleep(ONE_SEC * 3);
    //th.join();
    //th1.join();
    cout << "Done sleeping for 9 HRS";
}
/***************************************************************************************************************************/

int turn;
bool isItEvenTurn()
{
    return (turn == 0);
}

bool isItOddTurn()
{
    return (turn == 1);
}


void even_run()
{
    for(int i = 0; i <= 100; i += 2)
    {
        unique_lock<mutex> lk(m);
        cv.wait(lk, isItEvenTurn); //repeatedly calls isItEvenTurn until it returns true.
        turn = 1;
        lk.unlock();

        printf("%d,", i);
        cv.notify_one();
    }

    return;
}


void odd_run()
{

    for(int i = 1; i <= 99; i += 2)
    {
        unique_lock<mutex> lk(m);
        cv.wait(lk, isItOddTurn); //repeatedly calls isItOddTurn until it returns true.
        turn = 0;
        lk.unlock();

        printf("%d,", i);
        cv.notify_one();
    }
    return;
}

void IKSolution::oddEvenMain()
{
    turn = 0;
    thread th1(even_run);
    thread th(odd_run);
    usleep(ONE_SEC * 1);
    cout << "\n\n Done sleeping for 1 SECS \n\n";
}


/************************************************************************************************************************************/

class Worker;
class Dispatcher;


class Worker
{

    public:
        void init(int id, int duration, function<void(Worker*, Dispatcher *)> callback, Dispatcher *d);
        void notifyMeWhenAjobIsAvail(int jobNo);
        bool isTheWorkOver(); //predicate
        bool isItMyTurnToWork(); //predicate
        int getId();
        int currJobNo;

    private:

        thread* myTId;
        int id;
        int sleepduration;

        int workerTurn = 1;
        mutex _lock;
        condition_variable _cv;
        function<void(Worker*, Dispatcher *)> cb;
        void myWorkerFunction();
        Dispatcher *disp;

};

class Dispatcher
{
    private:
        queue<Worker *> fWorkers;
        mutex fWorkersQLock; //Worker Queue

        queue<int> pRequests;
        mutex pRequestsQLock; //Requests Queue

    public:
        void DispatcherMain();
        static void notifyMeWhenAjobIscompete(Worker*, Dispatcher *disp);
};


int Worker::getId()
{
    return id;
}

bool Worker::isItMyTurnToWork()
{
    return (workerTurn == 0);
}

bool Worker::isTheWorkOver()
{
    return (workerTurn == 1);
}

void Worker:: myWorkerFunction()
{
    DEBUG_DEBUG(cout << "Worker thread started and waiting \n");
    while(true)
    {
        unique_lock<mutex> lk(_lock);
        _cv.wait(lk, bind(&Worker::isItMyTurnToWork, this)); //keeps waiting until the condition is true
        //DEBUG_DEBUG(cout << "Worker: " << this << " received a job. Working..\n");
        usleep(sleepduration);
        workerTurn = 1;
        lk.unlock();

        _cv.notify_one();
        cb(this, disp);

    }
};


void Worker::notifyMeWhenAjobIsAvail(int jobNo)
{
    unique_lock<mutex> lk(_lock);
    _cv.wait(lk, bind(&Worker::isTheWorkOver, this)); //Have you completed the job given to you earlier?
    currJobNo = jobNo;
    workerTurn = 0;
    lk.unlock();

    _cv.notify_one();

}

void Worker::init(int wid, int duration, function<void(Worker*, Dispatcher *)> callback, Dispatcher *d)
{
    myTId = new thread(&Worker::myWorkerFunction, this); //If you just do thread(myWorkerFunction), then you are not passing in any args to myWorkerFunction.
                                                         //By default the function expects one arg, i.e poiter to the class.
                                                         //http://stackoverflow.com/questions/15434492/c-11-thread-initialization-with-member-functions-compiling-error
    id = wid;
    sleepduration = duration;
    cb = callback;
    disp   = d;
}




void Dispatcher::notifyMeWhenAjobIscompete(Worker *worker, Dispatcher *disp)
{
    DEBUG_TRACE(cout << "Dispatcher: Worker " << worker->getId() << " says he has completed job no " << worker->currJobNo << " \n");

    disp->pRequestsQLock.lock();
    if(!disp->pRequests.empty())
    {
        int jobNo = disp->pRequests.front();
        disp->pRequests.pop();
        worker->notifyMeWhenAjobIsAvail(jobNo);
        disp->pRequestsQLock.unlock(); //Requests Queue
    }
    else
    {
        disp->pRequestsQLock.unlock(); //Requests Queue
        disp->fWorkersQLock.lock();
        disp->fWorkers.push(worker);
        disp->fWorkersQLock.unlock();
    }




}

#define requestGenerationRate (TEN_MSEC * 10 * 100)

void Dispatcher::DispatcherMain()
{
    Worker w1; Worker w2; Worker w3; Worker w4; Worker w5;

    DEBUG_DEBUG(cout << "Dispatcher running \n");
    w1.init(1, ONE_SEC * 1, bind(&notifyMeWhenAjobIscompete, &w1, this), this);
    w2.init(2, ONE_SEC * 2, bind(&notifyMeWhenAjobIscompete, &w2, this), this);
    w3.init(3, ONE_SEC * 3, bind(&notifyMeWhenAjobIscompete, &w3, this), this);
    w4.init(4, ONE_SEC * 4, bind(&notifyMeWhenAjobIscompete, &w4, this), this);
    w5.init(5, ONE_SEC * 5, bind(&notifyMeWhenAjobIscompete, &w5, this), this);

    fWorkers.push(&w1);
    fWorkers.push(&w2);
    fWorkers.push(&w3);
    fWorkers.push(&w4);
    fWorkers.push(&w5);

    int jobNo = 0;
    while(1)
    {
        ++jobNo;
        fWorkersQLock.lock();
        if(!fWorkers.empty())
        {
            Worker *freeWorker = fWorkers.front();
            fWorkers.pop();
            fWorkersQLock.unlock();

            freeWorker->notifyMeWhenAjobIsAvail(jobNo);
        }
        else
        {
            fWorkersQLock.unlock();
            pRequestsQLock.lock();
            pRequests.push(jobNo);
            DEBUG_DEBUG(cout << "All workers are busy!!!!!, queing job " << jobNo << " Request Q size " << pRequests.size() <<  " \n");
            pRequestsQLock.unlock(); //Requests Queue

            usleep(requestGenerationRate);

        }
    }
};


void IKSolution::synchrnousRequestDispatcher()
{

    Dispatcher disp;
    disp.DispatcherMain();
}


#if 0
void initWorkers()
{
    vector<thread> workerThreads(NUMBER_OF_THREADS);

    for(int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        workerThreads[i] = thread(myWorkerFunction, i);
    }

}
#endif


/***************************************************************************************************************************/
